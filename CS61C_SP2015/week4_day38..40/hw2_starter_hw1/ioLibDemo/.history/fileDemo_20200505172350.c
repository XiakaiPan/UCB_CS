// Demo of IO Library function.

#include <stdio.h>
#include <string.h>

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
	 * 7. char *fgets(char *str, int size, FILE *stream); 
	 * write from str to stream
	 */

	char str[10];
	while (fgets(str, sizeof(str), fp))
	{
		// char *__cdecl strtok(char * __restrict__ _Str,
		// const char * __restrict__ _Delim) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
		strtok(str, "\n");
		printf("the string written to fgets.txt is: %s\n", str);
	}

	/**
	 * 8. int __cdecl fputs(const char * __restrict__ _Str,FILE * __restrict__ _File);
	 */
	char s[] = "Hello, fputs()!";
	FILE *fp3 = fopen("fputs.txt", "w");
	fputs(s, fp3);

	/**
	 * 9. fscanf():
	 */
	char s1[20];
	// FILE *fp4 = fopen("fscanf.txt", "w");
	fscanf(fptr, "%s", "Hello, fscanf()!");

	/**
	 * 10. fprintf():
	 */

	fclose(fptr);

	return 0;
}
