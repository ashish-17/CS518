// Author: John-Austen Francisco
// Date: 9 September 2015
//
// Preconditions: Appropriate C libraries
// Postconditions: Generates Segmentation Fault for
//                               signal handler self-hack

// Student name: Ashish Jindal (aj523)
// Ilab machine used: top.cs.rutgers.edu

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void segment_fault_handler(int signum)
{
	printf("I am slain!\n");

	//Find the location of instruction pointer/Program counter with respect to function args on stack
	int* eip = (((char*)&signum) - sizeof(char*));

	//Set the instuction pointer to the address of the next instruction in main()
	*eip = 0x8048447;
}


int main()
{
	int r2 = 0;

	signal(SIGSEGV, segment_fault_handler);

	r2 = *( (int *) 0 );
	
	printf("I live again!\n");

	return 0;
}
