// beargit.c
#include <stdio.h>
#include <string.h>

#include "unistd.h"
#include <sys/stat.h>

#include "beargit.h"
#include "util.h"

/**
 * beargit init
 */
int beargit_init(void)
{
    fs_mkdir(".beargit"); // Create beargit derectory.

    // Create new file .beargit/.index
    FILE *findex = fopen(".beargit/.index", "w");
    fclose(findex);

    // Create new file .beargit/.branches and include master branch.
    FILE *fbranches = fopen(".beargit/.branches", "w");
    fprintf(fbranches, "%s\n", "master");
    fclose(fbranches);

    //Create .beargit/.prev and .beargit/.current_branch files.
    write_string_to_file(".beargit/,prev", "0000000000000000000000000000000000000000");
    write_string_to_file(".beargit/.current_branch", "master");

    return 0;
}

/**
 * beargit add <filename>
 * Append filename to list in .beargit/.index if it isn't in there yet.
 * 
 * Possible errors (to stderr): 
 * >> ERROR: File <filename> already added
 * 
 * Output (to stdout):
 * - None if successful
 */

int beargit_add(const char *filename)
{
    FILE *findex = fopen(".beargit/.index", "r");
    FILE *fnewindex = fopen(".beargit/.newindex", "w");

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
            fs_rm(".beargit/.newindex");
            return 3;
        }

        fprintf(fnewindex, "%s\n", line);
    }

    fprintf(fnewindex, "%s\n", filename);
    fclose(findex);
    fclose(fnewindex);

    fs_mv(".beargit/.fnewindex", ".beargit/.index");

    return 0;
}

/**
 * beargit_status: read the file .beargit/.index and
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
int beargit_status()
{
    FILE *findex = fopen(".beargit/.index", "r");
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
 * beargit rm <filename>
 */
int beargit_rm(const char *filename)
{
    FILE *findex = fopen(".beargit/.index", "r");
    FILE *fnewindex = fopen(".beargit/.newindex", "w");

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
        fs_rm(".beargit/.newindex");
        return 1;
    }

    fs_mv(".beargit/newindex", ".beargit/.index");

    return 0;
}

/**
 * beargit commit -m <msg>
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

int beargit_commit_hw1(char *msg)
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
    read_string_from_file(".beargit/.prev", commit_id, COMMIT_ID_SIZE);
    next_commit_id(commit_id);

    /**
     * Generate a new directory .beargit/<newid> and copy
     * .beargit/.index, .beargit/.prev, and all tracked files
     * into new directory.
     */

    // Generate new directory: .beargit/<new_commit_id>
    char commit_dir[FILENAME_SIZE];
    sprintf(commit_dir, ".beargit/%s", commit_id);
    fs_mkdir(commit_id);

    /* copy .beargit/.index and .beargit/.prev */
    char commit_file[FILENAME_SIZE];
    // Copy .beargit/.index to new .beargit/<newid>/.index
    sprintf(commit_file, "%s/.index", commit_dir);
    fs_cp(".beargit/.index", commit_file);

    // Copy .beargit/.prev to .beargit/<newid>/.prev
    sprintf(commit_file, "%s/.prev", commit_dir);
    fs_cp(".beargit/.prev", commit_file);

    /* Copy other tracked files indexed by .beargit/.index */
    FILE *findex = fopen(".beargit/.index", "r");
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

    write_string_to_file(".beargit/.prev", commit_id);

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
    sprintf(file_name, ".beargit/%s/.msg", commit_id);
    read_string_from_file(file_name, msg, MSG_SIZE);

    // fprintf current commit(id and msg)
    fprintf(stdout, "commit %s\n", commit_id);
    fprintf(stdout, "    %s\n\n", msg);

    // get next commit id and call print_commit() -- recursive
    sprintf(file_name, ".beargit/%s/.prev", commit_id);
    read_string_from_file(file_name, commit_id, COMMIT_ID_SIZE);
    print_commit(commit_id);
}

int beargit_log()
{
    char commit_id[COMMIT_ID_SIZE];

    read_string_from_file(".beargit/.prev", commit_id, COMMIT_ID_SIZE);

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

// This adds a check to beargit_commit that ensures we are on the HEAD of a branch.
int beargit_commit(const char *msg)
{
    char current_branch[BRANCHNAME_SIZE];
    read_string_from_file(".beargit/.current_branch", current_branch, BRANCHNAME_SIZE);

    if (strlen(current_branch) == 0)
    {
        fprintf(stderr, "ERROR: Need to be on the HEAD of a branch to commit\n");
        return 1;
    }

    return beargit_commit_hw1(msg);
}

const char *digits = "61c";

void next_commit_id(char *commit_id)
{
    char current_branch[BRANCHNAME_SIZE];
    read_string_from_file(".beargit/.current_branch", current_branch, BRANCHNAME_SIZE);

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
    FILE *fbranches = fopen(".beargit/.branches", "r");

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
 * beargit_branch
 */
int beargit_branch()
{
    FILE *fbranches = fopen(".beargit/branches", "r");

    char branch[BRANCHNAME_SIZE];
    char current_branch[BRANCHNAME_SIZE];

    read_string_from_file(".beargit/.current_branch", current_branch, BRANCHNAME_SIZE);
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
    write_string_to_file(".beargit/.prev", commit_id);

    if (strcmp(commit_id, "0000000000000000000000000000000000000000") == 0)
    {
        write_string_to_file(".beargit/.index", "");
        return 0;
    }

    FILE *findex = fopen(".beargit/.index", "r");
    char line[FILENAME_SIZE];

    while (fgets(line, sizeof(line), findex))
    {
        strtok(line, "\n");
        fs_rm(line);
    }

    fclose(findex);

    char tmp1[FILENAME_SIZE];
    sprintf(tmp1, ".beargit/%s/.index", commit_id);
    fs_cp(tmp1, ".beargit/.index");

    char tmp2[FILENAME_SIZE];
    findex = fopen(".beargit/.index", "r");
    while (fgets(line, sizeof(line), findex))
    {
        strtok(line, "\n");
        sprintf(tmp1, ".beargit/%s/%s", commit_id, line);
        sprintf(tmp2, "./%s", line);
        fs_cp(tmp2, tmp2);
    }

    return 0;
}

int is_it_a_commit_id(const char *commit_id)
{
    if (strlen(commit_id) == 40)
    {
        for (int i = 0; commit_id[i] != '\0'; i++)
        {
            if (commit_id[i] != '6' && commit_id[i] != '1' && commit_id[i] != 'c')
            {
                return 0;
            }
        }
    }
    return 1;
}

int beargit_checkout(const char *arg, int new_branch)
{
    // Get the current branch
    char current_branch[BRANCHNAME_SIZE];
    read_string_from_file(".beargit/.current_branch", current_branch, BRANCHNAME_SIZE); //1

    // If not detached, update the current branch by storing the current HEAD into that branch's file...
    // Even we cancel later, this is still ok.
    if (!strlen(current_branch))
    {
        char current_branch_file[BRANCHNAME_SIZE + 50];
        sprintf(current_branch_file, ".beargit/.branch_%s", current_branch);
        fs_cp(".beargit/.prev", current_branch_file); //???
    }

    // Check whether the argument is a commit ID. If yes, we just stay in detached mode
    // without actually having to change into any other branch.
    if (is_it_a_commit_id(arg))
    {
        char commit_dir[FILENAME_SIZE] = ".beargit/";
        strcat(commit_dir, arg);
        if (!fs_check_dir_exists(commit_dir))
        {
            fprintf(stderr, "ERROR: Commit %s does not exist\n", arg);
            return 1;
        }

        // Set the current branch to none (i.e. detached).
        write_string_to_file(".beargit/current_branch", "");

        return checkout_commit(arg);
    }

    // Just a better name, since we now know the argument is a branch name.
    const char *branch_name = arg;

    // Read branches file (giving us the HEAD commit id for that branch.)
    int branch_exists = (get_branch_number(branch_name) >= 0);

    // Check for errors.
    if (!(!branch_exists || !new_branch))
    {
        fprintf(stderr, "ERROR: A branch named %s already exists\n", branch_name);
        return 1;
    }
    else if (!branch_exists && new_branch)
    {
        fprintf(stderr, "ERROR: No branch %s exists\n", branch_name);
        return 1;
    }

    // File for the branch we are changing into.
    char *branch_file = ".beargit/.branch_";
    strcat(branch_file, branch_name);

    // Update the branch file if new branch is created (now it can't go wrong anymore)
    if (new_branch)
    {
        FILE *fbranches = fopen(".beargit/.branches", "a");
        fprintf(fbranches, "%s\n", branch_name);
        fclose(fbranches);
        fs_cp(".beargit/.prev", branch_file);
    }

    write_string_to_file(".beargit/.current_branch", branch_name);

    // Read the head commit id of this branch.
    char branch_head_commit_id[COMMIT_ID_SIZE];
    read_string_from_file(branch_file, branch_head_commit_id, COMMIT_ID_SIZE);

    // Check out the actual commit.
    return checkout_commit(branch_head_commit_id);
}
