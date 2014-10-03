#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{

int ind = 1; // skip 0, which is the program path
FILE *FilePtr;
char Charct = 'a';

// First loop checks to see if help flag is present
for( ; ind < argc; ++ind) 
{
	// If --help is passed, show help and end
	if(strcmp(argv[ind], "--help") == 0) // Shows help if true
	{
		printf(	"Usage: cat-lite [--help] [FILE]...\n"
				"With no FILE, or when FILE is -, read standard input.\n\n"			   
				"Examples:\n"
					"cat-lite README   Print the file README to standard output.\n"
					"cat-lite f - g    Print f's contents, then standard input,\n" 
									 "then g's contents.\n"
					"cat-lite          Copy standard input to standard output.\n"
				);
		return EXIT_SUCCESS;
	}
}

// Second loop checks to ensure all files exist (and ignore -)
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
	FilePtr = fopen(argv[ind],"r");
	
	if(strcmp(argv[ind], "-") == 0) // What to do if -
	{
		while (Charct != '\n')
		{
			Charct = fgetc(stdin);
			fprintf(stdout,"%c",Charct);
		}
		return EXIT_SUCCESS;
	}

	else
	{
		Charct = fgetc(FilePtr);
		while (!feof(FilePtr))
		{
			fprintf(stdout,"%c",Charct);
			Charct = fgetc(FilePtr);
		}
		fclose(FilePtr);
	}
	return EXIT_SUCCESS;
		
}

// Added so leaving arguments blank is same as -
while (Charct != '\n')
	{
		Charct = fgetc(stdin);
		fprintf(stdout,"%c",Charct);
	}
		
	return EXIT_SUCCESS;
}
