//The following is a sample main.cc. Modify it to test your program.
//Make sure to test thoroughly. All the pieces below have to be included.
#include <stdio.h>
//These are called prototypes and they have to be here.
//Any function in arrays.cc that you also call from main must be listed here. 
//For now, make sure you include the following 3 lines in main.cc
void print3dPoint(int);
int swapBytes(int);
int countGroups(int);
//This function will run when you run your program from the command line.
int main(void)
{
	int answer;
	//For the print functions you will have to verify that the correct
	//output was printed yourself.
	printf("Verify the following manually\n");
	print3dPoint(155);
	print3dPoint(0x1234567A);
	print3dPoint(0x0203807C);
	//Test swapBytes. Note that this only prints tests
	//that fail.
	//Put an else in if you want to see tests that pass also.
	//swapBytes test 1
	answer = swapBytes(0xA345D239);
	if (answer != 0x45A339D2)
	{
		printf("Failed swapBytes test 1\n");
		printf("Expected Hex: %X\t", 0x45A339D2);
		printf("Found Hex: %X\n", answer);
	}
	//Put more swapBytes tests here.
	//Test countGroups. Note that this only prints tests that fail.
	//Put an else in if you want to see tests that pass also.
	//countGroups test 1
	answer = countGroups(0x8000000F);
	if (answer != 2)
	{
		printf("Failed countGroups test 1\n");
		printf("Expected: %d\t", 2);
		printf("Found: %d\n", answer);
	}
	else
		printf("Correct\n");
	//Put more countGroups tests here
	return 0;
}