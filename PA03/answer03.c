#include "answer03.h"
char * strcat_ex(char * * dest, int * n, const char * src) // Append src to dest
{
	int DestLength = 0, SrcLength = 0;
	int SrcIndex = 0;
	int DestIndex = 0;
	int Increase = 0;
	

	DestLength = strlen(*dest);
	SrcLength = strlen(src);



	printf("Done with beginning\n");
	
	if( (*dest == NULL) || (SrcLength + DestLength + 1 > *n) ) // dest is large enough - regular append
	{
		printf("Malloc time\n");
		Increase = SrcLength + DestLength - *n;
		printf("Increase %i\n",Increase);
		dest = malloc(Increase * sizeof(char));
	}	
		
		
	while (src[SrcIndex] != '\0') 
	{
		printf("Beginning of while loop\n");
		// While loop runs until string finishes writing
		*dest[DestIndex + DestLength] = src[SrcIndex];
		
		// Indicies incremented seperatly to keep track of the different
		// places in dest and src
		DestIndex++;
		SrcIndex++;
		printf("Dest %i, Src %i\n",DestIndex, SrcIndex);
			
	}
		
	dest[DestIndex] = '\0';
	free(dest);
	
	

	
	
	
	return *dest;
}



char * * explode(const char * str, const char * delims, int * arrLen)
{
	
	return (char **) arrLen;
}



char * implode(char * * strArr, int len, const char * glue)
{
	
	return *strArr;
}



void sortStringArray(char * * arrString, int len)
{
	
}



void sortStringCharacters(char * str)
{
	
}



void destroyStringArray(char * * strArr, int len)
{
	
}

