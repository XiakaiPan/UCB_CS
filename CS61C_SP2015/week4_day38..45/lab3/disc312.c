#include <stdlib.h>

int main() {
	int n;
	int fib = 1, i = 1, j = 1;
	if (n == 0) 		return 0;
	else if (n == 1)	return 1;
	n -= 2;
	while (n != 0) {
		fib = i + j;
		j = i;
		i = fib;
		n--;
	}
	return fib;
}
