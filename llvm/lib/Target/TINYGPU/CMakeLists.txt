add_llvm_component_group(TINYGPU)

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
