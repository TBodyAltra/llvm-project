//===--- TINYGPU.h - Declare TINYGPU target feature support -------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares TINYGPU TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_TINYGPU_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_TINYGPU_H

#include "clang/Basic/TargetID.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/ADT/StringSet.h"
#include "llvm/Support/Compiler.h"
#include "llvm/TargetParser/TargetParser.h"
#include "llvm/TargetParser/Triple.h"
#include <optional>

namespace clang {
namespace targets {

class LLVM_LIBRARY_VISIBILITY TINYGPUTargetInfo final : public TargetInfo {

public:
  TINYGPUTargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts);

};

} // namespace targets
} // namespace clang

namespace TINYGPUAS {
enum : unsigned {
  FLAT_ADDRESS = 0,
  GLOBAL_ADDRESS = 1,
};
} // namespace TINYGPUAS

#endif // LLVM_CLANG_LIB_BASIC_TARGETS_TINYGPU_H