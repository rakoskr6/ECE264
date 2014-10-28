#include "answer08.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

List * List_createNode(const char * str)
{
	List *ptr = malloc(sizeof(List));
	ptr->str = malloc(strlen(str) * sizeof(char)); // create space for string
	ptr->next = NULL;
	return ptr;
}

void List_destroy(List * list)
{
	if (list != NULL)
	{
		free(list->str);
		free(list);
	}
}

int List_length(List * list)
{
	int index ;
	for (index = 0; list->next != NULL; index++)
	{
		list = list->next;
	}
	return index;
}

	
	
	
	
	return EXIT_SUCCESS;
}
