#include <stdio.h>
#include <standlib.h>

int main (int argc, int ** argv)
{
	if (argc < 2)
	{
		printf("Need file name\n");
		return EXIT_FAILURE;
	}
	printf("File name is %s\n",argv[1]);
	FILE * fptr;
	
	fptr = fopen (argv[1],"w"); // w means write
	
	if (fptr == NULL)
	{
		printf("Fopen fail\n");
		return EXIT_FAILURE;
	}
	
	fclose (fptr)
	return EXIT_SUCCESS;
	
}
