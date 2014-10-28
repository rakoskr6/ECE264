#include "answer08.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List * List_createNode(const char * str)
{
	List *ptr = malloc(sizeof(List));
	ptr->str = malloc(strlen(str) * sizeof(char));
	ptr->next = NULL;
	return ptr;
}

