#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer05.h"
// Function Prototypes
void Partition (int * arr, int ind, int left);
void PartitionIn(int * PartArr, int ind, int left);
void PartitionDec(int * PartArr, int ind, int left);
void PartitionEv(int * PartArr, int ind, int left);
void PartitionOd(int * PartArr, int ind, int left);
void PartitionOdEv(int * PartArr, int ind, int left);


void partitionAll(int PartitionNum) // Code used (and modified) from class book
{
	int * PartArr;
	PartArr = malloc(sizeof( int ) * PartitionNum);
	
	Partition(PartArr, 0 , PartitionNum); // Call function which will actually use recursion
	
	free(PartArr);
}

void Partition(int * PartArr, int ind, int left)
{
	int val = 1, PrintInd = 0;
	/* left is how many integer options are left after the first integer is chosen
	 * val is the value that is part of the partition
	 * ind is the order in which the previously found val will go */
	
	
	if (left == 0) // Then print array to show partition
	{
		for (PrintInd = 0; PrintInd < ind - 1; PrintInd++)
		{
			printf("%d + ",PartArr[PrintInd]);
		}
		printf("%d\n",PartArr[ind - 1]); // Out of loop to allow \n
	}
	
	for(val = 1; val <= left; val ++)
	{
		PartArr[ind] = val;
		Partition(PartArr, ind + 1 , left - val);
	}
}



void partitionIncreasing(int PartitionNum)
{
	int * PartArr;
	PartArr = malloc(sizeof( int ) * PartitionNum);
	
	PartitionIn(PartArr, 0 , PartitionNum); // Call function which will actually use recursion
	
	free(PartArr);
}

void PartitionIn(int * PartArr, int ind, int left)
{
	int val = 1, PrintInd = 0;
	
	if (left == 0) // Then print array to show partition
	{
		for (PrintInd = 0; PrintInd < ind - 1; PrintInd++)
		{
			printf("%d + ",PartArr[PrintInd]);
		}
		printf("%d\n",PartArr[ind - 1]); // Out of loop to allow \n
	}
	
	for(val = 1; val <= left; val ++)
	{
		if ((ind - 1) >= 0) // Makes sure a valid location in array will be derefference
		{
			if (val > PartArr[ind - 1]) // Ensure current value > previous value
			{
				PartArr[ind] = val;
				PartitionIn(PartArr, ind + 1, left - val);
			}

		}
		else
		{
			PartArr[ind] = val;
			PartitionIn(PartArr, ind + 1 , left - val);
		}
	}
}


void partitionDecreasing(int PartitionNum)
{
	int * PartArr;
	PartArr = malloc(sizeof( int ) * PartitionNum);
	
	PartitionDec(PartArr, 0 , PartitionNum); // Call function which will actually use recursion
	
	free(PartArr);
}

void PartitionDec(int * PartArr, int ind, int left)
{
	int val = 1, PrintInd = 0;
	
	if (left == 0) // Then print array to show partition
	{
		for (PrintInd = 0; PrintInd < ind - 1; PrintInd++)
		{
			printf("%d + ",PartArr[PrintInd]);
		}
		printf("%d\n",PartArr[ind - 1]); // Out of loop to allow \n
	}
	
	for(val = 1; val <= left; val ++)
	{
		if ((ind - 1) >= 0) // Makes sure a valid location in array will be derefference
		{
			if (val < PartArr[ind - 1]) // Ensure current value < previous value
			{
				PartArr[ind] = val;
				PartitionDec(PartArr, ind + 1, left - val);
			}

		}
		else
		{
			PartArr[ind] = val;
			PartitionDec(PartArr, ind + 1 , left - val);
		}
	}
}


void partitionEven(int PartitionNum)
{
	int * PartArr;
	PartArr = malloc(sizeof( int ) * PartitionNum);
	
	PartitionEv(PartArr, 0 , PartitionNum); // Call function which will actually use recursion
	
	free(PartArr);
}

void PartitionEv(int * PartArr, int ind, int left)
{
	int val = 1, PrintInd = 0;
	
	if (left == 0) // Then print array to show partition
	{
		for (PrintInd = 0; PrintInd < ind - 1; PrintInd++)
		{
			printf("%d + ",PartArr[PrintInd]);
		}
		printf("%d\n",PartArr[ind - 1]); // Out of loop to allow \n
	}
	
	for(val = 1; val <= left; val ++)
	{
		if (val % 2 == 0) // Ensure current value is even
		{
			PartArr[ind] = val;
			PartitionEv(PartArr, ind + 1, left - val);
		}
	}

	
}


void partitionOdd(int PartitionNum)
{
	int * PartArr;
	PartArr = malloc(sizeof( int ) * PartitionNum);
	
	PartitionOd(PartArr, 0 , PartitionNum); // Call function which will actually use recursion
	
	free(PartArr);
}

void PartitionOd(int * PartArr, int ind, int left)
{
	int val = 1, PrintInd = 0;
	
	if (left == 0) // Then print array to show partition
	{
		for (PrintInd = 0; PrintInd < ind - 1; PrintInd++)
		{
			printf("%d + ",PartArr[PrintInd]);
		}
		printf("%d\n",PartArr[ind - 1]); // Out of loop to allow \n
	}
	
	for(val = 1; val <= left; val ++)
	{
		if (val % 2 != 0) // Ensure current is odd
		{
			PartArr[ind] = val;
			PartitionOd(PartArr, ind + 1, left - val);
		}
	}	
}







void partitionOddAndEven(int PartitionNum)
{
	int * PartArr;
	PartArr = malloc(sizeof( int ) * PartitionNum);
	
	PartitionOdEv(PartArr, 0 , PartitionNum); // Call function which will actually use recursion
	
	free(PartArr);
}

void PartitionOdEv(int * PartArr, int ind, int left)
{
	int val = 1, PrintInd = 0;
	
	if (left == 0) // Then print array to show partition
	{
		for (PrintInd = 0; PrintInd < ind - 1; PrintInd++)
		{
			printf("%d + ",PartArr[PrintInd]);
		}
		printf("%d\n",PartArr[ind - 1]); // Out of loop to allow \n
	}
	
	for(val = 1; val <= left; val ++)
	{
		if ((ind-1) < 0) // If 0 index, can be even or odd
		{
				PartArr[ind] = val;
				PartitionOdEv(PartArr, ind + 1, left - val);
		}
		else if (val % 2 != 0) // If current is odd
		{
			if (PartArr[ind - 1] % 2 == 0) // What to do if previous was even
			{
				PartArr[ind] = val;
				PartitionOdEv(PartArr, ind + 1, left - val);
			}
			// Else do nothing
		}
		else // If curren is even
		{
			if (PartArr[ind - 1] % 2 != 0) // What to do if previous was Odd
			{
				PartArr[ind] = val;
				PartitionOdEv(PartArr, ind + 1, left - val);
			}
			// Else do nothing
		}		
	}	
}
