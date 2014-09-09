#include <stdio.h>
#include "answer02.h"


// Must point to valid string, cannot be a null string
size_t my_strlen(const char * str)
{
	int index = 0; // Index that iterates through string  
	
	for (index = 0; str[index] != '\0'; index++)
	{
		// For loop runs until end of string is found. No need
		// for anything in the loop since function returns index.
	}
	return index;
}

// Must point to valid strings, cannot be null strings
int my_countchar(const char * str, char ch)
{
	int index = 0, Occurances = 0;

// Iterates through string counting all occurances of ch 
	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == ch)
		{
			Occurances++;	
		}
	}
	
	return Occurances;
}

// Must point to valid string/character, cannot be null
char * my_strchr(const char * str, int ch)
{
	int index = -1; // Starts at -1 since index will be incremented before using and
					// needs to be 0 to start at string beginning. (iterate left to right)
	do
	{
		index++;
		
		// Returns string index as soon as ch is found
		if (str[index] == ch)
		{
			return (char *) &str[index];
		}
		
	
	} while (str[index] != '\0');

	return NULL;
}

// Must point to valid string/character, cannot be null
char * my_strrchr(const char * str, int ch)
{
	int index = -1; // Starts at -1 since index will be incremented before
					// using and needs to be 0 to start at string beginning.
	
	for (index = 0; str[index] != '\0'; index++)
	{
		// For loop runs until end of string is found.
	}
	
	index++; // Incremented since index will be deincrmented before using
			 // and it needs to start at the end of the string (iterate right to left)
	
	do
	{
		index--;
		
// Returns string index as soon as ch is found
		if (str[index] == ch)
		{
			return (char *) &str[index];
		}
		

	} while (index > 0);

	return NULL;
}


// Still needs fixing
// Must point to valid strings, cannot be null strings
char * my_strstr(const char * haystack, const char * needle)
{
	int HaySize = 0, NeedSize = 0; // To store haystack and needle size
	int HayIndex = 0, NeedIndex = 0; // Indicies to iterate through haystack and needle
	int CharEqual = 0; // How many characters are equal between haystack and needle

// Following for loops detect string sizes
	for (HaySize = 0; haystack[HaySize] != '\0'; HaySize++)
	{
		// For loop runs until end of string is found.
	}
	for (NeedSize = 0; needle[NeedSize] != '\0'; NeedSize++)
	{
		// For loop runs until end of string is found.
	}

		
	for (HayIndex = 0; HayIndex <= HaySize; HayIndex++)
	{
		
		if (needle[NeedIndex] == haystack[HayIndex])
		{
			CharEqual++; // To show how many characters are equal
			NeedIndex++; // To view the next value of needle
			
			if (CharEqual == NeedSize - 1) // true if needle is in haystack
			{
				return ((char *) &haystack[HayIndex]) - NeedSize + 1; //explan minus
			}
		}
		else
		{
			// Resets values if needle isn't in haystack (at this point)
			NeedIndex = 0;
			CharEqual = 0;
		}
	}
	
	return  NULL;
	
}

// Still needs fixing
// Must point to valid strings, cannot be null strings
char * my_strcpy(char * dest, const char * src)
{
	int index = 0;
	
	do 
	{
		// For loop runs until end of string is found.
		dest[index] = src[index];
		index++;
	} while (src[index] != '\0');
	
	return dest;
}

// Still needs fixing
char * my_strcat(char * dest, const char * src)
{
	int index = -1;
	

	
	do 
	{

		index++;
		dest[index] = src[index];
		
	} while (src[index] != '\0');
	
	
	return dest;
}


int my_isspace(int ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v')
	{
		return 1;
	}

	return 0;
	
}


int my_atoi(const char * str)
{
	int index = 0; // Index to itterate through array
	int Negative = 0; // 0 if positive, 1 if negative
	int Number = 0; // The number that is returned
	int Place = 1; // The place value of the leftmost digit
	
	for (index = 0; str[index] != '\0'; index++) // Runs until end of string
	{
		if (str [index] == '-') // If a '-' is in the string, the number is negative
		{
			Negative = 1;
		}
		
		if (str[index] == '0' || str[index] == '1' || str[index] == '2' || str[index] == '3' || str[index] == '4' || str[index] == '5' || str[index] == '6' || str[index] == '7' || str[index] == '8' || str[index] == '9') 
		{
			Number = Number * Place + (str[index] - '0');
			Place = Place * 10;
		}
	
	
	}
	
// Makes number negative if the negative flag is 1
	if (Negative == 1) 
	{
		Number = -Number;
	}
	
	return Number;
}






