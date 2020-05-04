.data				#data section
str: .asciiz "Hello world\n"
number: .word 256

.text 				#code section
.globl main
main:
li	$v0, 4			#system call for printing strings
la	$a0, str		#loading our string from data section to the $a0 register
syscall

la	$t0, number		#loading our number from data section to the $t0 register
lw 	$s1, 0($t0)		#loading our number as a word to another register, $s1

addi	$t2, $s1, 8		#adding our number ($s1) with 8 and leaving the sum to register $t2

sw 	$t2, 0($t0)		#storing the sum of register $t2 as a word at the first place of $t0

li 	$v0, 10			#system call for terminating the execution
syscall