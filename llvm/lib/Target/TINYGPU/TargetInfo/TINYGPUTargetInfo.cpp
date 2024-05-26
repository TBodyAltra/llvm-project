//===-- TINYGPUTargetInfo.cpp - TINYGPU Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

namespace llvm {
Target &getTheTINYGPUTarget() {
  static Target TheTINYGPUTarget;
  return TheTINYGPUTarget;
}
} // namespace llvm

extern "C" void LLVMInitializeTINYGPUTargetInfo() {
  RegisterTarget<Triple::tinygpu> X(getTheTINYGPUTarget(), "tinygpu", "demo tinygpu", "TINYGPU");
}

// FIXME: Temporary stub - this function must be defined for linking
// to succeed and will be called unconditionally by llc, so must be a no-op.
// Remove once this function is properly implemented.
extern "C" void LLVMInitializeTINYGPUTargetMC() {}
