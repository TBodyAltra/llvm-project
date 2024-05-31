//===-- TINYGPURegisterInfo.td - TINYGPU Register defs --------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===--------------------------------------------------------------------------===//

//===--------------------------------------------------------------------------===//
// Declarations that describe the TINYGPU register files
//===--------------------------------------------------------------------------===//

let Namespace = "TINYGPU" in {
class TINYGPUReg<bits<4> Enc, string n, list<string> alt = []> : Register<n> {
  let HWEncoding{3-0} = Enc;
  let AltNames = alt;
}
} // namespace TINYGPU

let FallbackRegAltNameIndex = NoRegAltName in
def ABIRegAltNameIndex : RegAltNameIndex;

let RegAltNameIndices = [NoRegAltName] in {
  def R0  : TINYGPUReg<0, "R0">, DwarfRegNum<[0]>;
  def R1  : TINYGPUReg<1, "R1">, DwarfRegNum<[1]>;
  def R2  : TINYGPUReg<1, "R2">, DwarfRegNum<[2]>;
  def R3  : TINYGPUReg<1, "R3">, DwarfRegNum<[3]>;
  def R4  : TINYGPUReg<1, "R4">, DwarfRegNum<[4]>;
  def R5  : TINYGPUReg<1, "R5">, DwarfRegNum<[5]>;
  def R6  : TINYGPUReg<1, "R6">, DwarfRegNum<[6]>;
  def R7  : TINYGPUReg<1, "R7">, DwarfRegNum<[7]>;
  def R8  : TINYGPUReg<1, "R8">, DwarfRegNum<[8]>;
  def R9  : TINYGPUReg<1, "R9">, DwarfRegNum<[9]>;
  def R10 : TINYGPUReg<1, "R10">, DwarfRegNum<[10]>;
  def R11 : TINYGPUReg<1, "R11">, DwarfRegNum<[11]>;
  def R12 : TINYGPUReg<1, "R12">, DwarfRegNum<[12]>;
}

let RegAltNameIndices = [ABIRegAltNameIndex] in {
  def R13 : TINYGPUReg<1, "R13", ["blockIdx"]>, DwarfRegNum<[13]>;
  def R14 : TINYGPUReg<1, "R14", ["blockDim"]>, DwarfRegNum<[14]>;
  def R15 : TINYGPUReg<1, "R15", ["threadIdx"]>, DwarfRegNum<[15]>;
}

def GPR : RegisterClass<"TINYGPU", [i8], 8, (add (sequence "R%u", 0, 15))> {
  let RegInfos = RegInfoByHwMode<[DefaultMode], [RegInfo<8, 8, 8>]>;
}
