//===-- TINYGPUInstrInfo.h - TINYGPU Instruction Information --------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the TINYGPU implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_TINYGPU_TINYGPUINSTRINFO_H
#define LLVM_LIB_TARGET_TINYGPU_TINYGPUINSTRINFO_H

#include "TINYGPURegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "TINYGPUGenInstrInfo.inc"

namespace llvm {

class TINYGPUInstrInfo : public TINYGPUGenInstrInfo {

public:
  TINYGPUInstrInfo();
};
}

#endif