//===-- TINYGPUMCAsmInfo.cpp - TINYGPU Asm Properties -----------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the TINYGPUMCAsmInfo properties
//
//===----------------------------------------------------------------------===//

#include "TINYGPUMCAsmInfo.h"
#include "llvm/TargetParser/Triple.h"
using namespace llvm;

void TINYGPUMCAsmInfo::anchor() {}

TINYGPUMCAsmInfo::TINYGPUMCAsmInfo(const Triple &TT) {
  CodePointerSize = CalleeSaveStackSlotSize = 2;
}
