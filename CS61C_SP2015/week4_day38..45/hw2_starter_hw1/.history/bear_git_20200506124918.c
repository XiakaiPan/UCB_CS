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
            isExist = 1;
            continue;
        }
        fprintf(fnewindex, "%s\n", line);
    }
    fclose(findex);
    fclose(fnewindex);

    if (!isExist)
    {
        fprintf(stderr, "ERROR: File %s not tracked\n", filename);
        fs_rm(".bear_git/.newindex");
        return 1;
    }

    fs_mv(".bear_git/newindex", ".bear_git/.index");

    return 0;
}

/**
 * bear_git commit -m <msg>
 */
const char *go_bears = "GO BEARS!";

int is_commit_msg_ok(const char *msg)
{
    int i = 0, j = 0;
    while (msg[i] != '\0')
    {
        if (msg[i] == go_bears[j])
        {
            if (go_bears[j + 1] != '\0')
            {
                i++;
                j++;
                continue;
            }
            return 1;
        }

        i++;
        j = 0;
    }

    return 0;
}

void next_commit_id(char *commit_id)
{
    int i = 0;

    while (commit_id[i] != '\0')
    {
        switch (commit_id[i])
        {
        case '0':
        case 'c':
            commit_id[i] = '6';
            break;
        case '6':
            commit_id[i] = '1';
            goto End;
            break;
        case '1':
            commit_id[i] = 'c';
            goto End;
            break;
        default:
            fprintf(stderr, "ERROR: commit id only contain charactors in ['6', '1', 'c], origin commit id is \"%s\"\n", commit_id);
            break;
        }
        i++;
    }
End:
    return;
}

int bear_git_commit(char *msg)
{
    //First, check whether the commit string contains "GO BEARS!". If not, display an error message.
    if (!is_commit_msg_ok(msg))
    {
        fprintf(stderr, "ERROR: Message must contain %s\n", go_bears);
        return 1;
    }

    // Read the ID of the previous last commit from .beargit/.prev;
    // Generate the next ID (newid) in such a way that: All characters of the id are either 6, 1 or c;  Generating 100 IDs in a row will generate 100 IDs that are all unique(Hint: you can do this in such a way that you go through all possible IDs before you repeat yourself.Some of the ideas from the number representation class may help you !) char commit_id[COMMIT_ID_SIZE];
    read_string_from_file(".bear_git/.prev", commit_id, COMMIT_ID_SIZE);
    next_commit_id(commit_id);
}