//===--- TINYGPU.cpp - Implement TINYGPU target feature support -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements TINYGPU TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "TINYGPU.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/CodeGenOptions.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"
using namespace clang;
using namespace clang::targets;

namespace clang {
namespace targets {

static constexpr Builtin::Info BuiltinInfo[] = {
#define BUILTIN(ID, TYPE, ATTRS)                                               \
  {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
#define TARGET_BUILTIN(ID, TYPE, ATTRS, FEATURE)                               \
  {#ID, TYPE, ATTRS, FEATURE, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
#include "clang/Basic/BuiltinsTINYGPU.def"
};

TINYGPUTargetInfo::TINYGPUTargetInfo(const llvm::Triple &Triple,
                                   const TargetOptions &Opts)
    : TargetInfo(Triple) {
}

} // namesapce targets
} // namespace clang
