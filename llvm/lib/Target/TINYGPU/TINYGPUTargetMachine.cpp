//===-- TINYGPUTargetMachine.cpp - Define TargetMachine for TINYGPU ----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===-------------------------------------------------------------------------===//
//
// Implements the info about TINYGPU target spec.
//
//===-------------------------------------------------------------------------===//

#include "TINYGPUTargetMachine.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/IR/LegacyPassManager.h"
#include <optional>
using namespace llvm;

extern "C" void LLVMInitializeTINYGPUTarget() {
  RegisterTargetMachine<TINYGPUTargetMachine> X(getTheTINYGPUTarget());
}

static std::string computeDataLayout(const Triple &TT) {
  return "e-m:e-p:32:32-p1:8:8-i8:8-i16:16-n8:8";
}

static Reloc::Model getEffectiveRelocModel(const Triple &TT,
                                           std::optional<Reloc::Model> RM) {
  return RM.value_or(Reloc::Static);
}

TINYGPUTargetMachine::TINYGPUTargetMachine(const Target &T, const Triple &TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       std::optional<Reloc::Model> RM,
                                       std::optional<CodeModel::Model> CM,
                                       CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T, computeDataLayout(TT), TT, CPU, FS, Options,
                        getEffectiveRelocModel(TT, RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, CPU, FS, *this) {
  initAsmInfo();
}

namespace {
class TINYGPUPassConfig : public TargetPassConfig {
public:
  TINYGPUPassConfig(TINYGPUTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  TINYGPUTargetMachine &getTINYGPUTargetMachine() const {
    return getTM<TINYGPUTargetMachine>();
  }

  bool addInstSelector() override;
};
}

TargetPassConfig *TINYGPUTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new TINYGPUPassConfig(*this, PM);
}

bool TINYGPUPassConfig::addInstSelector() {
  addPass(createTINYGPUISelDag(getTINYGPUTargetMachine()));

  return false;
}
