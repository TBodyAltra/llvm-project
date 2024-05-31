//===-- TINYGPUCallingConv.td - Calling Conventions TINYGPU ----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This describes the calling conventions for the TINYGPU architecture.
//
//===----------------------------------------------------------------------===//

// TINYGPU 8-bit C return-value convention.
def RetCC_TINYGPU8 : CallingConv<[CCIfType<[i8], CCAssignToReg<[R11, R12]>>]>;

// TINYGPU 8-bit C Calling convention.
def CC_TINYGPU8 : CallingConv<[

  // All arguments get passed in integer registers if there is space.
  CCIfType<[i8], CCAssignToReg<[ R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12]>>,

  // Could be assigned to the stack in 8-byte aligned units, but unsupported
  CCAssignToStack<8, 8>
]>;

// FIXME: how to determine this for TINYGPU?
def CSR : CalleeSavedRegs<(add R1, R2, R3)>;