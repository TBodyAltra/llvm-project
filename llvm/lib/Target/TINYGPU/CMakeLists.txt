add_llvm_component_group(TINYGPU)

set(LLVM_TARGET_DEFINITIONS TINYGPU.td)
tablegen(LLVM TINYGPUGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM TINYGPUGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM TINYGPUGenMCCodeEmitter.inc -gen-emitter)
add_public_tablegen_target(TINYGPUCommonTableGen)

add_llvm_target(TINYGPUCodeGen
  TINYGPUTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  MC
  TINYGPUInfo
  Support
  Target

  ADD_TO_COMPONENT
  TINYGPU
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
