#Purpose: the program finds the second greatest element from a list of numbers
#for this purpose it will use 5 registers
#	%edi: will hold the index of the current examined number
#	%ecx: will hold the maximum currently found
#	%eax will hold the currently examined number
#	%ebx will hold the second greatest number currently found
#	%edx will hold the end of the list

.section .data
data_items:
	.long 12,32, 98, 82, 77,55

.section .text
.globl _start
_start:
	movl $0, %edi
	movl data_items(,%edi, 4), %eax
	movl %eax,%ecx
	movl $5, %edi
	movl data_items(,%edi, 4), %edx
	movl $0, %edi

start_loop:
	cmpl data_items(,%edi, 4), %edx
	je end_loop

	incl %edi
	movl data_items(,%edi, 4), %eax
	cmpl %ecx, %eax
	jl else
	movl %ecx, %ebx
	movl %eax, %ecx
	jmp start_loop
else:
	cmpl %ebx, %eax
	jl start_loop
	movl %eax, %ebx
	jmp start_loop

end_loop:
	movl $1, %eax
	int $0x80


