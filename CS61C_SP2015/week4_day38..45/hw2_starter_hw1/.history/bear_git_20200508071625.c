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

void next_commit_id_hw1(char *commit_id)
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

int bear_git_commit_hw1(char *msg)
{
    //First, check whether the commit string contains "GO BEARS!". If not, display an error message.
    if (!is_commit_msg_ok(msg))
    {
        fprintf(stderr, "ERROR: Message must contain %s\n", go_bears);
        return 1;
    }

    /**
     *  Read the ID of the previous last commit from .beargit/.prev
     *  and generate the next ID (newid)
     */
    char commit_id[COMMIT_ID_SIZE];
    read_string_from_file(".bear_git/.prev", commit_id, COMMIT_ID_SIZE);
    next_commit_id(commit_id);

    /**
     * Generate a new directory .beargit/<newid> and copy
     * .beargit/.index, .beargit/.prev, and all tracked files
     * into new directory.
     */

    // Generate new directory: .bear_git/<new_commit_id>
    char commit_dir[FILENAME_SIZE];
    sprintf(commit_dir, ".bear_git/%s", commit_id);
    fs_mkdir(commit_id);

    /* copy .bear_git/.index and .bear_git/.prev */
    char commit_file[FILENAME_SIZE];
    // Copy .bear_git/.index to new .bear_git/<newid>/.index
    sprintf(commit_file, "%s/.index", commit_dir);
    fs_cp(".bear_git/.index", commit_file);

    // Copy .bear_git/.prev to .bear_git/<newid>/.prev
    sprintf(commit_file, "%s/.prev", commit_dir);
    fs_cp(".bear_git/.prev", commit_file);

    /* Copy other tracked files indexed by .bear_git/.index */
    FILE *findex = fopen(".bear_git/.index", "r");
    char origin_file[FILENAME_SIZE];
    while (fgets(origin_file, sizeof(origin_file), findex))
    {
        strtok(origin_file, "\n");
        fprintf(commit_file, "%s/%s", commit_dir, origin_file);
        fs_cp(origin_file, commit_file);
    }
    fclose(findex);

    sprintf(commit_file, "%s/.msg", commit_dir);
    write_string_to_file(commit_file, msg);

    write_string_to_file(".bear_git/.prev", commit_id);

    return 0;
}

void print_commit(char *commit_id)
{
    if (strcmp(commit_id, "0000000000000000000000000000000000000000") == 0)
    {
        return;
    }

    char msg[MSG_SIZE];
    char file_name[FILENAME_SIZE];

    // get msg content of current commit_id
    sprintf(file_name, ".bear_git/%s/.msg", commit_id);
    read_string_from_file(file_name, msg, MSG_SIZE);

    // fprintf current commit(id and msg)
    fprintf(stdout, "commit %s\n", commit_id);
    fprintf(stdout, "    %s\n\n", msg);

    // get next commit id and call print_commit() -- recursive
    sprintf(file_name, ".bear_git/%s/.prev", commit_id);
    read_string_from_file(file_name, commit_id, COMMIT_ID_SIZE);
    print_commit(commit_id);
}

int bear_git_log()
{
    char commit_id[COMMIT_ID_SIZE];

    read_string_from_file(".bear_git/.prev", commit_id, COMMIT_ID_SIZE);

    if (strcmp(commit_id, "0000000000000000000000000000000000000000") == 0)
    {
        fprintf(stderr, "ERROR: There are no commits!");
        return 1;
    }
    fprintf(stdout, "\n");
    print_commit(commit_id);
    return 0;
}

// ---------------------------------
// HOMEWORK2
// ---------------------------------

// This adds a check to bear_git_commit that ensures we are on the HEAD of a branch.
int bear_git_commit(const char *msg)
{
    char current_branch[BRANCHNAME_SIZE];
    read_string_from_file(".beargit/.current_branch", current_branch, BRANCHNAME_SIZE);

    if (strlen(current_branch) == 0)
    {
        fprintf(stderr, "ERROR: Need to be on the HEAD of a branch to commit\n");
        return 1;
    }

    return bear_git_commit_hw1(msg);
}

const char *digits = "61c";

void next_commit_id(char *commit_id)
{
    char current_branch[BRANCHNAME_SIZE];
    read_string_from_file(".bear_git/.current_branch", current_branch, BRANCHNAME_SIZE);

    // The first COMMIT_ID_BRANCH_BYTES=10 characters of the commit ID will
    // be used to encode the current branch number. This is necessary to avoid
    // duplicated IDs in different branches, as they can have the same predecessor
    // (so next_commit_id has to depend on something else).
    int n = get_branch_number(current_branch);
    for (int i = 0; i < COMMIT_ID_BRANCH_BYTES; i++)
    {
        // This translate the branch number into base 3 and
        // substitutes 0,1,2 for '6', '1', 'c'
        commit_id[i] = digits[n % 3];
        n /= 3;
    }

    // Use next_commit_id to fill in the rest of the commit ID.
    next_commit_id_hw1(commit_id + COMMIT_ID_BRANCH_BYTES);
}

// This helper function returns the branch number of a specific branch, or
// return -1 if the branch does not exist.
int get_branch_number(const char *branch_name)
{
    FILE *fbranches = fopen(".bear_git/.branches", "r");

    int branch_index = -1;
    int counter = 0;
    char line[FILENAME_SIZE];
    while (fgets(line, sizeof(line), fbranches))
    {
        strtok(line, "\n");
        if (strcmp(line, branch_name) == 0)
        {
            branch_index = counter;
        }
        counter++;
    }

    fclose(fbranches);
    return branch_index;
}

/**
 * bear_git_branch
 */
int bear_git_branch()
{
    FILE *fbranches = fopen(".bear_git/branches", "r");

    char branch[BRANCHNAME_SIZE];
    char current_branch[BRANCHNAME_SIZE];

    read_string_from_file(".bear_git/.current_branch", current_branch, BRANCHNAME_SIZE);
    strtok(current_branch, "\n");

    while (fgets(branch, sizeof(branch), fbranches))
    {
        strtok(branch, "\n");
        if (strcmp(branch, current_branch) == 0)
        {
            fprintf(stdout, "* %s\n", branch);
        }
        else
        {
            fprintf(stdout, "  %s\n", branch);
        }
    }

    fclose(fbranches);

    return 0;
}

/**
 * brear_git_checkout
 */
int checkout_commit(const char *commit_id)
{
    return 0;
}

int is_it_a_commit_id(const char *commit_id)
{
    return 1;
}

int bear_git_checkout(const char *arg, int new_branch)
{
    // Get the current branch
    char current_branch[BRANCHNAME_SIZE];
    read_string_from_file(".bear_git/.current_branch", current_branch, BRANCHNAME_SIZE);

    // If not detached, update the current branch by storing the current HEAD into that branch's file...
    // Even we cancel later, this is still ok.
    if (strlen(current_branch))
    {
        char current_branch_file[BRANCHNAME_SIZE + 50];
        sprintf(current_branch_file, ".bear_git/.branch_%s", arg);
    }
}