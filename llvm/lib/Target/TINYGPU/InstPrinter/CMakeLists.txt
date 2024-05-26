add_llvm_component_library(LLVMTINYGPUAsmPrinter
    TINYGPUInstPrinter.cpp

    LINK_COMPONENTS
    MC
    Support

    ADD_TO_COMPONENT
    TINYGPU
)