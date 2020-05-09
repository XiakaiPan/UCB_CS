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

	FILE *fptr = fopen("fileDemo.txt", "r");
	/**
	 * 3. size_t __cdecl fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File);
	 * return count;
	 * read binary data from ptr count times by size to fp;
	 */
	FILE *fptr1 = fopen("fileDemo.txt", "r");
	FILE *fp1 = fopen("fwrite.txt", "w");
	printf("the count is %d", fwrite(fptr1, sizeof(char), 3, fp1));

	/**
	 * 4. size_t __cdecl fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
	 * 
	 */
	//fread();

	return 0;
}
