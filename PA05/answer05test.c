#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer05.h"

int main(void)
{
	//char *String[50] = "hello";
	int Num = 1;
	
	while (Num)
	{
		printf("Enter a number to partition: ");
		scanf("%i",&Num);
		printf("\n");
		partitionAll(Num);
	}
		
	
	return (EXIT_SUCCESS);
}
