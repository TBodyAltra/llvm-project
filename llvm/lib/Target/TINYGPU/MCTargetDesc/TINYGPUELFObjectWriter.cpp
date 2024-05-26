//===-- TINYGPUELFObjectWriter.cpp - TINYGPU ELF Writer --------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/TINYGPUMCTargetDesc.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCFixup.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class TINYGPUELFObjectWriter : public MCELFObjectTargetWriter {
public:
  TINYGPUELFObjectWriter(uint8_t OSABI, bool Is64Bit);
  ~TINYGPUELFObjectWriter() override;
protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool ISPCRel) const override;
};
}

TINYGPUELFObjectWriter::TINYGPUELFObjectWriter(uint8_t OSABI, bool Is64Bit)
    : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_TINYGPU,
                              /*HasRelocationAddend*/ true) {}

TINYGPUELFObjectWriter::~TINYGPUELFObjectWriter() {}

unsigned TINYGPUELFObjectWriter::getRelocType(MCContext &Ctx,
                                              const MCValue &Target,
                                              const MCFixup &FixUp,
                                              bool IsPCRel) const {
  report_fatal_error("invalid fixup kind!");
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createTINYGPUELFObjectWriter(uint8_t OSABI, bool Is64Bit) {
    return std::make_unique<TINYGPUELFObjectWriter>(OSABI, Is64Bit);
}
