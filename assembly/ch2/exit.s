#THe purpose of this program is to return a value as an exit code


.section .data
#since there is no data in this program there's no need for this section

.section .text #this is the section where the instructions are written

.globl _start
_start:
	movl $1, %eax
	movl $3, %ebx



