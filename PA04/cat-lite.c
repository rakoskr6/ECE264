#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{

int ind = 1; // skip 0, which is the program path
//FILE *FilePtr;

// First loop checks to see if help flag is present
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

// Second loop checks to ensure all files exist (and not think - is a file)
for(ind = 1; ind < argc; ++ind) 
{		
	if (((fopen(argv[ind],"r")) == NULL) && ((strcmp(argv[ind],"-")) != 0 ))
	{
		fprintf(stderr,"cat cannot open %s\n",argv[ind]);
		return EXIT_FAILURE;
	}		
}
	
// Third loop opens and prints files or uses stdin
for(ind = 1; ind < argc; ++ind) 
{		
	//FilePtr = fopen(argv[ind],"r");
	
	if(strcmp(argv[ind], "-") == 0) // What to do if -
	{
		
		
	}

	else
	{
		
		
	}
		
}

	return EXIT_SUCCESS;
}
