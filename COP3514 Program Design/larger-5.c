/*
larger.c
This program allows a user to create any size array and inputs values into it.
Then it calculates the first [0] verse [arraysize-1] and replaces the value with the greater.
It keeps going until it reaches the middle of the array and ends keeping the odd value.
Davin Hill
*/

#include <stdio.h>

int main(void)
{

	int userInputArraySize = 0;
	int i = 0;
	int arrayLocation = 0;

	//Printing out promt to ask user to enter length of array
	printf("Enter the length of the input array: ");

	//Collects user input
	scanf("%d", &userInputArraySize);

	//This is to show output on ./try_larger
	printf("%d\n", userInputArraySize);

	//Create array and size
	int numArray[userInputArraySize];
	
	//Used to count down from last position in array
	arrayLocation = userInputArraySize - 1;

	//Printing out promt to ask user to input array elements
	printf("Enter the array elements: ");

	//For loop takes user input to be put into array
	for (i = 0; i<userInputArraySize; i++)
	{
		//Taking the numbers to be input into numArray array
		scanf("%d", &numArray[i]);
		//This is to help output look nice in MobaXterm, printing out array input
		printf("%d ", numArray[i]);
	}

	//For loop to go through the entire loop to be evaluated by if statments
	for (i = 0; i < userInputArraySize; i++)
	{
		//Only performing this check as to keep odd number of values in array
		if (i < arrayLocation)
		{
			//If the first position value of the array is less than the array location that is being checked
			if (numArray[i] < numArray[arrayLocation])
			{
				//Position i of array that is less than checked position value is replaced
				numArray[i] = numArray[arrayLocation];
				//Decreasing array output
				userInputArraySize--;
			}
			else
			{
				//Decreasing array output
				userInputArraySize--;
			}
		}

		//Counting down from last position in array
		arrayLocation--;
	}

	//This is to help output look nice in MobaXterm
	printf("\nOutput array: ");

	//For loop to print out the new array and values
	for (i = 0; i < userInputArraySize; i++)
	{
		printf("%d ", numArray[i]);
	}
	
	//This is to help output look nice in MobaXterm, pushing the ------- line down
	printf("\n");	

	return 0;
}