#include "answer03.h"
#include <string.h>


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
		dest2 = malloc(1 + 2 * (DestLength + SrcLength));
		
	    *dest = dest2;
	    strcpy(*dest + DestLength,src);
	    return *dest;
	}
	else
		DestLength = strlen(*dest);
	
	
	
	if((SrcLength + DestLength + 1) > *n) // dest is not large enough - malloc
	{
		*n = SrcLength + DestLength + 1;
		dest2 = malloc(1 + 2 * (DestLength+ SrcLength));
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
	*arrLen = 0;
	
	
	StrLength = strlen(str); 
	DelimsLength = strlen(delims);
	
	// Computes number of rows (arrLen) and columns (MaxSize)
	for (StrIndex = 0; StrIndex <= StrLength; StrIndex++)
	{
		for (DelimsIndex = 0; DelimsIndex < DelimsLength; DelimsIndex++)
		{
			if (str[StrIndex] == delims[DelimsIndex])
			{
				*arrLen = *arrLen + 1;
				if (MaxSize < (StrIndex - PrevDelim))
				{	
					MaxSize = StrIndex - PrevDelim; // Perhaps -1
				}
				PrevDelim = StrIndex;
			}
		}
	}
	
	
	// Creates 2D array of appropriate length
	StrArr = malloc((*arrLen + 1) * sizeof(char*));  // Plus 1
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
			
			if ((str[StrIndex] == delims[DelimsIndex]) || (str[StrIndex] == '\0'))
			{
				// This is where the new string is actually created
				CurrentSize = StrIndex - PrevDelim;
				
				for (PrevDelimIndex = 0; PrevDelimIndex <= CurrentSize; PrevDelimIndex++)
				{
					if (PrevDelimIndex != CurrentSize)
					{
						StrArr[StrNumber][PrevDelimIndex] = str[PrevDelim + PrevDelimIndex];
					}
					if (PrevDelimIndex == CurrentSize)
					{
						StrArr[StrNumber][PrevDelimIndex] = '\0'; // Add end of string character after finsihed
					}
				}
				PrevDelim = StrIndex + 1; // +1 so the same value isn't repeated
				StrNumber++;
			}
		
		}
	}
		
	*arrLen = *arrLen + 1;
	
	return StrArr;
}



char * implode(char * * strArr, int len, const char * glue) // Combines elements of strArr (length len) into one array with glue b/t
{
	char *strArrNew = NULL;
	int LenIndex = 0;
	int n = 0;
	
	
	//strArrNew= malloc(len * sizeof(char));
	
	for (LenIndex = 0; LenIndex <= len; LenIndex++)
	{
		strArrNew = strcat_ex(&strArrNew, &n, strArr[LenIndex]); // Append src to dest
		if (LenIndex != len) // Done to ensure glue isn't added to end of array
		{
			strArrNew= strcat_ex(&strArrNew, &n, glue);
		}
	}
	
	for (n = 0; n <= len; n++)
	{
		free(strArr[n]); // Improper free
	}
	free(strArr);
	
	return strArrNew;
}

int compar (const void *a, const void*b)
{
	return strcmp(*(char**)a,*(char**)b);
}


void sortStringArray(char * * arrString, int len)
{
	qsort(arrString, len, sizeof(arrString[0]), compar);
}


int compar2 (const void *a, const void *b)
{
	return (*(char*)a - *(char*)b);
}


void sortStringCharacters(char * str)
{
	//printf("%s\n",str);
	qsort(str, strlen(str), sizeof(char), compar2);
	//printf("%s\n",str);
}



void destroyStringArray(char * * strArr, int len)
{
	int n = 0;
	if (strArr != NULL)
	{
		for (n = 0; n < (strlen(*strArr)); n++)
		{
			free(strArr[n]);
		}
		free(strArr);
	}
}

