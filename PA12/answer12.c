#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>
#include "answer12.h"

typedef struct ThreadInfo{ // info to pass to thread
	uint128 Max;
	uint128 Min;
	uint128 Value;
	int ReturnVal;
}ThreadInfo;

void *checkPrime(void *Info)
{
	uint128 max = ((ThreadInfo*) Info)->Max;
	uint128 index = ((ThreadInfo*) Info)->Min;
	uint128 value = ((ThreadInfo*) Info)->Value;
	
	for (index = 1; index <= (1+max/2); index++) 
    {
		if ((value % ((2 * index) + 1) == 0) && ((2*index+1) != value))//over 2
		{
			((ThreadInfo*)Info)->ReturnVal = ((ThreadInfo*)Info)->ReturnVal * 0;
			return NULL;
		}
    }	
    ((ThreadInfo*)Info)->ReturnVal = ((ThreadInfo*)Info)->ReturnVal * 1;
    return NULL;
}

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
	uint128 max, Interval;
	int index = 0;
	pthread_t thread[n_threads];
	int FinalReturn = 1;
	
    if ((value % 2 == 0) && (value != 2)) // initial check to ensure not 2
    {
       return 0;
    }
    max = sqrt(value);
    ThreadInfo Info[n_threads];
    
    Interval = max / n_threads;
    
    
    
    for (index = 0; index < n_threads; index++) // Page 348
    {
		Info[index].Max = (Interval * (index+1))+1;
		Info[index].Min = Interval * index;
		Info[index].ReturnVal = 1;
		Info[index].Value = value;
		pthread_create(&thread[index],NULL,checkPrime,(void *) &Info[index]);
		
	}
	
	for (index = 0; index < n_threads; index++)
	{
		pthread_join(thread[index],NULL);
		
		FinalReturn = Info[index].ReturnVal * FinalReturn;
	}
    
	return FinalReturn;

}
