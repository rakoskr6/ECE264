#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
int ind = 1; // Skip 0,the program path
   
   // Loop through arguments to print
   
for( ; ind < argc; ++ind) 
{   
	fprintf(stdout, "%s ", argv[ind]);
}
fprintf(stdout, "\n"); // Add newline after complete
	
	return EXIT_SUCCESS;
}
