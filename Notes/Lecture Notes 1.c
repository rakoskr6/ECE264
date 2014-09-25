#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) //argv[0] is the name of the program. argv[x] is the command line argument
{
	if (argc < 2)
	{
		printf("Need file name\n");
		return EXIT_FAILURE;
	}
	printf("File name is %s\n",argv[1]);
	FILE * fptr; // File is a structure in stdlib.h
	
	fptr = fopen (argv[1],"w"); // w means write
	
	if (fptr == NULL)
	{
		printf("Fopen fail\n");
		return EXIT_FAILURE;
	}
	
	fclose (fptr)
	return EXIT_SUCCESS;
	
}


/* fptr points to file stream (pointer)
 * 		everytime something is read the pointer moves forward
 * 
 */

while (!feof(fpt))
{
	int ch = fgetc(fptr)
	if (ch != EOF) // EOF is a special symbol in stdio.h
	{
		printf("%c %d\n",ch,ch);
		
	}
	
}

fscanf(fptr,"%d",&val); 
