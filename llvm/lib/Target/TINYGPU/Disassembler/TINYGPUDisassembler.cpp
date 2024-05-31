//===-- TINYGPUDisassembler.cpp - Disassembler for TINYGPU --------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the TINYGPUDisassembler class.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/TINYGPUMCTargetDesc.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/MC/MCDecoderOps.h"
#include "llvm/Support/Endian.h"

using namespace llvm;

#define DEBUG_TYPE "tinygpu-disassembler"

typedef MCDisassembler::DecodeStatus DecodeStatus;

namespace {
class TINYGPUDisassembler : public MCDisassembler {
public:
    TINYGPUDisassembler(const MCSubtargetInfo &STI, MCContext &Ctx)
        : MCDisassembler(STI, Ctx) {}

    DecodeStatus getInstruction(MCInst &Instr, uint64_t &Size,
                                ArrayRef<uint8_t> Bytes, uint64_t Address,
                                raw_ostream &CStream) const override;
};
} // end of anonymous namespace

static DecodeStatus DecodeGPRRegisterClass(MCInst &Inst, uint32_t RegNo,
                                           uint64_t Address,
                                           const MCDisassembler *Decoder) {
  if (RegNo >= 16)
    return MCDisassembler::Fail;

  MCRegister Reg = TINYGPU::R0 + RegNo;
  Inst.addOperand(MCOperand::createReg(Reg));
  return MCDisassembler::Success;
}

#include "TINYGPUGenDisassemblerTables.inc"

DecodeStatus TINYGPUDisassembler::getInstruction(MCInst &MI, uint64_t &Size,
                                                 ArrayRef<uint8_t> Bytes, uint64_t Address,
                                                 raw_ostream &CStream) const {
    Size = 2;
    if (Bytes.size() < 2) {
        Size = 0;
        return MCDisassembler::Fail;
    }

    // Get the two bytes of the instruction
    uint16_t Inst = support::endian::read16le(Bytes.data());

    return decodeInstruction(DecoderTable16, MI, Inst, Address, this, STI);
}

static MCDisassembler *createTINYGPUDisassembler(const Target &T,
                                                 const MCSubtargetInfo &STI,
                                                 MCContext &Ctx) {
    return new TINYGPUDisassembler(STI, Ctx);
}

extern "C" void LLVMInitializeTINYGPUDisassembler() {
    TargetRegistry::RegisterMCDisassembler(getTheTINYGPUTarget(), createTINYGPUDisassembler);
}
