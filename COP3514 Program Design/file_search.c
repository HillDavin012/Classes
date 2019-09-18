/*
file_search.c
This program reads a input file while also creating a final file
The input file is read for its strings, then those strings are sent to function shift to be modified
After bring modified they get evaluated if it matches any from original starting at i (k=i)
If a match is found the strings get written to the final_file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 100
#define STR_LEN 1000

void shift(char *message, int shift_amount, char *shift_message)

{

	for (; *message != '\0'; message++)
	{

		if (*message >= 'a' && *message <= 'z')

			*shift_message++ = (*message - 'a' + shift_amount) % 26 + 'a';

		else if (*message >= 'A' && *message <= 'Z')

			*shift_message++ = (*message - 'A' + shift_amount) % 26 + 'A';

		else

			*shift_message++ = *message;
	}

	*shift_message = '\0';

}

int main()
{
	int i, j, k;
	int count = 1;
	int num_words = 0;

	char modified[WORD_LEN];
	char original[STR_LEN][WORD_LEN];
	char input_file[WORD_LEN];
	char final_file[WORD_LEN];

	printf("Enter the file name: ");

	//Take user input
	scanf("%s", input_file);
	printf("%s\n", input_file);

	//Creating new file file.txt.sft
	sprintf(final_file, "%s.sft", input_file);
	printf("Output file name: %s", final_file);

	//Create pointers to read from origianl file to final
	FILE *read = fopen(input_file, "r");
	FILE *write = fopen(final_file, "w");

	//Checking if file could be read if not return 0 and exit
	if (read == NULL)
	{
		printf("Unable to open\n");

		return 0;
	}

	//Reading data and saving it in original [num_words]
	while (fscanf(read, "%s", original[num_words]) != EOF)
	{
		//Counting the words
		num_words++;
	}

	//This for loop is only to be executed for the number of strings in the file
	for (i = 0; i < num_words; i++)
	{
		//This for loop is to go through all possible modified shifts
		for (j = 1; j < 26; j++)
		{
			//Each j calls a new shift to get modified and come back for testing
			shift(original[i], j, modified);

			//k = i keeps it from going over ones that have already been tested
			for (k = i; k < num_words; k++)
			{
				if (strcmp(original[k], modified) == 0)
				{
					//If they are, they get written to file
					fprintf(write, "\n%d\t%s\n\t%s\n", count, original[i], modified);
					count++;
					break;
				}
			}
		}
	}

	//Closing to prevent warnings and notes
	fclose(read);
	fclose(write);

	return 0;
}