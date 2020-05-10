	.data					# data of program
	.word 2, 4, 6, 8
n:	.word 13


	.text					# code
main:		add	$t0, $0, $zero
		addi	$t1, $zero, 1
		la	$t3, n
		lw	$t3, 0($t3)
fib:		beq	$t3, $0, finish
		add 	$t2, $t1, $t0
		move 	$t0, $t1
		move	$t1, $t2
		subi	$t3, $t3, 1
		j	fib
finish:		addi	$a0, $t0, 0
		li 	$v0, 1		# You will be asked about what the purpose of this line for syscall -- print a integer
		syscall
		li	$v0, 10
		syscall
		
# About system call
# $v0 = 1 printf_int
# $v0 = 2 print_float
# $v0 = 3 print_double
# $v0 = 4 print_string

### read an entire line of input up to and including the newline character.
# $v0 = 5 read int to $v0
# $v0 = 6 read_float to $v0
# $v0 = 7 read_double

### The read_string service has the same semantices as the UNIX library routine fgets.
# $v0 = 8 read_string

### The sbrk serveice returns the address to a block of memory containing n additional bytes. this would be 
### used for dynamic memory allocation.
# $v0 = 9 sbrk, dynamicly alllocate memory(bytes?) $a0 = amount, $v0 is the first address of allocated space

# $v0 = 10 exit