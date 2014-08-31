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
  int index = 0;
  int indexminus = 0; // Numer before the current index
 

  // Itterates over entire array
  for (index = 0; index < len; index++)
    {
      indexminus = index - 1;

      // Ensures only numbers in the array are read
      if (indexminus < 0)
	{
	  indexminus = index;
	}      

      if (array[index] < array [index - 1])
	{
	  return 0;
	}
    }
    return 1;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    return 0;
}

int arrayFindSmallest(int * array, int len)
{
    return 0;
}
