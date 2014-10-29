#include "answer08.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int (*compar)(const char *, const char*);

List * List_createNode(const char * str)
{
	List *ptr = malloc(sizeof(List));
	ptr->str = strdup(str); // Copy string and create space for it
	ptr->next = NULL;
	return ptr;
}

void List_destroy(List * list)
{
	while (list != NULL)
	{
		List *ptr = list->next;
		free(list->str);
		free(list);
		list = ptr;
	}
}

int List_length(List * list)
{
	int index = 0;
	if (list == NULL) // returns 0 if null
		return index;
	for (index = 1; list->next != NULL; index++)
	{
		list = list->next;
	}
	return index;
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
	List *ptr = NULL;
	while((lhs->next != NULL) && (rhs->next != NULL))
	{
		if (compar > 0) // positive then first is bigger
		{
			List_merge(lhs->next,rhs,strcmp((lhs->next)->str,rhs->str));
		}
		else if (compar < 0) // negative then second is bigger
		{
			ptr = lhs;
			lhs = rhs;
			lhs->next = ptr;
			List_merge(lhs->next,rhs->next,strcmp((lhs->next)->str,(rhs->next)->str));
		}
		else // Then equal
		{
			ptr = lhs->next;
			lhs->next = rhs;
			// ???
			List_merge(lhs->next,rhs->next,strcmp((lhs->next)->str,(rhs->next)->str));
		}
		
	}
	return lhs;
}


