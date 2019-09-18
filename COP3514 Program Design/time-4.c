//time.c
//This program changes military 24 hour time to 12 hour time.
//Davin Hill

#include <stdio.h>

int main(void)
{
	int hour = 0;
	int mins = 0;

	printf("Please enter a military time (0000 to 2359): ");

	//Accepting 2 digits for hours and 2 for mins
	scanf("%2d%2d", &hour, &mins);

	//Making sure input was not over 23
	if (hour>23)
	{
		printf("Invalid input.");
	}
	else
	{
		//Making sure mins don't go over 59
		if (mins>59)
		{
			printf("Invalid input.");
		}
		else
		{
			//Catching PM
			if (hour>11)
			{
				//Just catching 12pm
				if (hour<13)
				{
					printf("The regular time is %d:%02d pm.", hour, mins);
				}
				else
				{
					hour = hour - 12;
					printf("The regular time is %d:%02d pm.", hour, mins);
				}
			}
			//Catching AM	
			else
			{
				//Turning 0000 into 12AM
				if (hour == 0)
				{
					hour = 12;
					printf("The regular time is %d:%02d am.", hour, mins);
				}
				//Catching the rest of the AM 0100-1159
				else
				{
					printf("The regular time is %d:%02d am.", hour, mins);
				}
			}
		}
	}
return 0;
}
