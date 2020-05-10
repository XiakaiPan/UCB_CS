.text
.globl main		#main function
main:

li	$v0,11		#ll=system code for printing a character, $v0=register that gets the system code for printing as value
la	$a0,'a'		#'a'=our example character, $a0=register that accepts the character for printing
syscall			#Call to the System to execute our instructions and print the character at the a0 register

li 	$v0,10		#11=system code for terminating, $v0=register that gets the system code for terminating (optional, but desirable)
syscall			#Call to the System to terminate the execution