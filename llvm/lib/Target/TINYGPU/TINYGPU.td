//===-- TINYGPU.td - Describe the TINYGPU Target Machine -------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===--------------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===--------------------------------------------------------------------------===//
// TINYGPU subtarget features and instruction predicates.
//===--------------------------------------------------------------------------===//


//===--------------------------------------------------------------------------===//
// Register File, instruction descriptions, calling conventions
//===--------------------------------------------------------------------------===//

include "TINYGPURegisterInfo.td"
include "TINYGPUInstrInfo.td"
include "TINYGPUCallingConv.td"

//===--------------------------------------------------------------------------===//
// TINYGPU processors supported
//===--------------------------------------------------------------------------===//

def : ProcessorModel<"tinygpu-naive", NoSchedModel, []>;

//===--------------------------------------------------------------------------===//
// Define the TINYGPU target
//===--------------------------------------------------------------------------===//

def TINYGPUInstrInfo : InstrInfo {
  let guessInstructionProperties = 0;
}

def TINYGPUAsmParser : AsmParser {
    let ShouldEmitMatchRegisterAltName = 1;
}

def TINYGPU : Target {
  let InstructionSet = TINYGPUInstrInfo;
  let AssemblyParsers = [TINYGPUAsmParser];
}
