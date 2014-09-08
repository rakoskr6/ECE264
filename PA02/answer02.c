#include <stdio.h>
#include "answer02.h"
size_t my_strlen(const char * str) ;

int main (void)
{
char * str = "hello!";
printf("%i\n",my_countchar(str, 'k'));
return 0;
}


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
