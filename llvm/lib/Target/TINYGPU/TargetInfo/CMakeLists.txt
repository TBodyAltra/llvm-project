add_llvm_component_library(LLVMTINYGPUInfo
  TINYGPUTargetInfo.cpp

  LINK_COMPONENTS
  Support
  MC

  ADD_TO_COMPONENT
  TINYGPU
)
