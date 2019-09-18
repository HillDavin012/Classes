//force.c
//Calculates force on an object with friction over time
//Davin Hill

#include <stdio.h>
#include <math.h>

int main (void)
{
	double time = 0.0;
	double force = 0.0;

	//printing time and force headers
	printf("Time\tForce\n");

	//Starting loop, starting at 0 and increasing by .5 and stopping at 10
	for(time = 0; time < 10.5; time = time + .5)
	{
		//Cathing when time is below 3.5 to use first equation
		if(time<3.5)
		{
			force = 20.0;
			printf("\n%.1f\t%.1f\n", time, force);
		}
		//Otherwise check when time increases above 3.5 but below 6.5
		else
		{
			//Catching time before 6.5
			if(time<6.5)
			{
				force = 4*(time+2);
				printf("\n%.1f\t%.1f\n", time, force);
			}
			//Else time is above 3.5 and 6.5 and the last equation should be used
			else
			{
				force = 4*(pow(time, 2)+time*2);
				printf("\n%.1f\t%.1f\n", time, force);	
			}	
		}
	}
	return 0;
}
