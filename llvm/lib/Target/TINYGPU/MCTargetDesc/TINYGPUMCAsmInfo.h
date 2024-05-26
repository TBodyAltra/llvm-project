//===-- TINYGPUMCAsmInfo.h - TINYGPU Asm Info ----------------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the TINYGPUMCAsmInfo class
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_TINYGPU_MCTARGETDESC_TINYGPUMCASMINFO_H
#define LLVM_LIB_TARGET_TINYGPU_MCTARGETDESC_TINYGPUMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
class Triple;

class TINYGPUMCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit TINYGPUMCAsmInfo(const Triple &TargetTriple);
};
} // namespace llvm

#endif // LLVM_LIB_TARGET_TINYGPU_MCTARGETDESC_TINYGPUMCASMINFO_H
