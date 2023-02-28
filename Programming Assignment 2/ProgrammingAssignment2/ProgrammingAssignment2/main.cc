#include <stdio.h>
//Sample main.cc
//Prototypes from cloops.cc are required so that
//the compiler knows parameters and return
//types for those functions at compile time.
//YOU MUST HAVE THE FOLLOWING IN MAIN!!!!
void printRectangle(int, int);
void printTriangle(int);
void printFormat(int, int, int);
//USE OTHER VALUES OF WIDTH AND HEIGHT FOR TESTING.
//TEST YOUR FUNCTIONS THOROUGHLY.
//MAKE SURE YOUR FUNCTIONS WORK CORRECTLY
//FOR ODD VALUES (0, 1, -4, etc...)
int main()
{
	printRectangle(20, 12);
	printTriangle(14);
	printFormat(30, 0, 0);
}
