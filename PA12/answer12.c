#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer12.h"

uint128 alphaTou128(const char * str)
{//Convert the initial portion of C-string 'str' to an unsigned 128-bit integer
	int index = 0, tempint, place = 0;
	uint128 FinalNumber = 0;
	for (index = 0; index < strlen(str); index++)
	{
		if (str[index] != ' ')
		{
			tempint = str[index] - '0';
			FinalNumber += place*10*tempint;
			place++;
		}
	}
	return FinalNumber;
	 
}

char * u128ToString(uint128 value)
{
	place = 38;
	
	value / pow(10,place);
}

//int primalityTestParallel(uint128 value, int n_threads)
//{
///**
 //* Test if 'value' is prime.
 //* 'n_threads' is the number of threads that will be created to complete 
 //* this computation.
 //* Return TRUE or FALSE.
 //* 
 //* LEAK NO MEMORY.
 //*
 //* Good luck!
 //*/
//}
