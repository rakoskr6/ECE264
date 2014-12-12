#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "answer12.h"

uint128 alphaTou128(const char * str)
{
	int index = 0; // Index to itterate through array
	int Negative = 0; // 0 if positive, 1 if negative
	uint128 Number = 0; // The number that is returned
	long int Place = 1; // The place value of the leftmost digit
	
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
		}
	}
	// Makes number negative if the negative flag is 1
	if (Negative == 1) 
	{
		Number = 0;
	}
	
	return Number;
	
}
	
//uint128 alphaTou128(const char * str)
//{//Convert the initial portion of C-string 'str' to an unsigned 128-bit integer
	//int index = 0, tempint, place = 0;
	//uint128 FinalNumber = 0;
	
	//while(str[index] == ' ') // ignores leading whitespace
	//{
		//index++;
	//}
	
	//while (((str[index] > '9') || (str[index] < '0')))
	//{
		//place++;
	//}
	////place = strlen(str) - 1; // minus one since place should end at 0
	
	//if (((str[index] > '9') || (str[index] < '0')))
			//{
				//return 0; // random characters start string, return 0
			//}
			
	//for (index = 0; index < strlen(str); index++)
	//{
		//if ((str[index] > '9') || (str[index] < '0'))
		//{
			//return FinalNumber; // random characters in string, return final number
		//}
		//tempint = str[index] - '0'; // current value as int
		//printf("%i %Le   ",tempint,powl(10,place));
		//FinalNumber += powl(10,place)*tempint; // Add to uint128 with place value factor
		//printf("%c\n",str[index]);
		//place--; // decrement place value
	//}
	
	//return FinalNumber;
//}

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
