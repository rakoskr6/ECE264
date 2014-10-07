for n =4:

sum = 0 + f(4-1)
	sum1 = 0 + f(3-1)
		sum2 = 0 + f(2-1)
			return 1
		sum2 = 0 + 1
		sum2++
		return sum2 = 2
	sum1 = 0 + 2
	
	sum1 = 2 + f(3-2)
		return 1
	sum1 = 2 + 1
	sum1++
	return sum1 = 4
sum = 0 + 4

sum = 4 + f(4-2)
	sum1 = 0 + f(2-1)
		return 1
	sum1 = - + 1
	sum1++
	return sum = 2
sum = 4 + 2

sum = 6 + f(4-3)
	return 1
sum = 6 + 1
sum++
sum = 8

# include <stdio.h>
# include <stdlib.h>


int f ( int n )
{
	int i;
	int sum = 0;
	
	if ( n == 1)
	{
		printf("1\n");
		return 1; // only one way to partition 1
	}
	
	for ( i = 1; i < n ; i ++)
	{
		
		sum += f( n - i ) ;
		printf("f(%i-%i) = %i\n",n,i,sum);
	}
	sum ++;
	return sum ;
}


int main ( int argc , char * argv [])
{
	int n ;
	if ( argc < 2)
	{
		printf ("Need one positive integer\n") ;
		return EXIT_FAILURE ;
	}
	
	n = ( int ) strtol ( argv [1] , NULL , 10) ;
	
	if ( n <= 0)
	{
		printf ("Need one positive integer\n") ;
		return EXIT_FAILURE ;
	}
	printf ("f(%d) = %d\n" , n , f ( n ) ) ;
	return EXIT_SUCCESS ;
}
