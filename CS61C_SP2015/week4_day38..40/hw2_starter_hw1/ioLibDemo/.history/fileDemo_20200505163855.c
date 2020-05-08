// Demo of IO Library function.

#include <stdio.h>

int main()
{
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
	FILE *fp1 = fopen("fwrite.txt", "w");
	printf("the count is %d\n", fwrite(fptr, sizeof(char), 3, fp1));

	/**
	 * 4. size_t __cdecl fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
	 * read from _File to _DstBuf (binary)
	 */

	//fread();

	/**
	 * 5. int __cdecl fgetc(FILE *_File);
	 */
	char c = fgetc(fptr);
	printf("the first char of fileDemo.txt is: %c\n", c);

	/**
	 * 6.
	 */
	FILE *fp2 = fopen("fputc.txt", "w");
	printf("The ascii code of char which is written into %s is: %d\n", "fputc.txt", fputc(c, fp2));

	/**
	 * 7. fgets
	 * 	fgets (char *__restrict__ __s, int __n, FILE *__restrict__ __stream)
		{
			if (__ssp_bos (__s) != (size_t) -1 && (size_t) __n > __ssp_bos (__s))
				__chk_fail ();
			return __fgets_alias (__s, __n, __stream);
		}
	 */
	fgets();

	/**
	 * 8. fputs
	 */

	/**
	 * 9. fscanf():
	 */

	/**
	 * 10. fprintf():
	 */

	fclose(fptr);

	return 0;
}
