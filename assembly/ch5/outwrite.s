#Purpose: trying to write to the regular stdout stream

#Purpose: trying to write to the regular stdout stream
.section .data
.equ SYS_WRITE, 4

.section .bss
.lcomm BUFFER, 50



.section .text
.globl _start

_start:
	movl $0, %edi
	movl $BUFFER, %ebx
	movb $53, (%ebx, %edi, 1)
	movl $SYS_WRITE, %eax
	movl $1, %ebx
	movl $BUFFER, %ecx
	movl $1, %edx
	int $0x80
	movl $1, %eax
	movl $0, %ebx
	int $0x80
	
