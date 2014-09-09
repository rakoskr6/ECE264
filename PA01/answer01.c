#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int index = 0;
  int sum = 0;

  // Itterates through the whole array adding all numbers
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

  // Itterates through the whole array counting all numbers < 0
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
 

  // Itterates over entire array, only finishes loop if arrays increasing
  for (index = 0; index < len; index++)
    {
      indexminus = index - 1;

      // Ensures only numbers in the array are read
      if (indexminus < 0)
	{
	  indexminus = index;
	}      

      // If the array isn't increasing return 0
      if (array[index] < array [indexminus])
	{
	  return 0;
	}
    }
    return 1;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int index = 0;
  int NeedleIndex = -1;

  // Itterates over entire array looking for the needle
  for (index = 0; index < len; index++)
    {
      if (haystack[index] == needle)
	{
	  NeedleIndex = index;
	}
    }

    return NeedleIndex;
}

int arrayFindSmallest(int * array, int len)
{
  int index = len;
  int smallest;
  int smallestindex;

  // Ensures there is at least 1 number in the array
  if (len <= 0)
    {
      return 0;
    }

  smallest = array[len-1]; // Initial value of smallest in case all numbers are the same

  // Itterates over entire array right to left (so rightmost number is used
  // if multiple lowest numbers exist)
  for (index = len - 1; index >= 0; index--)
    {
      if (array[index] <= smallest)
	{
	  smallestindex = index;
	  smallest = array[index];
	}
    }

    return smallestindex;
}
