//===-- TINYGPUFrameLowering.cpp - TINYGPU Frame Information ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the TINYGPU implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#include "TINYGPUFrameLowering.h"
#include "TINYGPUSubtarget.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

using namespace llvm;

bool TINYGPUFrameLowering::hasFP(const MachineFunction &MF) const { return  true; }

void TINYGPUFrameLowering::emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const {}

void TINYGPUFrameLowering::emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const {}