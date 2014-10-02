/*
 * Recursion
 * 	1. Terminating Condition
 * 	2. Patter
 * 	3. Changing Size
 * 
 * 
 * 
 * 
 * Integer partition
 * 	recursion
 * 	memory allocation
 * 	pointer
 * 
 * Take a positive integer and break it into the sum of some 
 * positive integers or itself
 * 	Ex:
 * 	4 = 1+1+1
 * 	4 = 1+1+2
 * 	4 = 1+2+1
 * 	4 = 1+3
 * 	4 = 2+1+1
 * 	4 = 2+2
 * 	4 = 3+1
 * 	4 = 4
 * 
 * First number 
 */
 
 for (i = 1; i < n; i++)
{
	n-i // left
	
}

partition (int n)
{
	// Terminating Condition
	if (n==0)
	{
		//done
	}
	for(i=1; i<=n; i++)
	{
		//i is used
		partition(n-i);
	}
}

/*
 * How many lines do you have when you partition
 * n and the first number must
 * 
 */
