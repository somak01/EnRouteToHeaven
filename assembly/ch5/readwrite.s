#Purpose: to read from the standard input and write to the standard ouput
#	  possibly do the same upper conversion like in the example program
#I'm not sure about the varibles it will pan out one way or another



.section .data

###Constants###
.equ STDIN, 0
.equ STDOUT,1
.equ SYS_WRITE,4
.equ SYS_READ,3
.equ SYS_OPEN,5
.equ SYS_CLOSE,6
.equ SYS_EXIT,1
.equ LINUX_SYSCALL,0x80
.equ END_OF_FILE, 0
.section .bss
.equ BUFFER_SIZE, 1 #should be the buffer size
.lcomm BUFFER, BUFFER_SIZE	#this should be the actual buffer
.equ ST_SIZE_RESERVE, 8
.equ ST_FD_IN, -4
.equ ST_FD_OUT, -8
.equ ST_ARGC, 0
.equ ST_ARGV_0, 4
.equ ST_ARGV_1, 8
.equ ST_ARGV_2, 12


.section .text
.globl _start
_start:
	movl %esp, %ebp
	subl $ST_SIZE_RESERVE, %esp
read_loop_begin:
	movl $SYS_READ, %eax
	movl $STDIN, %ebx
	movl $BUFFER, %ecx
	movl $BUFFER_SIZE, %edx
	int $LINUX_SYSCALL
	
	cmpl $END_OF_FILE, %eax
	jle end_loop
continue_read_loop:
	pushl $BUFFER
	pushl %eax
	call convert
	popl %eax
	addl $4, %esp
	movl %eax, %edx
	movl $SYS_WRITE, %eax
	movl $STDOUT, %ebx
	movl $BUFFER, %ecx
	int $LINUX_SYSCALL
	jmp read_loop_begin

end_loop:
	movl $SYS_EXIT, %eax
	movl $0, %ebx
	int $LINUX_SYSCALL




.type convert, @function
convert:
	.equ LOWERCASE_A, 'a'
	.equ LOWERCASE_Z, 'z'
	.equ UPPER_CONVERSION, 'A' - 'a'

pushl %ebp
movl %esp, %ebp
movl 12(%ebp), %eax
movl 8(%ebp), %ebx
movl $0, %edi
cmpl $0, %ebx
je end_conversion
convert_loop:
movb (%eax, %edi, 1), %cl
cmpb $LOWERCASE_A, %cl
jl next_byte
cmpb $LOWERCASE_Z, %cl
jg next_byte
addb $UPPER_CONVERSION, %cl
movb %cl, (%eax, %edi, 1)
next_byte:
incl %edi
cmpl %edi, %ebx
jne convert_loop

end_conversion:
	movl %ebp, %esp
	popl %ebp
	ret
