#include <stdio.h>
#include <stdlib.h> 
#include "help.h"
#include "linkedList.h"


char* scan_line(char* line)
{
	int ch; //as getchar() returns `int`

	if ((line = malloc(sizeof(char))) == NULL) //allocating memory
	{
		//checking if allocation was successful or not
		printf("unsuccessful allocation");
		exit(1);
	}

	line[0] = '\0';

	for (int index = 0; ((ch = getchar()) != '\n') && (ch != EOF); index++)
	{
		if ((line = realloc(line, (index + 2) * sizeof(char))) == NULL)
		{
			//checking if reallocation was successful or not
			printf("unsuccessful reallocation");
			exit(1);
		}

		line[index] = (char)ch; //type casting `int` to `char`
		line[index + 1] = '\0'; //inserting null character at the end
	}

	return line;
}
int main(void)
{
	node* head = NULL;
	char* a = NULL;
	size_t i = 0;
	do
	{
		i = insert_line(&a);
		if (i>0) {
			push(&head, a, i);
		}
		free(a); 
		a = NULL;

	} while (i>0);
	
	printList(head);


	//char* a = NULL;

	//int i = insert_line(&a); //function call to scan the line

	//printf("%s\n", a); //printing the scanned line

	//free(a); //don't forget to free the malloc'd pointer
	freeList(head);
	system("pause");
	return 0;
}


