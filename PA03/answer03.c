#include "answer03.h"
char * strcat_ex(char * * dest, int * n, const char * src) // Append src to dest
{
	int DestLength = 0, SrcLength = 0;
	//int SrcIndex = 0;
	//int DestIndex = 0;
	int Increase = 0;
	char * dest2;

	
	DestLength = strlen(*dest);
	SrcLength = strlen(src);
	printf("Dest %i, Src %i\n\n",DestLength,SrcLength);
	
	if( (*dest == NULL) || (SrcLength + DestLength + 1 > *n) ) // dest is not large enough - malloc
	{
		printf("Going to use malloc\n\n");
		Increase = SrcLength + DestLength + 1;
		dest2 = malloc(Increase * sizeof(char));
		strcpy(dest2,*dest);
		free(*dest);
		printf("%s\n\n",dest2);
	    *dest = dest2;
	    strcpy(*dest + DestLength,src);

}
		
	
	

	
	
	
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

