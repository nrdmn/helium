.section .bss

stack_bottom:
.skip 4096
stack_top:


.section .text

.code32

.global _start
_start:
	movl $stack_top, %esp

	cmpl $0x36d76289, %eax
	jne 1f

	call main

1:
	hlt

