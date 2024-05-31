add_llvm_component_library(LLVMTINYGPUDisassembler
  TINYGPUDisassembler.cpp

  LINK_COMPONENTS
  MCDisassembler
  TINYGPUInfo
  Support

  ADD_TO_COMPONENT
  TINYGPU
)