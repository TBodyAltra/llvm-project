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
// Register File, instruction descriptions
//===--------------------------------------------------------------------------===//

include "TINYGPURegisterInfo.td"
include "TINYGPUInstrInfo.td"

def TINYGPUInstrInfo : InstrInfo;

//===--------------------------------------------------------------------------===//
// TINYGPU processors supported
//===--------------------------------------------------------------------------===//

def : ProcessorModel<"tg0", NoSchedModel, []>;

//===--------------------------------------------------------------------------===//
// Define the TINYGPU target
//===--------------------------------------------------------------------------===//

def TINYGPU : Target {
  let InstructionSet = TINYGPUInstrInfo;
}
