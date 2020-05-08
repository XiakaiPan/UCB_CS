/* Disc02.c */
/**
 * Part 1: C Management
 */
// 1. Memory Section(Code, Static data, Heap, Stack)
/**
 * Program’s address space contains	4 regions:
 * – stack:	local variables	inside funcLons, grows downward		
 * – heap:  space requested for dynamic data via malloc(); 
 *   resizes dynamically, grows upward
 * – static	data: variables declared outside functions, does not grow	
 *   or shrink. Loaded when program starts,	can	be modified.
 * – code: loaded when program starts, does	not	change
 */
#include <stdlib.h>

#define C 2         // static data X ->Code
const int val = 16; // static data X ->Code
char arr[] = "foo"; // stack X ->static data
void foo(int arg)   // arg: stack
{
    char *str = (char *)malloc(C * val); // *str: heap; str: stack
    char *ptr = arr;                     // same as str
}
// 2. Wrong point
// 3. prepend and free in the LinkedList.
struct ll_node
{
    struct ll_node *next;
    int value;
};
// #include <stdlib.h>
free_ll(struct ll_node **list)
{
    if (*list)
    {
        free_ll(&(*list)->next);
        free(*list);
    }

    *list = NULL;
}

prepend(struct ll_node **list, int value)
{
    struct ll_node *item = (struct ll_node *)
        malloc(sizeof(struct ll_node));
    item->value = value;
    item->next = *list;
}