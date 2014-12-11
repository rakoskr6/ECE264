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
	int place = 38, Temp, index, FirstValue = 0;//, indexS = 0;
	char *String;
	long double Decimal;
	
	for (index = 38; index >= 0; index--)
	{
		Temp = value / powl(10,place); // gets integer at hightest to lowest place value
		Decimal = value / powl(10,place);
		value = (Decimal - Temp) * powl(10,place--);
		printf("%i\n",Temp);
		
		if (Temp != 0 || FirstValue == 1) // Ignores leading zeros
		{
			if(!FirstValue)//Just found beginning of number, must malloc string
			{
				String = malloc(sizeof(char) * (index + 1)); // Plus one for null character
				//indexS = index + 1;
				String[index + 1] = '\0';
			}
			FirstValue = 1;
			String[index] = '0' + Temp;
		}
		
	}
	//String[indexS] = '\0';
	return String;
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
