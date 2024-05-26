//===-- TINYGPUInstrInfo.td - TINYGPU Instruction Description ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===--------------------------------------------------------------------------===//
// This file describes the TIGPU Instrucions in the TableGen Format
//===--------------------------------------------------------------------------===//

include "TINYGPUInstrFormats.td"

//===--------------------------------------------------------------------------===//
// Operand and SDNode transformation definitions
//===--------------------------------------------------------------------------===//

def uimm8 : Operand<i16>;

//===--------------------------------------------------------------------------===//
// Instruction Class Templates
//===--------------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class ALU_B<TINYGPUOpCode opcode, string opcodestr>: 
    TGInstB<opcode, (outs GPR:$rd), (ins GPR:$rs, GPR:$rt), opcodestr, "$rd, $rs, $rt">;

//===--------------------------------------------------------------------------===//
// Instructions
//===--------------------------------------------------------------------------===//

def NOP   : TGInstR<OPC_NOP, (outs), (ins), "NOP", "">;
def BRnzp : TGInstBr<OPC_BR_NZP, (outs), (ins GPR:$nzp, uimm8:$imm8), "BRnzp", "$imm8">;
def CMP   : TGInstC<OPC_CMP, (outs), (ins GPR:$rs, GPR:$rt), "CMP", "$rs, $rt">;
def ADD   : ALU_B<OPC_ADD, "ADD">;
def SUB   : ALU_B<OPC_SUB, "SUB">;
def MUL   : ALU_B<OPC_MUL, "MUL">;
def DIV   : ALU_B<OPC_DIV, "DIV">;
def LDR   : TGInstU<OPC_LDR, (outs GPR:$rd), (ins GPR:$rs), "LDR", "$rd, %rs">;
def STR   : TGInstC<OPC_STR, (outs), (ins GPR:$rs, GPR:$rt), "STR", "$rs, $rt">;
def CONST : TGInstCon<OPC_CONST, (outs GPR:$rd), (ins uimm8:$imm8), "CONST", "$rd, $imm8">;
def RET   : TGInstR<OPC_RET, (outs), (ins), "RET", "">;
