#include <stdio.h>
#include <stdlib.h>

//  error: initializer element is not constant
//  Global variable encounters computing.

int main() {

	int i = 0; 
	char s1[] = "Hello!";
	char *s2 = malloc(sizeof(char) *7);

	do {
		s2[i] = s1[i];
		i++;
	} while (s1[i] != '\0');

	s2[i] = '\0';
}

