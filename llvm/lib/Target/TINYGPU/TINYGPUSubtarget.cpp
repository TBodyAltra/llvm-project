//===-- TINYGPUSubtarget.cpp - TINYGPU Subtarget Information ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the TINYGPU specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "TINYGPUSubtarget.h"
#include "TINYGPU.h"
#include "TINYGPUFrameLowering.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "tinygpu-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "TINYGPUGenSubtargetInfo.inc"

void TINYGPUSubtarget::anchor() {}

TINYGPUSubtarget &TINYGPUSubtarget::initializeSubtargetDependencies(StringRef CPU,
                                                                StringRef FS,
                                                                bool Is64Bit) {
  // Determine default and user-specified characteristics
  StringRef CPUName = CPU;
  if (CPUName.empty())
    CPUName = "tinygpu-naive";
  ParseSubtargetFeatures(CPUName, CPUName, FS);
  return *this;
}

TINYGPUSubtarget::TINYGPUSubtarget(const Triple &TT, const StringRef CPU,
                                   const StringRef FS, const TargetMachine &TM)
    : TINYGPUGenSubtargetInfo(TT, CPU, CPU, FS),
      FrameLowering(initializeSubtargetDependencies(CPU, FS, TT.isArch64Bit())),
      InstrInfo(), RegInfo(getHwMode()), TLInfo(TM, *this) {}