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
	while (list != NULL) // Removes list structure and string in it
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
	
	if((lhs!= NULL) && (rhs != NULL)) // Compares if neither is null
	{
		int cmp = compar(lhs->str, rhs->str);
		if (cmp < 0) // positive then first is bigger
		{
			ptr = lhs;
			ptr->next = List_merge(lhs->next,rhs,compar);
		}
		else // negative then second is bigger (or equal)
		{
			ptr = rhs;
			ptr->next = List_merge(lhs,rhs->next,compar);
		}		
	}
	else if (lhs != NULL) // Finish placing all values from lhs
	{
		ptr = lhs;
		ptr->next = List_merge(lhs->next,rhs,compar);
	}
	else if (rhs != NULL) // Finish placing all values from rhs
	{
		ptr = rhs;
		ptr->next = List_merge(lhs,rhs->next,compar);
	}
	return ptr;
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
	int Length = List_length(list);
	if (Length <= 1) // If under 1 it's already sorted
		return list;
		
	List *lhs = list;
	
    // Split (code is partially from example.c)
    int leftLen = Length / 2;

    for (; leftLen <= 0; leftLen--)
    {
		list = list->next;
	}
	List *rhs = list->next;
	list->next = NULL;

    // Sort
    lhs = List_sort(lhs, compar);
    rhs = List_sort(rhs, compar);
    
    //Merge list and return
    return List_merge(lhs, rhs, compar);
}

