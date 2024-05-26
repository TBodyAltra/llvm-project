//===-- TINYGPUMCTargetDesc.h - TINYGPU Target Descriptions --------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides TINYGPU specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_TINYGPU_MCTARGETDESC_TINYGPUMCTARGETDESC_H
#define LLVM_LIB_TARGET_TINYGPU_MCTARGETDESC_TINYGPUMCTARGETDESC_H

#include "llvm/Config/config.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/DataTypes.h"
#include <memory>

namespace llvm {
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class StringRef;
class Target;
class Triple;
class raw_ostream;
class raw_pwrite_stream;

Target &getTheTINYGPUTarget();

MCCodeEmitter *createTINYGPUMCCodeEmitter(const MCInstrInfo &MCII,
                                          MCContext &Ctx);

MCAsmBackend *createTINYGPUAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                        const MCRegisterInfo &MRI,
                                        const MCTargetOptions &Options);

std::unique_ptr<MCObjectTargetWriter>
createTINYGPUELFObjectWriter(uint8_t OSABI, bool Is64Bit);

} // namespace llvm

// Define symbolic names for TINYGPU registers
#define GET_REGINFO_ENUM
#include "TINYGPUGenRegisterInfo.inc"

// Define symbolic names for TINYGPU instructions
#define GET_INSTRINFO_ENUM
#include "TINYGPUGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_TINYGPU_MCTARGETDESC_TINYGPUMCTARGETDESC_H
