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
}
