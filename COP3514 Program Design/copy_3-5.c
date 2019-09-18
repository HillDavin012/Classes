/*
copy_3.c
This program allows a user to create any size array and inputs values into it.
Then it takes the initial [0] position value and every 3rd after that to create a new array
Davin Hill
*/

#include <stdio.h>

void decimate_by3(int a1[], int n, int a2[]);

int main(void)
{
	int userInputArraySize = 0;
	int i = 0;
	int secondArraySize = 0;

	//Printing out promt to ask user to enter length of array
	printf("Enter the length of the input array: ");

	//Collects user input
	scanf("%d", &userInputArraySize);

	//This is to show output on ./try_copy
	printf("%d\n", userInputArraySize);

	//Create array and size
	int firstArray[userInputArraySize];

	//Get 2nd arrat size by adding 2 and dividing that by 3
	secondArraySize = ((userInputArraySize+2)/3);

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
	
	//function called
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

//void function that computes array2
void decimate_by3(int a1[], int n, int a2[])
{

	int i = 0;
	int array2Counter = 0;

	//For loop that goes through first array and selects every 3rd position to be put into 2nd array
	for (i = 0; i < (n); i += 3)
	{
		//Assigns value into 2nd array
		a2[array2Counter] = a1[i];

		//Goes to next array location++
		array2Counter++;
	}
}

