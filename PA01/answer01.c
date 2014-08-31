#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int index = 0;
  int sum = 0;

  for (index = 0; index < len; index++)
    {
      sum += array[index];
    }

  return sum;
}

int arrayCountNegative(int * array, int len)
{
  int index = 0;
  int NumNegative = 0;
  for (index = 0; index < len; index++)
    {
      if (array[index] < 0)
	{
	  NumNegative++;
	}
    }
    return NumNegative;
}

int arrayIsIncreasing(int * array, int len)
{    
    return 0;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    return 0;
}

int arrayFindSmallest(int * array, int len)
{
    return 0;
}
