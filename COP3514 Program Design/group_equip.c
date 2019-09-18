/*
group_equip.c
This program creates linked lists
The program takes user inputs to create a list of workout equipment
The program takes the users input and checks for repeats and can also update current equipment
Davin Hill
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 30
struct equipment{
	char type[NAME_LEN+1];
	char description[NAME_LEN+1];
	int quantity;
	struct equipment *next;
};


struct equipment *append_to_list(struct equipment *list);
void update(struct equipment *list);
void printList(struct equipment *list);
void clearList(struct equipment *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct equipment *e_list = NULL;  
  printf("Operation Code: a for appending to the list, u for updating an equipment"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
	printf("%c\n", code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': e_list = append_to_list(e_list);
                break;
      case 'u': update(e_list);
                break;
      case 'p': printList(e_list);
                break;
      case 'q': clearList(e_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

//This function adds struct items to the list
struct equipment *append_to_list(struct equipment *list)
{
	//Checking for available memory and assining to pointer p
	struct equipment*  p = (struct equipment*)malloc(sizeof(struct equipment));

	//Starting location pointer at beggining of list
	struct equipment* location = list;

	//Setting next location NULL
	p->next = NULL;

	//Recieving information to be processed
	printf("Enter type: ");
	read_line(p->type, NAME_LEN);
	printf("\n");

	//Recieving information to be processed
	printf("Enter discription: ");
	read_line(p->description, NAME_LEN);
	printf("\n");

	//Recieving information to be processed
	printf("Enter quantity: ");
	scanf("%d", &p -> quantity);
	printf("%d\n", p->quantity);

	//If list is empty or not found set p->next=NULL
	if (!list) 
	{
		list = p;
		p->next = NULL;
		return list;
	}
	else 
	{
		//While pointer location is not null
		while (location)
		{
			//Checking for repeated inputs
			if ((strcmp(location->type, p->type) == 0) && (strcmp(location->description, p->description) == 0))
			{
				printf("Equipment already exists.\n");
				return list;
			}
			//Break when next location is NULL
			if (!location->next)
			{
				break;
			}
			//Current equipment gets put onto end of list
			location = location->next;

		}
		//The next new item will be put at the end of list
		location->next = p;
		//Next location will be NULL
		p->next = NULL;
		return list;
	}
}

//This function updates current items in the list
void update(struct equipment *list)
{
	//Making sure list is created
	if (!list) 
	{
		printf("Equipment list not found");
		return;
	}

	int add;

	//Checking for memory space and assigning it to pointer p
	struct equipment *p = (struct equipment*)malloc(sizeof(struct equipment));

	//Creating pointer and beggining at the start of list
	struct equipment *location = list;

	//Recieving information to be processed
	printf("Enter equipment type: ");
	read_line(p->type, NAME_LEN);
	printf("\n");

	//Recieving information to be processed
	printf("Enter equipment discription: ");
	read_line(p->description, NAME_LEN);
	printf("\n");

	//Recieving information to be processed
	printf("Enter equipment type: ");
	scanf("%d", &add);

	//While location is not null keep looking
	while (location) 
	{
		//Looking for the updated equipement the user requested
		if ((strcmp(location->type, p->type) == 0) && (strcmp(location->description, p->description) == 0))
		{
			//Once found, do update
			location->quantity = location->quantity + add;
			printf("%s, new quantity: %d\n", location->type, location->quantity);
			free(p);
			return;
		}
		//Go to next location
		location = location->next;
	}



}

//This function prints the list at the users request
void printList(struct equipment *list)
{
	//Creating pointer p to point to list
	struct equipment *p = list;

	printf("\n%s\t%s\t%s\n", "Equipment", "Description", "Quantity");

	//While p is not NULL print
	while (p) 
	{
		printf("%s\t %s\t\t %d\n", p->type, p->description, p->quantity);
		p = p -> next;
	}

  

}

//This function depoints to items on the list and frees memory
void clearList(struct equipment *list)
{

	struct equipment *p = list;
	struct equipment *temp;

	//Goes through list and frees items
	while (!p) 
	{
		temp = p->next;
		free(p);
		p = temp;
	}

}

//This was part of the original file given, I only edited it slightly to show more output
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  printf("%c", ch);
  str[i++] = ch;
  while ((ch = getchar()) != '\n') 
  {
	  printf("%c", ch);
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
