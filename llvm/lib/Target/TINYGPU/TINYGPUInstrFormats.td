//===-- TINYGPUInstrFormats.td - TINYGPU Instruction Formats ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===--------------------------------------------------------------------------===//

class TINYGPUOpCode<bits<4> val> {
  bits<4> Value = val;
}
def OPC_NOP    : TINYGPUOpCode<0b0000>;
def OPC_BR_NZP : TINYGPUOpCode<0b0001>;
def OPC_CMP    : TINYGPUOpCode<0b0010>;
def OPC_ADD    : TINYGPUOpCode<0b0011>;
def OPC_SUB    : TINYGPUOpCode<0b0100>;
def OPC_MUL    : TINYGPUOpCode<0b0101>;
def OPC_DIV    : TINYGPUOpCode<0b0110>;
def OPC_LDR    : TINYGPUOpCode<0b0111>;
def OPC_STR    : TINYGPUOpCode<0b1000>;
def OPC_CONST  : TINYGPUOpCode<0b1001>;
def OPC_RET    : TINYGPUOpCode<0b1111>;

class TGInst<dag outs, dag ins, string opcodestr, string argstr,
             list<dag> pattern>
    : Instruction {
  field bits<32> Inst;
  let Size = 2;

  bits<4> Opcode = 0;
  let Inst{15-12} = Opcode;

  let Namespace = "TINYGPU";

  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = opcodestr # "\t" # argstr;
  let Pattern = pattern;
}

// Pseudo instructions
class Pseudo<dag outs, dag ins, list<dag> pattern>
    : TGInst<outs, ins, "", "", pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}

// Unary Inst
class TGInstU<TINYGPUOpCode opcode, dag outs, dag ins, string opcodestr, string argstr>
    : TGInst<outs, ins, opcodestr, argstr, []> {
  bits<4> rd;
  bits<4> rs;

  let Inst{11-8} = rd;
  let Inst{7-4} = rs;

  let Opcode = opcode.Value;
}

// Binary Inst
class TGInstB<TINYGPUOpCode opcode, dag outs, dag ins, string opcodestr, string argstr>
    : TGInst<outs, ins, opcodestr, argstr, []> {
  bits<4> rd;
  bits<4> rs;
  bits<4> rt;

  let Inst{11-8} = rd;
  let Inst{7-4} = rs;
  let Inst{3-0} = rt;

  let Opcode = opcode.Value;
}

// Compare Inst
class TGInstC<TINYGPUOpCode opcode, dag outs, dag ins, string opcodestr, string argstr>
    : TGInst<outs, ins, opcodestr, argstr, []> {
  bits<4> rs;
  bits<4> rt;

  let Inst{7-4} = rs;
  let Inst{3-0} = rt;

  let Opcode = opcode.Value;
}

// Const
class TGInstCon<TINYGPUOpCode opcode, dag outs, dag ins, string opcodestr, string argstr>
    : TGInst<outs, ins, opcodestr, argstr, []> {
  bits<8> imm8;
  bits<4> rd;

  let Inst{11-8} = rd;
  let Inst{7-0} = imm8;

  let Opcode = opcode.Value;
}

// Branch
class TGInstBr<TINYGPUOpCode opcode, dag outs, dag ins, string opcodestr, string argstr>
    : TGInst<outs, ins, opcodestr, argstr, []> {
  bits<3> nzp;
  bits<8> imm8;

  let Inst{11-9} = nzp;
  let Inst{7-0} = imm8;

  let Opcode = opcode.Value;
}

// Ret
class TGInstR<TINYGPUOpCode opcode, dag outs, dag ins, string opcodestr, string argstr>
    : TGInst<outs, ins, opcodestr, argstr, []> {

  let Opcode = opcode.Value;
}