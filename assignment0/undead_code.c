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

int* getOldPC(int);

void segment_fault_handler(int signum)
{
	printf("I am slain!\n");

	//Find the location of instruction pointer/Program counter with respect to function args on stack
	//This is the address of Instruction pointer which points to some code in kernel signal return handler...
	//We need to change the value at this address to point to desired instruction in out code space.
	int* PC1 = (((char*)&signum) - sizeof(char*));

	//Create dummy function call to get the address of program counter in our code which points to a code segment in this function.
	//We can move this value to the desired instuction we want by adding an offset.
	int* PC2 = getOldPC(7);

	// Calculate the number of bytes to jump to get to the desired instruction.
	int bytes_to_jump = 103;

	// Overwrite the program counter value.
	*PC1 = (char*)*PC2 + bytes_to_jump;
}

int* getOldPC(int dummy)
{
	int *PC = (((char*)&dummy) - sizeof(char*));
	return PC;
}

int main()
{
	int r2 = 0;

	signal(SIGSEGV, segment_fault_handler);

	r2 = *( (int *) 0 );
	
	printf("I live again!\n");

	return 0;
}
