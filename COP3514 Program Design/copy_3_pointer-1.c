/*
copy_3_pointer.c
This program allows a user to create any size array and inputs values into it.
Then it takes the initial [0] position value and every 3rd after that to create a new array
This program differs because it uses pointer arithmitic rather that calling 
Davin Hill
*/

#include <stdio.h>

//void function that computes array2
void decimate_by3(int *a1, int n, int *a2)
{

	int *i;
	int *x = a2;

	//This loop helps to copy every third element in the input array and copy it to the output array
	for (i = a1; i < a1 + n; i += 3, x++)
	{
		//Value in the input array is assigned to the output array
		*x = *i;
	}
}

int main(void)
{
	int userInputArraySize;
	int i = 0;
	int secondArraySize;

	//Printing out promt to ask user to enter length of array
	printf("Enter the length of the input array: ");

	//Collects user input
	scanf("%d", &userInputArraySize);

	//This is to show output on ./try_copy
	printf("%d\n", userInputArraySize);

	//Create array and size
	int firstArray[userInputArraySize];

	//Get 2nd arrat size by adding 2 and dividing that by 3
	secondArraySize = ((userInputArraySize + 2) / 3);

	//Create 2nd array
	int secondArray[secondArraySize];

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

	//Function deicimate_by3 called
	decimate_by3(firstArray, userInputArraySize, secondArray);


	//This is to help output look nice in MobaXterm
	printf("\nOutput array: ");

	//For loop to print out the new array and values
	for (i = 0; i<(secondArraySize); i++)
	{
		printf("%d ", secondArray[i]);
	}

	//This is to help output look nice in MobaXterm, pushing the ------- line down
	printf("\n");

	return 0;
}


