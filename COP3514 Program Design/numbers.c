/*
numbers.c
This program allows a user to create any size array and inputs values into it.
Then it sends it to three_numbers function to be evaluated to see if three values in it match
Finally results (0 or 1) are returned to main function to print out results
The points "number" keeps address of the int that repeats 3 times
Davin Hill
*/
#include <stdio.h>

//The function three_numbers recieves an array, its size, and a pointer
int three_numbers(int a[], int n, int *number)
{
	int i, j;
	int x = 0;
	int count = 0;

	//Need 2 for loops to compare [0] to [1] then [0] to [2] and so on...
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{

			//Comparing to see if there is a repeat
			if (a[i] == a[j])
			{
				//Increasing the count if a repeat is detected
				count++;
				
				//Catches if count gets to 3 then sets x to 1 because function detected a int repeated 3 times
				if (count > 2)
				{
					//Since a int has repeated 3 times this function will return a (x = 1)
					x = 1;
					//Assigning pointer to address of the value that is repeating
					*number = a[j];
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
	}
	//Will return a 0 or 1 if the function detects a int repeats 3 times
	return x;
}

int main(void)
{
	int userInputArraySize = 0, i, number, result;

	//Printing out promt to ask user to enter length of array
	printf("Enter the length of the array: ");

	//Collects user input
	scanf("%d", &userInputArraySize);

	//This is to show output on ./try_copy
	printf("%d\n", userInputArraySize);

	//Create array and size
	int firstArray[userInputArraySize];

	//Ask for elements in 1st array
	printf("Enter the array elements: ");

	//For loop takes user input to be put into array
	for (i = 0; i < userInputArraySize; i++)
	{
		//Taking the numbers to be input into numArray array
		scanf("%d", &firstArray[i]);
		printf("%d ", firstArray[i]);
	}

	//Calling and returning result of function into "result" 
	result = three_numbers(firstArray, userInputArraySize, &number);

	//Detecting result from function
	if (result == 1)
	{
		printf("\nOutput: There are three numbers with the same value: %d\n", number);
	}
	else
	{
		printf("\nOutput: The array does not contain three numbers with the same value.\n");
	}

	return 0;
}