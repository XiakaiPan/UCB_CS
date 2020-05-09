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

    FILE *fbranches = fopen(".bear_git/.branches", "w");
}