.section .bss
stack_bottom:
.skip 4096
stack_top:


.section .text
.global _start
_start:
	movl $stack_top, %esp

	/* check for multiboot */
	cmpl $0x2badb002, %eax
	je _multiboot_init

	/* check for multiboot2 */
	cmpl $0x36d76289, %eax
	je _multiboot2_init

1:
	hlt
	jmp 1b

_multiboot_init:
	pushl %ebx
	call multiboot_init

_multiboot2_init:
	pushl %ebx
	call multiboot2_init
