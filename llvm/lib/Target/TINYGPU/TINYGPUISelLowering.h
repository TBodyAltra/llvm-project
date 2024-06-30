//===-- TINYGPUISelLowering.h - TINYGPU DAG Lowering Interface ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that TINYGPU uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_TINYGPU_TINYGPUISELLOWERING_H
#define LLVM_LIB_TARGET_TINYGPU_TINYGPUISELLOWERING_H

#include "TINYGPU.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {
class TINYGPUSubtarget;
namespace TINYGPUISD {
enum NodeType : unsigned {
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  END_PGM
};
} // namespace TINYGPUISD

class TINYGPUTargetLowering : public TargetLowering {
  const TINYGPUSubtarget &Subtarget;

public:
  explicit TINYGPUTargetLowering(const TargetMachine &TM,
                                 const TINYGPUSubtarget &STI);

  // Provide custom lowering hooks for some operations.
  SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const override;

  // This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  /// Return true if integer divide is usually cheaper than a sequence of
  /// several shifts, adds, and multiplies for this target.
  /// The definition of "cheaper" may depend on whether we're optimizing
  /// for speed or for size.
  /// For TINYGPU, does not support mulhs op and shift op, for now
  /// So always keep the div op for TINYGPU
  bool isIntDivCheap(EVT VT, AttributeList Attr) const override { return true; }

  SDValue LowerINTRINSIC_WO_CHAIN(SDValue Op, SelectionDAG &DAG) const;

  SDValue lowerWorkitemID(SelectionDAG &DAG, SDValue Op) const;

private:
  // Lower incoming arguments, copy physregs into vregs
  SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
                               bool IsVarArg,
                               const SmallVectorImpl<ISD::InputArg> &Ins,
                               const SDLoc &DL, SelectionDAG &DAG,
                               SmallVectorImpl<SDValue> &InVals) const override;
  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      const SmallVectorImpl<SDValue> &OutVals, const SDLoc &DL,
                      SelectionDAG &DAG) const override;
  bool shouldConvertConstantLoadToIntImm(const APInt &Imm,
                                         Type *Ty) const override {
    return true;
  }
};
}

#endif