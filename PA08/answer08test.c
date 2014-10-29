#include "answer08.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	printf("\e[1;1H\e[2J"); // clears screen
	
	const char Str[50] = "Hello World!";
	printf("The string is %s\n\n",Str);
	
	List *Ptr = List_createNode(Str);
	printf("The pointer to the list is %p\n",Ptr);
	printf("The string in the list is %s\n",Ptr->str);
	printf("The next pointer is %p\n",Ptr->next);
	
	printf("The length of the list is %i\n",List_length(Ptr));
	
	List_destroy(Ptr);
	
	
	return EXIT_SUCCESS;
}
