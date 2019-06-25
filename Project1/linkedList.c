
#include "linkedList.h"

//#include <stdlib.h>
#include <string.h>
void push(node** head, char* s, size_t n)
{
	if (*head == NULL) {
		*head = malloc(sizeof(node));
		if (*head == NULL) {
			printf("unsuccessful Allocation");
			exit(1);
		}
		(*head)->str = malloc((n+1) * sizeof(char));
		if ((*head)->str == NULL) {
			printf("unsuccessful Allocation");
			exit(1);
		}
		strcpy_s((*head)->str, n + 1, s);
		(*head)->next = NULL;
		
	}
	else {
		node* cure = *head;
		while (cure->next) {
			cure = cure->next;
		}

		cure->next = malloc(sizeof(node));
		if (cure->next == NULL) {
			printf("unsuccessful Allocation");
			exit(1);
		}
		cure->next->str = malloc(n * sizeof(char));
		if (cure->next->str == NULL) {
			printf("unsuccessful Allocation");
			exit(1);
		}
		strcpy_s(cure->next->str,n+1, s);
		cure->next->next = NULL;
	}
	

}

void printList(node* head)
{
	if (head == NULL)
		return;
	node* cure = head;
 	while (cure) {
		printf("%s", cure->str);
		cure = cure->next;
	}

}

void freeList(node* head)
{
	node* tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}
