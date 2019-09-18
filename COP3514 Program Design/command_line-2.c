/*
command_line.c
This program collects the ints in the command line and puts them into an array
Then it sends the array to the function three_numbers
Three_numbers function detects if there is a repeated number
If there is a repeated number then x will = 1 and pointer *number = number that repeated
Davin Hill
*/

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{

    int p;
    int i;
    int commandLine[argc];
    int number;
    int result;
    
	//Creating array from command line
    for(i = 1; i < argc; i++)
    {
        p = atoi(argv[i]);
		commandLine[i-1] = p;
    }

    //Sending to function three_numbers to be evaluated
    result = three_numbers(commandLine, argc, &number);

	//Detecting result from function
	if (result == 1)
	{
		printf("\nOutput: There are three numbers with the same value in the command line: %d\n", number);
	}
	else
	{
		printf("\nOutput: The command line does not contain three numbers with the same value.\n");
	}

	return 0;
}