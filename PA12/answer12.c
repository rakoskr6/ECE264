#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "answer12.h"

uint128 alphaTou128(const char * str) // code from PA02
{
	int index = 0; // Index to itterate through array
	int Negative = 0; // 0 if positive, 1 if negative
	uint128 Number = 0; // The number that is returned
	uint128 Place = 1; // The place value of the leftmost digit
	
	while(str[index] != '\0')
	{
		index++;
	}
	
	for (; index>= 0; index--) // Runs until end of string
	{
		if (str [index] == '-') // If a '-' is in the string, the number is negative
		{
			Negative = 1;
		}
		

		if (str[index] == '0' || str[index] == '1' || str[index] == '2' || str[index] == '3' || str[index] == '4' || str[index] == '5' || str[index] == '6' || str[index] == '7' || str[index] == '8' || str[index] == '9') 
		{
			// Multiply the previous number by place and add the new number to the 1's place.
			// Also subtract by ASCII value '0' since str[index] - '0' will be the number of str[index].
			Number = Number + Place * (str[index] - '0');
			Place = Place * 10; // Increment the place of the number by a factor of 10
			//printf("%li\n",Place);
		}
	}

	if (Negative == 1) 
	{
		Number = 0; // unsigned, so make number 0
	}
	
	return Number;	
}
	

char * u128ToString(uint128 value) // ensure string can be added big to lower index, Temp should only 
{
	int index = 0, length = 0, Temp = 0;
	char *String;
	uint128 value2;
	value2 = value;
	if (value2 == 0)
	{
		length = 1; // if intitially 0, length is 1
	}
	while(value2 > 0)
	{
		length++;
		value2 = value2 / 10;
	}
	String = malloc(sizeof(char) * (length + 1)); // plus one for null
	length--; // since arrays start at 0
	
	for (index = 0; index <= length; index++)
	{
		Temp = value % 10; // gets lowest value
		String[length - index] = '0' + Temp; // stores in string
		//printf("String[%i] = %c\n",length-index,String[length-index]);
		value = value / 10; // decrements place value of uint128
	}
	String[length + 1] = '\0'; // null terminated

	return String;
}

int primalityTestParallel(uint128 value, int n_threads)
{//Test if 'value' is prime.
	uint128 index = 2, max;
    if ((value % 2 == 0) && (value != 2))
    {
       return 0;
    }
    max = sqrt(value);
    for (index = 1; index <= max; index++) 
    {
		if ((value % ((2 * index) + 1) == 0) && ((2*index+1) != value))
		{
			return 0;
		}
    }	
    return 1;

}
