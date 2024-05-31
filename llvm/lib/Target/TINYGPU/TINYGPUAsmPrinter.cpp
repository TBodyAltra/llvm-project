//===-- TINYGPUAsmPrinter.cpp - TINYGPU LLVM assembly writer ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to the TINYGPU assembly language.
//
//===----------------------------------------------------------------------===//

#include "TINYGPU.h"
#include "InstPrinter/TINYGPUInstPrinter.h"
#include "TINYGPUTargetMachine.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {
class TINYGPUAsmPrinter : public AsmPrinter {
public:
  explicit TINYGPUAsmPrinter(TargetMachine &TM,
                             std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)) {}

  StringRef getPassName() const override { return "TINYGPU Assembly Printer"; }

  void emitInstruction(const MachineInstr *MI) override;

  bool emitPseudoExpansionLowering(MCStreamer &OutStreamer,
                                   const MachineInstr *MI);
};
}

// Simple pseudo-instructions have their lowering (with expansion to real
// instructions) auto-generated.
// #include "TINYGPUGenMCPseudoLowering.inc"

void TINYGPUAsmPrinter::emitInstruction(const MachineInstr *MI) {
  // Do any auto-generated pseudo lowerings.
  //if (emitPseudoExpansionLowering(*OutStreamer, MI))
  //  return;

  MCInst TmpInst;
  LowerTINYGPUMachineInstrToMCInst(MI, TmpInst);
  EmitToStreamer(*OutStreamer, TmpInst);
}

// Force static initialization.
extern "C" void LLVMInitializeTINYGPUAsmPrinter() {
  RegisterAsmPrinter<TINYGPUAsmPrinter> X(getTheTINYGPUTarget());
}