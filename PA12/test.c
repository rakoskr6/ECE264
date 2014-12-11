#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer12.h"

int main(void)
{
	uint128 value;
	char *sValue;
	
	value = alphaTou128("9");
	sValue = u128ToString(value);
	printf("%s is %i\n",sValue, primalityTestParallel(value, 1));
	printf("%i is %i\n",5, primalityTestParallel(5, 1));
	free(sValue);
	return 0;
}
