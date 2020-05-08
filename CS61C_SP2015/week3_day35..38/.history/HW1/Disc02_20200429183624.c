// Disc02.c
/**
 * 1 C Management
 */
// 1. Memory Section(Code, Static data, Heap, Stack)
/**
 * Program’s address space contains	4 regions:
 * – stack:	local	variables	inside	
funcLons,	grows	downward		
– heap:	space	requested	for	
dynamic	data	via	malloc();	
resizes	dynamically,	grows	
upward	
– staLc	data:	variables	declared	
outside	funcLons,	does	not	grow	
or	shrink.	Loaded	when	program	
starts,	can	be	modified.	
– code:	loaded	when	program	
starts,	does	not	change
 */
#define C 2         // static data
const int val = 16; // static data
char arr[] = "foo"; // stack
void foo(int arg)   // arg:
{
    char *str = (char *)malloc(C * val);
    char *ptr = arr;
}