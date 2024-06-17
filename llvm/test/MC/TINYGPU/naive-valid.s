#RUN: llvm-mc %s -triple=tinygpu -show-encoding | FileCheck -check-prefixes=CHECK,CHECK-INST %s

# CHECK: MUL	R0, blockIdx, blockDim
# CHECK-INST: encoding: [0x11,0x50]
MUL R0, %blockIdx, %blockDim

# CHECK: CONST	R1, 0
# CHECK-INST: encoding: [0x00,0x91]
CONST R1, 0

# CHECK: CONST	R2, 8
# CHECK-INST: encoding: [0x08,0x91]
CONST R2, 8

# CHECK: CONST	R3, 16
# CHECK-INST: encoding: [0x10,0x91]
CONST R3, 16

# CHECK: ADD	R4, R1, R0
# CHECK-INST: encoding: [0x10,0x31]
ADD R4, R1, R0

# CHECK: LDR	R4, R4
# CHECK-INST: encoding: [0x10,0x71]
LDR R4, R4

# CHECK: ADD	R5, R2, R0
# CHECK-INST: encoding: [0x10,0x31]
ADD R5, R2, R0

# CHECK: LDR	R5, R5
# CHECK-INST: encoding: [0x10,0x71]
LDR R5, R5

# CHECK: ADD	R6, R4, R5
# CHECK-INST: encoding: [0x11,0x31]
ADD R6, R4, R5

# CHECK: ADD	R7, R3, R0
# CHECK-INST: encoding: [0x10,0x31]
ADD R7, R3, R0

# CHECK: STR	R7, R6
# CHECK-INST: encoding: [0x11,0x80]
STR R7, R6

# CHECK: RET
# CHECK-INST: encoding: [0x00,0xf0]
RET