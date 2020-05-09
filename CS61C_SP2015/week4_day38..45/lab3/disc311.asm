# Strcpy:
# $s1 -> char s1[] = "Hello!";
# $s2 -> char *s2 = malloc(sizeof(char) * 7);
## int i = 0;
## do {
##	s2[i] = s1[i];
##	i++;
## } while(s1[i] != '\0');
## s2[i] = '\0';

.data
str: 	.asciiz "Hello!"


	addiu	$t0, $0, 0
Loop:	addu	$t1, $s1, $t0	# s1[i]
	addu	$t2, $s2, $t0	# s2[i]
	lb 	$t3, 0($t1)	# char is 1 byte!
	sb	$t3, 0($t2)	
	
	addiu	$t0, $t0, 1
	addiu	$t1, $t1, 1
	
	bne	$t0, $0, Loop
	j 	Done
Done:	sb	$t4, 1($t2)
	
	