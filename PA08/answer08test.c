#include "answer08.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	printf("\e[1;1H\e[2J"); // clears screen
	
	//const char Str[50] = "Hello World!";
	//const char Str2[50] = "Goodnight World";
	//printf("The string is %s\n\n",Str);
	
	List *Ptr = List_createNode("Goodbye");
	Ptr->next = List_createNode("Hello");
	Ptr->next->next = List_createNode("Zolo");
	List *Ptr2 = List_createNode("Audios");
	Ptr2->next = List_createNode("Hola");
	Ptr2->next->next = List_createNode("Yolo");
	printf("The pointer to list one is %p\n",Ptr);
	printf("The string in list one %s\n",Ptr->str);
	printf("The string in list two is %s\n",Ptr2->str);
	printf("The pointer to list two is %p\n",Ptr2);
	
	printf("The length of the list is %i\n",List_length(Ptr));
	
	List *Merge = List_merge(Ptr, Ptr2, strcmp);
	
	printf("The merged list is: ");
	while (Merge != NULL)
	{
		printf("%s ",Merge->str);
		Merge = Merge->next;
	}
	printf("\n");

	List_destroy(Ptr);
	
	
	return EXIT_SUCCESS;
}
