//===-- TINYGPU.h - Top-level interface for TINYGPU -----------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in the LLVM
// TINYGPU back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_TINYGPU_TINYGPU_H
#define LLVM_LIB_TARGET_TINYGPU_TINYGPU_H

#include "MCTargetDesc/TINYGPUMCTargetDesc.h"
#include "llvm/Pass.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class TINYGPUTargetMachine;
class MCInst;
class MachineInstr;

void LowerTINYGPUMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI);

FunctionPass *createTINYGPUISelDag(TINYGPUTargetMachine &TM);
}

#endif