/*
convert.c
This program allows a user to create any size array and inputs values into it.
Then it takes the first array and uses pointer arithmetic to convert the first array
Then assigns the new value to a new pointer array
Davin Hill
*/

#include <stdio.h>


//void function that computes array2
void convert(int *a1, int n, int *a2)
{

	int *i;
	int *x = a2;

	//For loop to assign pointer values incurmentally
	for (i = a1; i < a1 + n; i++, x++)
	{
		//Assigns value into 2nd array
		*x = ((*i + 6) % 10);
	}
}

int main(void)
{
	int userInputArraySize;
	int i = 0;

	//Printing out promt to ask user to enter length of array
	printf("Enter the length of the input array: ");

	//Collects user input
	scanf("%d", &userInputArraySize);

	//This is to show output on ./try_copy
	printf("%d\n", userInputArraySize);

	//Create array and size
	int firstArray[userInputArraySize];

	//Create 2nd array
	int secondArray[userInputArraySize];

	//Ask for elements in 1st array
	printf("Enter the array elements: ");

	//For loop takes user input to be put into array
	for (i = 0; i<userInputArraySize; i++)
	{
		//Taking the numbers to be input into numArray array
		scanf("%d", &firstArray[i]);
		//This is to help output look nice in MobaXterm, printing out array input
		printf("%d ", firstArray[i]);
	}

	//Function convert called
	convert(firstArray, userInputArraySize, secondArray);


	//This is to help output look nice in MobaXterm
	printf("\nOutput array: ");

	//For loop to print out the new array and values
	for (i = 0; i<(userInputArraySize); i++)
	{
		printf("%d ", secondArray[i]);
	}

	//This is to help output look nice in MobaXterm, pushing the ------- line down
	printf("\n");

	return 0;
}