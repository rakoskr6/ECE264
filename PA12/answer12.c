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
	
	if ((str[index] > '9') || (str[index] < '0') && (str[index] != ' '))
			{
				return 0; // random characters start string, return 0
			}
			
	for (index = 0; index < strlen(str); index++)
	{
		if (str[index] != ' ')
		{
			if ((str[index] > '9') || (str[index] < '0'))
			{
				return FinalNumber; // random characters in string, return final number
			}
			tempint = str[index] - '0'; // current value as int
			FinalNumber += powl(10,place)*tempint; // Add to uint128 with place value factor
			place--; // decrement place value
		}
	}
	
	return FinalNumber;
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
