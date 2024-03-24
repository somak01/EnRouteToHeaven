#Purpose: This program converts an input file
#	  to an output file with all letters
#	  converted to uppercase.
#Processing:	1)Open the input file
#		2)Open the output file
#		4)While we're not at the end of the input file
#			a)read part of a file into our memory
#			b)go through each byte of memory
#				if the byte is a lower-case letter,
#				convert it to uppercases
#			c)write the memory buffer to output file

.section .data
######Constants########
.equ SYS_OPEN, 5
.equ SYS_CLOSE, 6
.equ SYS_READ, 3
.equ SYS_WRITE, 4
.equ SYS_EXIT, 1

#options for open 
.equ O_RDONLY, 0
.equ O_CREAT_WRONLY_TRUNC, 03101

#standard file descriptors
.equ STDIN, 0
.equ STDOUT, 1
.equ STDERR, 2

#System call interrupt
.equ LINUX_SYSCALL, 0x80

.equ END_OF_FILE, 0
.equ NUMBER_ARGUMENTS, 2

.section .bss
#Buffer - this is where the data is loaded into 
#	from the data file and written from
#	into the output file. This should 
#	never exceed 16000 for various reasons

.equ BUFFER_SIZE, 500
.lcomm BUFFER_DATA, BUFFER_SIZE


.section .text

#stack positions
.equ ST_SIZE_RESERVE, 8
.equ ST_FD_IN, -4
.equ ST_FD_OUT, -8
.equ ST_ARGC, 0#Number of arguments
.equ ST_ARGV_0, 4 #name of the program
.equ ST_ARGV_1, 8 #name of the input file
.equ ST_ARGV_2, 12#name of the output file


.globl _start
_start:
###Initializer program###
#save the stack pointer
movl %esp, %ebp

#Allocate space for our file descriptors
subl $ST_SIZE_RESERVE, %esp

open_files:
open_fd_in:
###Open input file###
movl $SYS_OPEN, %eax
#input file name into ebx
movl ST_ARGV_1(%ebp), %ebx
#read only flag
movl $O_RDONLY, %ecx
#Move the permissions into %edx
movl $0666, %edx
#call linux
int $LINUX_SYSCALL
#store the input file
store_fd_in:
	movl %eax, ST_FD_IN(%ebp)

###Open output file###
open_fd_out:
movl $SYS_OPEN, %eax
#output file name into ebx
movl ST_ARGV_2(%ebp), %ebx
#opening mode for output file
movl $O_CREAT_WRONLY_TRUNC, %ecx
#Move the permission into %edx
movl $0666, %edx
#call linux
int $LINUX_SYSCALL

#store the output file
store_fd_out:
	movl %eax, ST_FD_OUT(%ebp)



###BEGIN MAIN LOOP###
read_loop_begin:
	movl $SYS_READ, %eax
	#get the input file descriptor
	movl ST_FD_IN(%ebp), %ebx
	#the location to read data
	movl $BUFFER_DATA, %ecx
	#the size of the buffer
	movl $BUFFER_SIZE, %edx
	#Size of the buffer read is returned in %eax
	int $LINUX_SYSCALL

###Exit if we have reached the end###
cmpl $END_OF_FILE, %eax
#if found go the the end
jle end_loop

continue_read_loop:
	#Convert the block to upper case
	pushl $BUFFER_DATA #location to the buffer
	pushl %eax #size of the buffer
	call convert_to_upper
	popl %eax #get the size back
	addl $4, %esp #restore %esp

###Write the block out to the output file###
#size of the buffer
movl %eax, %edx
movl $SYS_WRITE, %eax
#file to use
movl ST_FD_OUT(%ebp), %ebx
#location of the buffer
movl $BUFFER_DATA, %ecx
int $LINUX_SYSCALL

###Continue the loop
jmp read_loop_begin

end_loop:
###Close the files###
movl $SYS_CLOSE, %eax
movl ST_FD_OUT(%ebp), %ebx
int $LINUX_SYSCALL

movl $SYS_CLOSE, %eax
movl ST_FD_IN(%ebp), %ebx
int $LINUX_SYSCALL

###EXIT###
movl $SYS_EXIT, %eax
movl $0, %ebx
int $LINUX_SYSCALL





#Purpose: This function does the conversion part of the program
#Input: THe first parameter is the location of the block to convert
#	The second parameter is the length of the buffer
#Output: 	This function overwrites the current 
#		buffer with the upper=casified version
#Variables:
#		%eax - beginning of buffer
#		%ebx - length of buffer
#		%edi - current buffer offset
#		%cl  - current byte examined(first part of %ecx)


#CONSTANTS#
#The lower boundary of our search
.equ LOWERCASE_A, 'a'
#The upper boundary of our search
.equ LOWERCASE_Z, 'z'
#The number needed for the conversion
.equ UPPER_CONVERSION, 'A' - 'a'

#Stack stuff#
.equ ST_BUFFER_LEN, 8 # length of the buffer
.equ ST_BUFFER, 12    # actual buffer
convert_to_upper:
	pushl %ebp
	movl %esp, %ebp
#Set up variables
	movl ST_BUFFER(%ebp), %eax
	movl ST_BUFFER_LEN(%ebp), %ebx
	movl $0, %edi

#if a buffeer with zero length was given to us just leave
cmpl $0, %ebx
je end_convert_loop

convert_loop:
	#get the current byte
	movb (%eax, %edi, 1), %cl
	# go to the next byte unless it is between 'a' and 'z'
	cmpb $LOWERCASE_A, %cl
	jl next_byte
	cmpb $LOWERCASE_Z, %cl
	jg next_byte
	#otherwise convert the byte to uppercase
	addb $UPPER_CONVERSION, %cl
	movb %cl, (%eax, %edi, 1)
next_byte:
	incl %edi
	cmpl %edi, %ebx
	jne convert_loop
end_convert_loop:
	#no retun value, just leave
	movl %ebp, %esp
	popl %ebp
	ret
