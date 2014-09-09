#include <stdio.h>
#include "answer02.h"

/*
int main (void)
{
char * str = "Hello World";
printf("%p\n",my_strstr(str, "ello"));
return 0;
}
*/

// Must point to valid string, cannot be a null string
size_t my_strlen(const char * str) //size_t is unsigned integer
{
	int index = 0;
	for (index = 0; str[index] != '\0'; index++)
	{
		// For loop runs until end of string is found.
		// No need for anything in the loop since the 
		// the function returns index.
	}
	return index;
}

// Must point to valid string, cannot be a null string
int my_countchar(const char * str, char ch)
{
	int index = 0, Occurances = 0;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == ch)
		{
			Occurances++;	
		}
	}
	
	return Occurances;
}

// Must point to valid string, cannot be a null string
char * my_strchr(const char * str, int ch)
{
	int index = -1; // explain
	do
	{
		index++;
		
		if (str[index] == ch)
		{
			return (char *) &str[index];
		}
		
	
	} while (str[index] != '\0');

	return NULL;
}

char * my_strrchr(const char * str, int ch)
{
	int index = -1;
	
	
	
	for (index = 0; str[index] != '\0'; index++)
	{
		// For loop runs until end of string is found.
	}
	index++; // explain
	do
	{
		index--;
		if (str[index] == ch)
		{
			return (char *) &str[index];
		}
		

	} while (index > 0);

	return NULL;
}

char * my_strstr(const char * haystack, const char * needle)
{
	int HaySize = 0, NeedSize = 0;
	int HayIndex = 0, NeedIndex = 0;
	int CharEqual = 0;

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
			CharEqual++;
			NeedIndex++;
			
			if (CharEqual == NeedSize - 1)
			{
				return ((char *) &haystack[HayIndex]) - NeedSize + 1; //explan minus
			}
		}
		else
		{
			NeedIndex = 0;
			CharEqual = 0;
		}
	}
	
	return (char *) haystack;
	
}


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

char * my_strcat(char * dest, const char * src)
{
	int index = 0;
	
		for (index = 0; src[index] != '\0'; index++)
	{
		// For loop runs until end of string is found.
	}
	
	do 
	{
		// For loop runs until end of string is found.
		dest[index] = src[index];
		index++;
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
	return 0;
}







