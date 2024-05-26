//===-- TINYGPUAsmBackend.cpp - TINYGPU Assembler Backend --------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===------------------------------------------------------------------------===//

#include "MCTargetDesc/TINYGPUMCTargetDesc.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCDirectives.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCFixupKindInfo.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace{
class TINYGPUAsmBackend : public MCAsmBackend {
  uint8_t OSABI;
  bool Is64Bit;

public:
  TINYGPUAsmBackend(uint8_t OSABI, bool Is64Bit)
      : MCAsmBackend(support::endianness::little), OSABI(OSABI), Is64Bit(Is64Bit) {}
  ~TINYGPUAsmBackend() override {}

  void applyFixup(const MCAssembler &Asm, const MCFixup &Fixup,
                  const MCValue &Target, MutableArrayRef<char> Data,
                  uint64_t value, bool IsResolved, const MCSubtargetInfo *STI) const override;

  std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override;

  bool fixupNeedsRelaxation(const MCFixup &Fixup, uint64_t Value,
                            const MCRelaxableFragment *DF,
                            const MCAsmLayout &Layout) const override {
      return false;
  }

  unsigned getNumFixupKinds() const override { return 1; }

  bool mayNeedRelaxation(const MCInst &Inst, const MCSubtargetInfo &STI) const override { return false; }

  void relaxInstruction(MCInst &Inst, const MCSubtargetInfo &STI) const override {
    report_fatal_error("TINGPUAsmBackend::relaxInstruction() unimplemented");
  }

  bool writeNopData(raw_ostream &OS, uint64_t Count, const MCSubtargetInfo *STI) const override;
};

bool TINYGPUAsmBackend::writeNopData(raw_ostream &OS, uint64_t Count, const MCSubtargetInfo *STI) const {
  // TODO: what does this do?
  report_fatal_error("TINYGPUAsmBackend::writeNopData() unimplemented.");
}

void TINYGPUAsmBackend::applyFixup(const MCAssembler &Asm, const MCFixup &Fixup,
                const MCValue &Target, MutableArrayRef<char> Data,
                uint64_t value, bool IsResolved, const MCSubtargetInfo *STI) const {
  return;
}

std::unique_ptr<MCObjectTargetWriter>
TINYGPUAsmBackend::createObjectTargetWriter() const {
  return createTINYGPUELFObjectWriter(OSABI, Is64Bit);
}

} // end anonymous namespace

MCAsmBackend *llvm::createTINYGPUAsmBackend(const Target &T,
                                            const MCSubtargetInfo &STI,
                                            const MCRegisterInfo &MRI,
                                            const MCTargetOptions &Options) {
  const Triple &TT = STI.getTargetTriple();
  uint8_t OSABI = MCELFObjectTargetWriter::getOSABI(TT.getOS());
  return new TINYGPUAsmBackend(OSABI, TT.isArch64Bit());
}

