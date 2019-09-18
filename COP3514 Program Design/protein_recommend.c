/*
protein_recommend.c
This program takes protein.txt and takes the information from its file
The program creates an output file with ".rcd" ending
The information from origianl file.txt gets sent to selection_sort to be sorted deccendly
Once the information is sorted, the top 5 with over 49 reviews only get written to output file
Davin Hill
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 100

//Here I create the struct for the proteins
struct protein
{
	char brand_name[STR_LEN];
	int inStock;
	int units_Sold;
	double customerReview;
	int num_reviews;
};

//This is supposed to sort in deccending order
void selection_sort(struct protein protein_powders[], int n);

//Added command line prompt
int main(int argc, char *argv[])
{

	struct protein protein_powders[STR_LEN];

	int i;
	int t = 0;
	int num_protein = 0;

	char input_file[STR_LEN];
	char final_file[STR_LEN];

	//Copy string from command line and assign to varible input_file
	strcpy(input_file, argv[1]);
	sprintf(final_file, "%s.rcd", input_file);

	FILE *read = fopen(input_file, "r");
	FILE *write = fopen(final_file, "w");

	//Making sure file can get be opened and can read it
	if (read == NULL)
	{
		printf("Unable to open\n");

		return 0;
	}
	//Else start while loop to collect everything off of the file
	else
	{
		while (fscanf(read, "%d %d %lf %d %[^\n]s ", &protein_powders[num_protein].inStock, &protein_powders[num_protein].units_Sold, &protein_powders[num_protein].customerReview, &protein_powders[num_protein].num_reviews, protein_powders[num_protein].brand_name) != EOF)
		{
			//This counts the amount of protein powders their are
			num_protein++;
		}
	}

	//Takes info and sends it to sort function
	selection_sort(protein_powders, num_protein);

	//Starting print out for 
	fprintf(write, "In sorted order:\r\n");
	printf("In sorted order: \n");
	for (i = 0; i < num_protein; i++)
	{
		if(protein_powders[i].inStock > 0)
		{

			//If statment catching num_reviews and times its executed only 5 times
			if (protein_powders[i].num_reviews > 49 && t < 5)
			{
				//Writing information to file
				fprintf(write, "%d %d %.2lf %d %s\r\n", protein_powders[i].inStock, protein_powders[i].units_Sold, protein_powders[i].customerReview, protein_powders[i].num_reviews, protein_powders[i].brand_name);
				//This is for output on mobax
				printf("%d %d %.2lf %d %s\n", protein_powders[i].inStock, protein_powders[i].units_Sold, protein_powders[i].customerReview, protein_powders[i].num_reviews, protein_powders[i].brand_name);

				t++;
			}
		}
		else 
		{
			continue;
		}
	}

	//Close read/write
	fclose(read);
	fclose(write);

	return 0;

}

//Selection sort was given, but it was modified to decrement order from highest to least 
void selection_sort(struct protein protein_powders[], int n)
{
	int i, largest = 0;
	struct protein temp;


	if (n == 1)
		return;

	for (i = 1; i < n; i++)
	{
		if (protein_powders[i].customerReview < protein_powders[largest].customerReview)
		{
			largest = i;
		}
	}

	if (largest < n - 1)
	{
		temp = protein_powders[n - 1];
		protein_powders[n - 1] = protein_powders[largest];
		protein_powders[largest] = temp;
	}

	selection_sort(protein_powders, n - 1);
}