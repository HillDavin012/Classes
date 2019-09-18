/*
words.c
This program collects capital letters from a user input and places them into an array to be printed later
The program takes what the user inputs and sends it to read line function
The read line function takes the input puts it into an array and then sends it to the function pick
the function pick only pics the capitals letters and puts them into another array and then prints out all of them.
Davin Hill
*/

#include <stdio.h>
#define STR_LEN 1000

//Encode function puts both arrays together one by one into 1 array
void pick(char *s1)
{
	int p;
	char final_Array[STR_LEN];
	char *t;
	char temp;
	t = final_Array;
	int count = 0;
	char *x = s1;

	//While loop that stops when the pointers become NULL
	while (*x != '\0')
	{
		if (*x >= 'A' && *x <= 'Z')
		{
			//Hold a potential capital letter
			temp = *x;
			//Next location in the array (checking next letter)
			x++;

			//Checking next letter if its capital
			if (*x >= 'A' && *x <= 'Z')
			{
				//Insert capital letter into array from temp
				*t = temp;
				count += 2;
				//Move to next empty location so new capital can be stored
				t++;
				//Insert next capital letter
				*t = *x;
				//Move to next empty location so new capital can be stored
				t++;
				//Next location in the array (checking next letter)
				x++;

				//Checking next letter if its capital
				if (*x >= 'A' && *x <= 'Z')
				{
					//Insert next capital letter
					*t = *x;
					count+=2;
					//Move to next empty location so new capital can be stored
					t++;
					//Next location in the array (checking next letter)
					x++;

					//Checking next letter if its capital
					if (*x >= 'A' && *x <= 'Z')
					{
						//Insert next capital letter
						*t = *x;
						count +=2;
						//Move to next empty location so new capital can be stored
						t++;
						//Next location in the array (checking next letter)
						x++;
						*t = 't';
						t++;
					}
					else
					{
						//Just placing a 't' to break up words for later
						*t = 't';
						//Move to next empty location so new capital can be stored
						t++;
						//Next location in the array (checking next letter)
						x++;
					}
				}
				else
				{
					//Just placing a 't' to break up words for later
					*t = 't';
					//Move to next empty location so new capital can be stored
					t++;
					//Next location in the array
					x++;
				}
			}
			else
			{
				//Next location in the array
				x++;
			}

		}
		else
		{
			//Next location in the array
			x++;
		}
	}

	printf("\n");

	//Print out the results
	for (p = 0; p < count; p++)
	{
		if (final_Array[p] == 't')
		{
			printf("\n");
		}
		else
		{
			printf("%c", final_Array[p]);
		}
	}
}
//Read_line catches all the letters and splits them up into 2 different arrays
int read_line(int *str, int n)
{
	int ch, i = 0;
	int count1 = 0;
	char array_one[STR_LEN];

	//While loop catching input from main function
	while ((ch = getchar()) != '\n')
	{
		if (i < n)
		{
			printf("%c", ch);
			//Pointer to input
			*str++ = ch;

			//Assigning values to arrayone(project said only encode for arithmatic)
			array_one[count1] = ch;
			count1++;

			//Increase to next letter
			i++;
		}
	}

	//Setting last value NULL for next function to catch
	array_one[count1] = '\0';

	//Stops collecting string
	*str = '\0';

	//Calls encode function and sends the 2 arrays
	pick(array_one);

	return i;
}

int main()
{
	int userInputWord[STR_LEN];

	//Printing out promt to ask user to input a word
	printf("Input: ");

	//Collects user input
	scanf("%d", userInputWord);
	read_line(userInputWord, STR_LEN);

	return 0;
}