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

//===----------------------------------------------------------------------===//
// TINYGPU specific DAG Nodes.
//===----------------------------------------------------------------------===//

def TINYGPUendpgm: SDNode<"TINYGPUISD::END_PGM", SDTNone,
                     [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===--------------------------------------------------------------------------===//
// Operand and SDNode transformation definitions
//===--------------------------------------------------------------------------===//

class ImmAsmOperand<int width> : AsmOperandClass {
    let Name = "Imm" # width;
    let RenderMethod = "addImmOperands";
    let DiagnosticType = !strconcat("Invalid", Name);
}

def imm8 : Operand<i8> {
    let ParserMatchClass = ImmAsmOperand<8>;
}

//===--------------------------------------------------------------------------===//
// Instruction Class Templates
//===--------------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class ALU_B<TINYGPUOpCode opcode, string opcodestr>: 
    TGInstB<opcode, (outs GPR:$rd), (ins GPR:$rs, GPR:$rt), opcodestr, "$rd, $rs, $rt">;

//===--------------------------------------------------------------------------===//
// Instructions
//===--------------------------------------------------------------------------===//
def ADD   : ALU_B<OPC_ADD, "ADD">;
def SUB   : ALU_B<OPC_SUB, "SUB">;
def MUL   : ALU_B<OPC_MUL, "MUL">;
def DIV   : ALU_B<OPC_DIV, "DIV">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in {
def NOP   : TGInstR<OPC_NOP, (outs), (ins), "NOP", "">;
def BRnzp : TGInstBr<OPC_BR_NZP, (outs), (ins GPR:$nzp, imm8:$imm8), "BRnzp", "$imm8">;
def CMP   : TGInstC<OPC_CMP, (outs), (ins GPR:$rs, GPR:$rt), "CMP", "$rs, $rt">;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isMoveImm = 1 in {
def CONST : TGInstCon<OPC_CONST, (outs GPR:$rd), (ins imm8:$imm8), "CONST", "$rd, $imm8">;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isReturn = 1, isTerminator = 1 in {
def RET   : TGInstR<OPC_RET, (outs), (ins), "RET", "">;
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
def LDR   : TGInstU<OPC_LDR, (outs GPR:$rd), (ins GPR:$rs), "LDR", "$rd, $rs">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
def STR   : TGInstC<OPC_STR, (outs), (ins GPR:$rs, GPR:$rt), "STR", "$rs, $rt">;

//===----------------------------------------------------------------------===//
// DAG selection patterns
//===----------------------------------------------------------------------===//
def DAG_RET: Pat<(TINYGPUendpgm), (RET)>;
def DAG_ADDi: Pat<(add GPR:$rs, imm:$imm), (ADD $rs, (CONST $imm))>;
//def DAG_ADD: Pat<(add GPR:$rs, GPR:$rt), (ADD $rs, $rt)>;
//def DAG_CONST: Pat<(imm:$imm), (CONST $imm)>;