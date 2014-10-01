#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{

int ind = 1; // skip 0, which is the program path
FILE *FilePtr;

for( ; ind < argc; ++ind) 
{
	   // If --help is passed, show help and end
	if(strcmp(argv[ind], "--help") == 0) // Shows help if true
	{
		printf("<help-message>\n"
				"Usage: cat-lite [--help] [FILE]...\n"
				"With no FILE, or when FILE is -, read standard input.\n");
		return EXIT_SUCCESS;
	}
}
	
for(ind = 1; ind < argc; ++ind) 
{		
	if(strcmp(argv[ind], "-") == 0) // Stdin if true
	{
		return EXIT_FAILURE;
	}
	else // open file
	{
		if ((FilePtr = fopen(argv[ind],'r')) == NULL)
		{
			
			return EXIT_FAILURE;
		}
		
	}
		
}
	return EXIT_FAILURE;
}
