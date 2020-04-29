#include <stdio.h>
/* 2 Uncommented Code? Yuck! */
/* 
 * 1. Compute the sum of all elemrnts in the arr.
 * Returns the sum of the first N elements in arr.
 */
 int foo(int *arr, int n) {
 	return n ? arr[0] + foo(arr+1, n-1) : 0;
 }

 /*
  * 2. Count the num of 0 in arr.
  * Returns -1 times the number of zeros in the first N elements 
  * of arr.
  */
 int bar(int *arr, int n) {
 	int sum = 0, i;

 	for (i = n; i > 0; i) {
 		sum += !arr[i-1];
 	}

 	return ~sum + 1;
 }

 /*
  * 3. Exchange two numbers.
  * Does Nothing.
  */
 void baz(int x, int y) {
 	x = x ^ y;
 	y = y ^ x;
 	x = x ^ y;
 }

/* 3 Programming with Pointers. */
/* 1. Swaps the value of two ints of this function. */
void swap(int* x, int* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
/* 2. Increments the values of an int outside of this function by one. */
void increment(int *x) {
	(*x)++;
}
/* 3 Returns the number of bytes in a string. Does not use strlen. */
int strlength(char *c) {
	int i = 0;
	while (c[i] != '\0') {
		i++;
	}
	return i;
}

// 4 Problem?
/* 1. Returns the sum of all the elements in SUMMANDS. */
	int sum(int* summands) {
		int sum = 0;
		// wrong: for (int i = 0; i < sizeof(*summands); i++) {
		for (int i = 0; summands[i] ; i++) { 
			sum += *(summands + i);
		}
		return sum;
	}

/* 2. Increments all the letters in the String,held in a array of 
 * length N. Does not modify any other memory which has been 
 * previously allocated. */
 void increment_4(char* string, int n) {
 	char a[n];
 	for (int i = 0; i < n; i++) {
 		//*(string + i)++;
 		a[i] = string[i]++;
 	}
 }

 /* 3. Copies the string SRC to DST. */
void copy(char* src, char* dst) {
		// while (*src++ = *dst++)
		char *s = src;
		char *d = dst;
		while (*s != '\0') {
			*d = *s;
			s++;
			d++;
		}
}

int main() {
	/* 2. Comment */
	/*
	int x = 3, y = 5;
	printf("Original: x = %d, y = %d\n", x, y);
	baz(x, y);
	printf("After baz(x, y): x = %d, y = %d\n", x, y);
	*/

	/* 3. Pointers */
	// 1. swap
	int *a, *b;
	*a = 1;
	*b = 2;
	// printf("%d, %d", a, b);
	printf("Before swap(), a: %d, b: %d;\n", *a, *b);
	swap(a, b);
	printf("After swap(), a: %d, b: %d\n", *a, *b);
	// 2. increment
	increment(a);
	increment(b);
	printf("After increment(), a: %d, b: %d\n", *a, *b);	
	// 3. strlength
	char *c = "Hello!";
	printf("The length of 'Hello!' is: %d\n", strlength(c));

	/* 4 Promblem? */
	// 1
	int intarr[] = {1, 2, 3, 4};
	printf("The sum of all elements in intarr is: %d\n", sum(intarr));
	// 2
	char arr[] = "Hello, world!";
	increment_4(arr, strlen(arr));
	printf("After increments, the 'Hello, world!' become:\n%s\n", arr);
	// 3
	char src[] = "CS61C";
	char dst[10];
	copy(src, dst);
	printf("src is: %s\ndst is: %s", src, dst);

	return 0;
}
