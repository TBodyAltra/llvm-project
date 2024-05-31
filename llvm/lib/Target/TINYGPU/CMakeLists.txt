add_llvm_component_group(TINYGPU)

set(LLVM_TARGET_DEFINITIONS TINYGPU.td)
tablegen(LLVM TINYGPUGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM TINYGPUGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM TINYGPUGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM TINYGPUGenAsmMatcher.inc -gen-asm-matcher)
tablegen(LLVM TINYGPUGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM TINYGPUGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM TINYGPUGenDisassemblerTables.inc -gen-disassembler)
tablegen(LLVM TINYGPUGenMCPesudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM TINYGPUGenCallingConv.inc -gen-callingconv)
tablegen(LLVM TINYGPUGenDAGISel.inc -gen-dag-isel)
add_public_tablegen_target(TINYGPUCommonTableGen)

add_llvm_target(TINYGPUCodeGen
  TINYGPUTargetMachine.cpp
  TINYGPUAsmPrinter.cpp
  TINYGPUFrameLowering.cpp
  TINYGPUInstrInfo.cpp
  TINYGPUISelDAGToDAG.cpp
  TINYGPUISelLowering.cpp
  TINYGPUMCInstLower.cpp
  TINYGPURegisterInfo.cpp
  TINYGPUSubtarget.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  MC
  TINYGPUInfo
  Support
  Target
  AsmPrinter
  SelectionDAG
  TINYGPUDesc
  TINYGPUInfo
  TINYGPUAsmPrinter

  ADD_TO_COMPONENT
  TINYGPU
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
add_subdirectory(AsmParser)
add_subdirectory(InstPrinter)
add_subdirectory(Disassembler)
