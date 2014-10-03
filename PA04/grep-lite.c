#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{

int ind = 1; // skip 0, which is the program path
char Pattern[100]; // Alocate enough room for pattern
char String[500][500]; // Alocate enough room for files
int IntLine = 0;
int Invert = FALSE, LineNum = FALSE, Quiet = FALSE;
int PatterNum = 1; // Point in array where the pattern is located
int ReturnValue = 1; // Value to return function (if not 0)

// First loop checks to see if help flag is present or if other flags exist
for( ; ind < argc; ++ind) 
{
	// If --help is passed, show help and end. Otherwise record other arguments
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
		return 1;
	}
	else if ((strcmp(argv[ind], "--invert-match") == 0) || (strcmp(argv[ind], "-v") == 0))
	{
		Invert = TRUE;
		PatterNum++;
	}
	else if ((strcmp(argv[ind], "--line-number") == 0) || (strcmp(argv[ind], "-n") == 0))
	{
		LineNum = TRUE;
		PatterNum++;
	}
	else if ((strcmp(argv[ind], "--quiet") == 0) || (strcmp(argv[ind], "-q") == 0))
	{
		Quiet = TRUE;
		PatterNum++;
	}
	
}


// Second part. Stores the pattern string if it exists

if (PatterNum == (argc - 1)) 
{
	strcpy(Pattern,argv[PatterNum]);
}		
else
{
	return 2;
}

	
// Third loop takes the stdin and stores it into String array
while (fgets(String[IntLine],2000,stdin) != NULL)
{
		IntLine++;
}




// Fourth loop searches for pattern in the string. Different cases for each argument
if (Quiet == TRUE)
{
		for (ind = 0; ind < IntLine; ind++)
	{
		if (strstr(String[ind],Pattern) != NULL)
		{
			ReturnValue = 0;
		}
	}
}

else if ((LineNum == TRUE) && (Invert == TRUE))
{
	
		for (ind = 0; ind < IntLine; ind++)
	{
		if (strstr(String[ind],Pattern) != NULL)
		{
			ReturnValue = 0;
		}
		else
		{
			printf("%d:%s",ind + 1,String[ind]);
		}
	}
}

else if (LineNum == TRUE)
{
		for (ind = 0; ind < IntLine; ind++)
	{
		if (strstr(String[ind],Pattern) != NULL)
		{
			printf("%d:%s",ind + 1,String[ind]);
			ReturnValue = 0;
		}
	}
}

else if (Invert == TRUE)
{
	for (ind = 0; ind < IntLine; ind++)
	{
		if (strstr(String[ind],Pattern) != NULL)
		{
			ReturnValue = 0;
		}
		else
		{
			printf("%s",String[ind]);
		}
	}

}

else
{
	for (ind = 0; ind < IntLine; ind++)
	{
		if (strstr(String[ind],Pattern) != NULL)
		{
			printf("%s",String[ind]);
			ReturnValue = 0;
		}
	}
}



	return ReturnValue; // Return value defined above
}
