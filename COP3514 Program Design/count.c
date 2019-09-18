/*
count.c
This program allows a user to input a sentence and then the program counts numbers, letters, and special characters.
Main function creates pointers then calls the void function count()
The pointers "num_letters, num_digits, num_special" points to "letters, number, special"
Then main function reads the pointers then prints them out to show values in a different function
Davin Hill
*/
#include <stdio.h>

//The count function recieves 3 pointers, and runs through the sentence detecting numbers, letters, and special characters
void count(int *num_letters, int *num_digits, int *num_special)
{
	char ch;
	int letters = 0;
	int number = 0;
	int special = 0;

		printf("Enter the sentence: ");

	//While loop to go through all the characters the user inputs into sentence
	while((ch=getchar())!='\n')
	{
		printf("%c", ch);
		//Checking for any lowercase letters
		if(ch>='a' && ch<='z')
		{
			//Increasing amount of letters if true
			letters++;
		}
		//Checking for any uppercase letters
		if(ch>='A' && ch<='Z')
        {
			//Increasing amount of letters if true
            letters++;
        }
		//Checking for any numbers
        if(ch>='0' && ch<='9')
        {
			//Increasing numbers int  if true
            number++;
        }
		//Switch stament to check for specific special characters
        switch(ch)
        {
            case '~':
                special++;
                break;

            case '!':
                special++;
                break;

            case '@':
                special++;
                break;

            case ',':
                special++;
                break;

            case ':':
                special++;
                break;

            case ';':
                special++;
                break;

            case '%':
                special++;
                break;

            case '&':
                special++;
                break;

            case '*':
                special++;
                break;

            case '_':
                special++;
                break;

            case '+':
                special++;
                break;
        }


	}
	
	printf("\n");

	//Assigning the pointers the address of the values for the amount of letters, numbers, and special characters
	*num_letters = letters;
	*num_digits = number;
	*num_special = special;

}

int main(void)
{
	//Creating pointer variables
	int num_letters, num_digits, num_special;

	//Calling count function with pointers
	count(&num_letters, &num_digits, &num_special);

	//Printing out result of count with pointers showing values
	printf("There are %d letters, %d digits, and %d special characters in the sentence.\n", num_letters, num_digits, num_special);

	return 0;
}
