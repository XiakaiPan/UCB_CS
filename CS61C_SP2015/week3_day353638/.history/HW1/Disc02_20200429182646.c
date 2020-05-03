// Disc02.c
/**
 * 1 C Management
 */
// 1. Memory Section(Code, Static data, Heap, Stack)
#define C 2
const int val = 16;
char arr[] = "foo";
void foo(int arg)
{
    char *str = (char *)malloc(C * val);
}
