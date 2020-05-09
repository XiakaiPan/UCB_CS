// bear_git.c
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>

#include "beargit.h"
#include "util.h"

/**
 * beargit init
 */
int bear_git_init(void)
{
    fs_mkdir(".bear_git"); // Create bear_git derectory.

    // Create new file .bear_git/.index
    FILE *findex = fopen(".bear_git/.index", "w");
    fclose(findex);

    // Create new file .bear_git/.branches and include master branch.
    FILE *fbranches = fopen(".bear_git/.branches", "w");
    fprintf(fbranches, "%s\n", "master");
    fclose(fbranches);

    //Create .bear_git/.prev and .bear_git/.current_branch files.
    write_string_to_file(".bear_git/,prev", "0000000000000000000000000000000000000000");
    write_string_to_file(".bear_git/.current_branch", "master");

    return 0;
}

/**
 * bear_git add <filename>
 * Append filename to list in .bear_git/.index if it isn't in there yet.
 * 
 * Possible errors (to stderr): 
 * >> ERROR: File <filename> already added
 * 
 * Output (to stdout):
 * - None if successful
 */

int bear_git_add(const char *filename)
{
    FILE *findex = fopen(".bear_git/.index", "r");
    FILE *fnewindex = fopen(".bear_git/.newindex", "w");

    char line[FILENAME_SIZE];
    while (fgets(line, sizeof(line), findex))
    // line[] include a filename with "\n"
    {
        strtok(line, "\n");
        if (strcmp(line, filename) == 0)
        {
            fprintf(stderr, "ERROR: File %s already added\n", filename);
            fclose(findex);
            fclose(fnewindex);
            fs_rm(".bear_git/.newindex");
            return 3;
        }

        fprintf(fnewindex, "%s\n", line);
    }

    fprintf(fnewindex, "%s\n", filename);
    fclose(findex);
    fclose(fnewindex);

    fs_mv(".bear_git/.fnewindex", ".bear_git/.index");

    return 0;
}

/**
 * bear_git_status: read the file .beargit/.index and
 * print a line for each tracked file.
 * 
 * Tracked files:
 * 
 * <file1>
 * [...]
 * <fileN>
 * 
 * <N> files total
 */
int bear_git_status()
{
    FILE *findex = fopen(".bear_git/.index", "r");
    int num = 0;

    fprintf(stdout, "%s\n\n", "Tracked files:");

    char line[FILENAME_SIZE];
    while (fgets(line, sizeof(line), findex))
    {
        strtok(line, "\n");
        num++;
        fprintf(stdout, "%s\n", line);
    }

    fprintf(stdout, "\n%d files total\n", num);

    fclose(findex);

    return 0;
}

/**
 * bear_git rm <filename>
 */
int bear_git_rm(const char *filename)
{
    FILE *findex = fopen(".bear_git/.index", "r");
    FILE *fnewindex = fopen(".bear_git/.newindex", "w");

    char line[FILENAME_SIZE];
    _Bool isExist = 0;

    while (fgets(line, sizeof(line), findex))
    {
        strtok(line, "\n");
        if (strcmp(line, filename) == 0)
        {
            continue;
        }
        fprintf(fnewindex, "%s\n", line);
    }

    return 0;
}