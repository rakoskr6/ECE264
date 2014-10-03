#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{

int ind = 1; // skip 0, which is the program path
char Pattern[1000];
char String[2000][2000];
int IntLine = 0;
int Invert = FALSE, LineNum = FALSE, Quiet = FALSE;
int PatterNum = 1; // Point in array where the pattern is located
int ReturnValue = 1;

// First loop checks to see if help flag is present or if other flags exist
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
		return 1;
	}
	else if (strcmp(argv[ind], "--invert-match") == 0)
	{
		Invert = TRUE;
		PatterNum++;
	}
	else if (strcmp(argv[ind], "--line-number") == 0)
	{
		LineNum = TRUE;
		PatterNum++;
	}
	else if (strcmp(argv[ind], "--quiet") == 0)
	{
		Quiet = TRUE;
		PatterNum++;
	}
	
}


// Second part stores the pattern string if it exists

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




// Fourth loop searches for pattern in the string
if (Quiet == TRUE)
{
	
	return 0; //match
}

else if ((LineNum == TRUE) && (Invert == TRUE))
{
	
	return 0; //match
}

else if (LineNum == TRUE)
{
	return 0; //match
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



	return ReturnValue;
}
