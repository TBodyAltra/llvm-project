add_llvm_component_library(LLVMTINYGPUAsmParser
    TINYGPUAsmParser.cpp

    LINK_COMPONENTS
    MC
    MCParser
    TINYGPUDesc
    TINYGPUInfo
    Support

    ADD_TO_COMPONENT
    TINYGPU
)