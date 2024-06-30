//===-- TINYGPURegisterInfo.cpp - TINYGPU Register Information ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the TINYGPU implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "TINYGPURegisterInfo.h"
#include "TINYGPU.h"
#include "TINYGPUSubtarget.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/RegisterScavenging.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_REGINFO_TARGET_DESC
#include "TINYGPUGenRegisterInfo.inc"

using namespace llvm;

TINYGPURegisterInfo::TINYGPURegisterInfo(unsigned HwMode)
    : TINYGPUGenRegisterInfo(TINYGPU::R1, /*DwarfFlavour*/0, /*EHFlavor*/0,
                           /*PC*/0, HwMode) {}

const MCPhysReg *
TINYGPURegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return CSR_SaveList;
}

BitVector TINYGPURegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  reserveRegisterTuples(Reserved, TINYGPU::R13); // blockIdx
  reserveRegisterTuples(Reserved, TINYGPU::R14); // blockDim
  reserveRegisterTuples(Reserved, TINYGPU::R15); // threadIdx
  return Reserved;
}

void TINYGPURegisterInfo::reserveRegisterTuples(BitVector &Reserved, unsigned Reg) const {
  MCRegAliasIterator R(Reg, this, true);

  for (; R.isValid(); ++R)
    Reserved.set(*R);
}


bool TINYGPURegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                            int SPAdj, unsigned FIOperandNum,
                                            RegScavenger *RS) const {
  report_fatal_error("Subroutines not supported yet");
  return false;
}

Register TINYGPURegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return TINYGPU::R0;
}