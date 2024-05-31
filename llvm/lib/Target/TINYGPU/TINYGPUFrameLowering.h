//===-- TINYGPUFrameLowering.h - Define frame lowering for TINYGPU -*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class implements TINYGPU-specific bits of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_TINYGPU_TINYGPUFRAMELOWERING_H
#define LLVM_LIB_TARGET_TINYGPU_TINYGPUFRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class TINYGPUSubtarget;

class TINYGPUFrameLowering : public TargetFrameLowering {
public:
    // TODO: How to determine the StackAlignment?
    explicit TINYGPUFrameLowering(const TINYGPUSubtarget &STI)
        : TargetFrameLowering(StackGrowsDown, /*StackAlignment=*/Align(8), /*LocalAreaOffset=*/0) {}

    void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
    void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;

    bool hasFP(const MachineFunction &MF) const override;
};
}
#endif