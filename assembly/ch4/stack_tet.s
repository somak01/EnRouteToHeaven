#Purpose: to try out the stack, since I doesn't really understand functions
#	at first, so hopefully after tinkering a little bit I will become
#	enlightened(or not :D)


#There is no data so the .data section will only be present for reading purposes


.section .data

.section .text
.globl _start
_start:
	pushl $3
	pushl $9
	pushl $10
	popl %edi
	movl (%esp), %ebx
	movl $1, %eax
int $0x80

