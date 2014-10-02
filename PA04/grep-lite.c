#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{

int ind = 1; // skip 0, which is the program path
//FILE *FilePtr;
//char Charct;

// First loop checks to see if help flag is present
for( ; ind < argc; ++ind) 
{
	   // If --help is passed, show help and end
	if(strcmp(argv[ind], "--help") == 0) // Shows help if true
	{
		printf("<help-message>\n"
				"Usage: grep-lite [OPTION]... PATTERN\n"
				"Search for PATTERN in standard input. PATTERN is a\n"
				"string. grep-lite will search standard input line by\n"
				"line, and (by default) print out those lines which\n"
				"contain pattern as a substring.\n\n"
				"  -v, --invert-match     print non-matching lines\n"
				"  -n, --line-number      print line numbers with output\n"
				"  -q, --quiet            suppress all output\n");
		return EXIT_SUCCESS;
	}
}

// Second loop checks to ensure no bogus arguments
for(ind = 1; ind < argc; ++ind) 
{		
	if (((fopen(argv[ind],"r")) == NULL) && ((strcmp(argv[ind],"-")) != 0 )) //update
	{
		fprintf(stderr,"cat cannot open %s\n",argv[ind]);
		return EXIT_FAILURE;
	}		
}
	
// Third loop executes grep-lite arguments


	return EXIT_SUCCESS;
}
