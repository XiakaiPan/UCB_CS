// Demo of IO Library function.

#include <stdio.h>

int main()
{
	/* Part 1:Create, open, read file. */
	/**
	 *  1. FILE * fopen(const char * path,const char * mode);
	 * return file pointer: FILE*;
	 * mode
	 * 	r: read only
	 * 	r+: open, read and write
	 * 	w: creat or overwrite
	 * 	w+: open, read and write
	 * 	a:append
	 * 	x: ?
	 */

	FILE *fp = fopen("fileDemo.txt", "r");

	/**
	 * 2. int fclose(FILE *fp);
	 */
	fclose(fp);

	/**
	 * 3. int write(const void* ptr, int size, int count, FILE* fp);
	 * return count;
	 * read data from ptr count times by size to fp;
	 */
	FILE *fptr = fopen("fileDemo.txt", "r");
	FILE *fp = fopen("fileDemo2.txt", "w");
	printf("the count is %d", fwrite)

	fread();
}
