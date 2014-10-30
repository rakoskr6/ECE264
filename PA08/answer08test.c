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
	printf("The pointer to list two is %p\n\n",Ptr2);
	
	printf("The length of the list is %i\n\n",List_length(Ptr));
	
	List *Merge = List_merge(Ptr, Ptr2, strcmp);
	
	printf("The merged list is: ");
	while (Merge != NULL)
	{
		printf("%s ",Merge->str);
		Merge = Merge->next;
	}
	printf("\n\n");

	List_destroy(Ptr);
	
	
	
	List *Ptr3 = List_createNode("Goodbye");
	Ptr3->next = List_createNode("Hello");
	Ptr3->next->next = List_createNode("Zolo");
	Ptr3->next->next->next = List_createNode("Audios");
	Ptr3->next->next->next->next = List_createNode("Hola");
	Ptr3->next->next->next->next->next = List_createNode("Yolo");
	
	Ptr3 = List_sort(Ptr3, strcmp);
	printf("The sorted list is: ");
	while (Ptr3 != NULL)
	{
		printf("%s ",Ptr3->str);
		Ptr3 = Ptr3->next;
	}
	printf("\n");
	List_destroy(Ptr3);
	
	return EXIT_SUCCESS;
}
