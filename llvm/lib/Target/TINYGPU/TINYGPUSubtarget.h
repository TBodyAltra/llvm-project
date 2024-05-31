//===-- TINYGPUSubtarget.h - Define Subtarget for the TINYGPU -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the TINYGPU specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_TINYGPU_TINYGPUSUBTARGET_H
#define LLVM_LIB_TARGET_TINYGPU_TINYGPUSUBTARGET_H

#include "TINYGPUFrameLowering.h"
#include "TINYGPUISelLowering.h"
#include "TINYGPUInstrInfo.h"
#include "llvm/CodeGen/SelectionDAGTargetInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"

#define GET_SUBTARGETINFO_HEADER
#include "TINYGPUGenSubtargetInfo.inc"

namespace llvm {
class StringRef;

class TINYGPUSubtarget : public TINYGPUGenSubtargetInfo {
    virtual void anchor();
    TINYGPUFrameLowering FrameLowering;
    TINYGPUInstrInfo InstrInfo;
    TINYGPURegisterInfo RegInfo;
    TINYGPUTargetLowering TLInfo;
    SelectionDAGTargetInfo TSInfo;

    TINYGPUSubtarget &initializeSubtargetDependencies(StringRef CPU, StringRef FS, bool Is64Bit);

public:
    TINYGPUSubtarget(const Triple &TT, const StringRef CPU,
                     const StringRef FS, const TargetMachine &TM);

    void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS);

    const TINYGPUFrameLowering *getFrameLowering() const override { return &FrameLowering; }
    const TINYGPUInstrInfo *getInstrInfo() const override { return &InstrInfo; }
    const TINYGPURegisterInfo *getRegisterInfo() const override { return &RegInfo; }
    const TINYGPUTargetLowering *getTargetLowering() const override { return &TLInfo; }
    const SelectionDAGTargetInfo *getSelectionDAGInfo() const override { return &TSInfo; }
    bool is64Bit() const { return false; }
};
} // namespace llvm

#endif // LLVM_LIB_TARGET_TINYGPU_TINYGPUSUBTARGET_H