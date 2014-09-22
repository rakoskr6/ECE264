#include "answer03.h"
char * strcat_ex(char * * dest, int * n, const char * src) // Append src to dest
{
	int DestLength = 0, SrcLength = 0;
	char * dest2;

	// Gets lengths of Dest and Src to see if too large for memory
	SrcLength = strlen(src);
	
	if ( *dest == NULL) // Doesn't work
	{
		DestLength = 0;
		*n = SrcLength + DestLength + 1;
		dest2 = malloc(*n * sizeof(char));
	    *dest = dest2;
	    strcpy(*dest + DestLength,src);
	    return *dest;
	}
	else
		DestLength = strlen(*dest);
	
	
	
	if((SrcLength + DestLength + 1) > *n) // dest is not large enough - malloc
	{
		*n = SrcLength + DestLength + 1;
		dest2 = malloc(*n * sizeof(char));
		strcpy(dest2,*dest);
		free(*dest);
	    *dest = dest2;
	    strcpy(*dest + DestLength,src);
	}
	else // Enough room - regular append
	{
	    strcpy(*dest + DestLength,src);
	}
		

	return *dest;
}



char * * explode(const char * str, const char * delims, int * arrLen) // split str at delims for arrLen splits (+1)
{
	
	int StrLength = 0, StrIndex = 0, DelimsLength = 0, DelimsIndex = 0, MaxSize = 0, PrevDelim = 0;
	
	char **StrArr;
	int StrArrIndex = 0;
	
	int PrevDelimIndex = 0, CurrentSize = 0, StrNumber = 0;
	
	
	
	StrLength = strlen(str);
	DelimsLength = strlen(delims);
	
	// Computes number of rows (arrLen) and columns (MaxSize)
	for (StrIndex = 0; StrIndex <= StrLength; StrIndex++)
	{
		for (DelimsIndex = 0; DelimsIndex < DelimsLength; DelimsIndex++)
		{
			if (str[StrIndex] == delims[DelimsIndex])
			{
				*arrLen++;
				if (MaxSize < (PrevDelim - StrIndex))
				{	
					MaxSize = PrevDelim - StrIndex;
				}
				PrevDelim = StrIndex;
			}
		}
	}
	printf("MaxSize: %i\n",MaxSize);
	printf("ArrLen: %i\n",*arrLen);
	
	// Creates 2D array of appropriate length
	StrArr = malloc(*arrLen * sizeof(char*));
	for (StrArrIndex = 0; StrArrIndex <= *arrLen; StrArrIndex++)
	{
		StrArr[StrArrIndex] = malloc(MaxSize * sizeof(char));
	}
	
	
	// Breaks up the str array and adds it to the 2D StrArr array
	PrevDelim = 0;
	for (StrIndex = 0; StrIndex <= StrLength; StrIndex++)
	{
		for (DelimsIndex = 0; DelimsIndex < DelimsLength; DelimsIndex++)
		{
			
			if (str[StrIndex] == delims[DelimsIndex])
			{
				for (PrevDelimIndex = 0; PrevDelimIndex <= CurrentSize; PrevDelimIndex++)
				{
					StrArr[StrNumber][PrevDelimIndex] = str[PrevDelim + PrevDelimIndex];
					
				}
				PrevDelim = StrIndex;
				StrNumber++;
			}
		
		}
	}
		
	printf("arrLen: %i\n",*arrLen);
	printf("StrArr: %s\n",*StrArr);
	
	return StrArr;
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

