// Disc02.c
/**
 * 1 C Management
 */
// 1. Memory Section(Code, Static data, Heap, Stack)
/**
 * 
 */
#define C 2         // static data
const int val = 16; // static data
char arr[] = "foo"; // stack
void foo(int arg)   // arg:
{
    char *str = (char *)malloc(C * val);
    char *ptr = arr;
}
