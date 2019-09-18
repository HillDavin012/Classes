/*
encode.c
This program allows a user to input any size word.
Then it takes the word and sends it to get put into 2 different arrays
After it gets put into 2 different arrays it goes to encode function
Finally the encode function takes both arrays of words and combines them flipping the letters
from the original version
Davin Hill
*/

#include <stdio.h>
#define STR_LEN 1000

//Encode function puts both arrays together one by one into 1 array
void encode(char *s1, char *s2)
{
	int p;
	char final_Array[STR_LEN];
	char *t;
	t = final_Array;
	int count = 0;
	char *i = s1;
	char *x = s2;

	//While loop that stops when the pointers become NULL
	while (*x != '\0' || *i != '\0')
	{
		//This gives me a 1 or a 0 so I can tell if its even or not
		if ((count % 2) != 1)
		{
			//Checking if pointer *x is NULL
			if (*x == '\0')
			{
				//If *x is NULL fill in with *i so no space ie merging would = emgrni*g
				*t = *i;
				count++;
				break;
			}
			//Else continue assigning pointer arithmetic
			else
			{
				*t = *x;
				x++;
				t++;
				count++;
			}
		}
		else
		{
			//*i cannot be NULL so no need for if stament just assign pointer arithmetic
			*t = *i;
			i++;
			t++;
			count++;
		}
	}
	//Make it look nice on Xmoba
	printf("\nOutput: ");

	//Print out the results
	for (p = 0; p < count; p++)
	{
		printf("%c", final_Array[p]);
	}
}
//Read_line catches all the letters and splits them up into 2 different arrays
int read_line(int *str, int n)
{
	int ch, i = 0;
	int count1 = 0;
	int count2 = 0;
	char array_one[STR_LEN];
	char array_two[STR_LEN];

	//While loop catching input from main function
	while ((ch = getchar()) != '\n')
	{
		if (i < n)
		{
			//Pointer to input
			*str++ = ch;
			//Only catching even for arrayone and odd for arraytwo 
			if (i % 2 == 0)
			{
				//Assigning values to arrayone(project said only encode for arithmatic)
				array_one[count1] = ch;
				count1++;
			}
			else
			{
				//Assigning values to arraytwo(project said only encode for arithmatic)
				array_two[count2] = ch;
				count2++;
			}
			//Increase to next letter
			i++;
		}
	}

	//Setting last value NULL for next function to catch
	array_two[count2] = '\0';
	array_one[count1] = '\0';

	//Stops collecting string
	*str = '\0';
	
	//Calls encode function and sends the 2 arrays
	encode(array_one, array_two);

	return i;
}

int main()
{
	int userInputWord[STR_LEN];

	//Printing out promt to ask user to input a word
	printf("Enter a word: ");

	//Collects user input
	scanf("%d", userInputWord);
	read_line(userInputWord, STR_LEN);


	//This is to help output look nice in MobaXterm, pushing the ------- line down
	printf("\n");

	return 0;
}