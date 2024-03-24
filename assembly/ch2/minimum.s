#the purpose of the program is to find the minimum of a list of numbers
#the registers that will be used are the following
#	%ebx - will hold the minimum value 
#	%edi - will hold the currently examined items index
#	%eax - will hold the current value


.section .data
 data_items:
	.long 3, 12, 5, 2,1, 12, 32, 1

.section .text

.globl _start
_start:
 movl $0, %edi
 movl data_items(, %edi, 4), %eax 
 movl %eax, %ebx
start_loop:
 cmpl $7, %edi
 je end_loop
 incl %edi 
 movl data_items(, %edi, 4), %eax 
 cmpl %ebx, %eax
 jge start_loop 
 movl %eax, %ebx
 jmp start_loop
end_loop:

 movl $1, %eax
 int $0x80
