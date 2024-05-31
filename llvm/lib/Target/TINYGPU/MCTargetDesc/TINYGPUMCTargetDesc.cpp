//===-- TINYGPUTargetDesc.cpp - TINYGPU Target Descriptions --------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------------------===//
//
// This file provides TINYGPU specific target descriptions.
//
//===----------------------------------------------------------------------------------===//

#include "TINYGPUMCTargetDesc.h"
#include "InstPrinter/TINYGPUInstPrinter.h"
#include "TINYGPUMCAsmInfo.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_INSTRINFO_MC_DESC
#include "TINYGPUGenInstrInfo.inc"

#define GET_REGINFO_MC_DESC
#include "TINYGPUGenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createTINYGPUMCInstrInfo() {
    MCInstrInfo *X = new MCInstrInfo();
    InitTINYGPUMCInstrInfo(X);
    return X;
}

static MCRegisterInfo *createTINYGPUMCRegisterInfo(const Triple &TT) {
    MCRegisterInfo *X = new MCRegisterInfo();
    // FIXME: R1 is not return address register
    InitTINYGPUMCRegisterInfo(X, TINYGPU::R1);
    return X;
}

static MCAsmInfo *createTINYGPUMCAsmInfo(const MCRegisterInfo &MRI,
                                         const Triple &TT,
                                         const MCTargetOptions &Options) {
    return new TINYGPUMCAsmInfo(TT);
}

static MCInstPrinter *createTINYGPUMCInstPrinter(const Triple &T,
                                                 unsigned SyntaxVariant,
                                                 const MCAsmInfo &MAI,
                                                 const MCInstrInfo &MII,
                                                 const MCRegisterInfo &MRI) {
    return new TINYGPUInstPrinter(MAI, MII, MRI);
}

#define GET_SUBTARGETINFO_MC_DESC
#include "TINYGPUGenSubtargetInfo.inc"

static MCSubtargetInfo *createTINYGPUMCSubtargetInfo(const Triple &TT,
                                                     StringRef CPU, StringRef FS) {
    if (CPU.empty() || CPU == "naive")
        CPU = "tinygpu-naive";
    return createTINYGPUMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/CPU, FS);
}

extern "C" void LLVMInitializeTINYGPUTargetMC() {
    Target *T = &getTheTINYGPUTarget();
    TargetRegistry::RegisterMCAsmInfo(*T, createTINYGPUMCAsmInfo);
    TargetRegistry::RegisterMCInstrInfo(*T, createTINYGPUMCInstrInfo);
    TargetRegistry::RegisterMCRegInfo(*T, createTINYGPUMCRegisterInfo);
    TargetRegistry::RegisterMCAsmBackend(*T, createTINYGPUAsmBackend);
    TargetRegistry::RegisterMCCodeEmitter(*T, createTINYGPUMCCodeEmitter);
    TargetRegistry::RegisterMCInstPrinter(*T, createTINYGPUMCInstPrinter);
    TargetRegistry::RegisterMCSubtargetInfo(*T, createTINYGPUMCSubtargetInfo);
}