#include "answer08.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List * List_createNode(const char * str)
{
	List *ptr = malloc(sizeof(List));
	ptr->str = strdup(str); // Copy string and create space for it
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

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
	while((lhs->next != NULL) && (rhs->next != NULL)
	{
		if ((strcmp(lhs->str,rhs->str)) > 0) // positive then first is bigger
		{
			lhs
		}
		else if ((strcmp(lhs->str,rhs->str)) < 0) // negative then second is bigger
		{
			
		}
		else // Then equal
		{
			
		}
	}
	
}
