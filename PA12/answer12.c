#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "answer12.h"

uint128 alphaTou128(const char * str)
{//Convert the initial portion of C-string 'str' to an unsigned 128-bit integer
	int index = 0, tempint, place = 0;
	uint128 FinalNumber = 0;
	place = strlen(str) - 1; // minus one since place should end at 0
	
	for (index = 0; index < strlen(str); index++)
	{
		if (str[index] != ' ')
		{
			tempint = str[index] - '0'; // current value as int
			FinalNumber += powl(10,place)*tempint; // Add to uint128 with place value factor
			place--; // decrement place value
		}
	}
	
	return FinalNumber;
}

char * u128ToString(uint128 value) // ensure string can be added big to lower index, Temp should only 
{
	int index =0, length = 0, Temp = 0;
	char *String;
	uint128 value2;
	value2 = value;
	
	while(value2 > 0)
	{
		length++;
		value2 = value2 / 10;
	}
	String = malloc(sizeof(char) * (length + 1));
	
	
	for (index = 0; index <= length; index++)
	{
		if (value > 0)
		{
			Temp = value % 10; // gets lowest value
			String[length - index] = '0' + Temp; // stores in string
			value = value / 10; // decrements place value of uint128
		}
	}
	String[length + 1] = '\0';

	return strdup(String);
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
