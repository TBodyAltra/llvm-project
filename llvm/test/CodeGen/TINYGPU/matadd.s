	.text
	.file	"matadd.ll"
	.globl	matadd                          # -- Begin function matadd
	.p2align	1
	.type	matadd,@function
matadd:                                 # @matadd
# %bb.0:                                # %entry
	MUL	R3, blockIdx, blockDim
	ADD	R3, R3, threadIdx
	ADD	R1, R1, R3
	LDR	R1, R1
	ADD	R0, R0, R3
	LDR	R0, R0
	ADD	R0, R0, R1
	ADD	R1, R2, R3
	STR	R0, R1
	RET	
.Lfunc_end0:
	.size	matadd, .Lfunc_end0-matadd
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
