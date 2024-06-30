//===- IntrinsicsTINYGPU.td - Defines TINYGPU intrinsics -----*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines all of the TINYGPU intrinsics.
//
//===----------------------------------------------------------------------===//

class TINYGPUReadPreloadRegisterIntrinsicNamed<string name>
  : DefaultAttrsIntrinsic<[llvm_i8_ty], [], [IntrNoMem, IntrSpeculatable]>, ClangBuiltin<name>;

let TargetPrefix = "tinygpu" in {
def int_tinygpu_workitem_id_x : TINYGPUReadPreloadRegisterIntrinsicNamed<"__builtin_tinygpu_workitem_id_x">;
def int_tinygpu_workgroup_id_x : TINYGPUReadPreloadRegisterIntrinsicNamed<"__builtin_tinygpu_workgroup_id_x">;
def int_tinygpu_workgroup_size_x : TINYGPUReadPreloadRegisterIntrinsicNamed<"__builtin_tinygpu_workgroup_size_x">;
}