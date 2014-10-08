#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer05.h"

int main(void)
{
	//char *String[50] = "hello";
	int Num = 2;
	
	while (Num - 1)
	{
		printf("Enter a number to partition: ");
		scanf("%i",&Num);
		printf("\n");
		partitionAll(Num);
	}
	Num = 2;
	while (Num - 1)
	{
		printf("Enter a number to partition increasing: ");
		scanf("%i",&Num);
		printf("\n");
		partitionIncreasing(Num);
	}
	
	Num = 2;
	while (Num - 1)
	{
		printf("Enter a number to partition decreasing: ");
		scanf("%i",&Num);
		printf("\n");
		partitionDecreasing(Num);
	}

	Num = 2;
	while (Num - 1)
	{
		printf("Enter a number to partition even: ");
		scanf("%i",&Num);
		printf("\n");
		partitionEven(Num);
	}		


	Num = 2;
	while (Num - 1)
	{
		printf("Enter a number to partition Odd: ");
		scanf("%i",&Num);
		printf("\n");
		partitionOdd(Num);
	}		

	Num = 2;
	while (Num - 1)
	{
		printf("Enter a number to partition even/Odd: ");
		scanf("%i",&Num);
		printf("\n");
		partitionOddAndEven(Num);
	}		

	Num = 2;
	while (Num - 1)
	{
		printf("Enter a number to partition Prime: ");
		scanf("%i",&Num);
		printf("\n");
		partitionPrime(Num);
	}		
		
	return (EXIT_SUCCESS);
}
