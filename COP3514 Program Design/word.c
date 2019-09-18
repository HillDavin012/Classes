//word.c
//This program takes user input and capitalizes the first letter or digit and adds "!" if there is less than 8 characters to make it 8 long.
//Davin Hill

#include <stdio.h>
#include <ctype.h>

int main()
{

	char ch = 0;
	int wordLength = 0;
	int addch = 0;

	printf("Enter the message: ");	

	//While loop to accept characters until enter
	while (ch != '\n')
	{
		//Reprinting what was typed corrected
		printf("%c", ch);

		//Cathing what was typed
		ch = getchar();

		//Catching the first time this loop is ran to chech the first character
		if(wordLength==0)
		{
			printf("Output: ");
			
			//Converting lower case letter to uppercase
			if (ch>='a' && ch<='z') 
			{
				ch = ch - 32;
			}
		
			//Converting any numbers to uppercase A
			if (ch>='0' && ch<='9' ) 
			{
				ch = 'A' ;
			}
		}

	//Increasing word length each time to check later to see how many characters there are
	wordLength++;	
		
	}
	
	//Catching correct length of characters
	if (wordLength<9) 
	{
		//For loop to add "!" 
		for (addch = wordLength--; addch<9; addch++)
		{
			printf("!");
		}
	}

	return 0;
}
