add_llvm_component_library(LLVMTINYGPUDesc
  TINYGPUAsmBackend.cpp
  TINYGPUELFObjectWriter.cpp
  TINYGPUMCAsmInfo.cpp
  TINYGPUMCTargetDesc.cpp
  TINYGPUMCCodeEmitter.cpp

  LINK_COMPONENTS
  MC
  TINYGPUInfo
  Support
   
  ADD_TO_COMPONENT
  TINYGPU
)