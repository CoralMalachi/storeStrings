#include <stdio.h>
#include <stdlib.h> 
#include "help.h"
#include "linkedList.h"



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


