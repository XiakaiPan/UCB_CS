	.text
main:
	li	$s0, 0x30
loop:
	move	$a0, $s0	#copy from s0 to a0
	
	li	$v0, 11		#syscall with v0 = 11 will print out
	syscall
	
	addi	$s0, $s0, 3	#what happens if the constant is changed?
	
	li 	$t0, 0x5d	
	bne	$s0, $t0, loop
	nop			#delay slot filler (just in case)
	
stop:		j	stop	#loop forever here
	nop			#delay slot filler (just in case)