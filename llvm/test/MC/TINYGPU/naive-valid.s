#RUN: llvm-mc %s -triple=tinygpu -show-encoding \
#RUN:     | FileCheck -check-prefixes=CHECK,CHECK-INST %s
#RUN: llvm-mc %s -triple=tinygpu -filetype=obj \
#RUN:     | llvm-objdump -d - | FileCheck -check-prefix=CHECK-INST %s

MUL R0, %blockIdx, %blockDim
CONST R1, 0
CONST R2, 8
CONST R3, 16
ADD R4, R1, R0
LDR R4, R4
ADD R5, R2, R0
LDR R5, R5
ADD R6, R4, R5
ADD R7, R3, R0
STR R7, R6
RET
