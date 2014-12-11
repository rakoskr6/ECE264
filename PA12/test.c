#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer12.h"

int main(void)
{
	uint128 value;
	char *sValue;
	
	value = alphaTou128("123456789876543210");
	sValue = u128ToString(value);
	printf("%s\n",sValue);
	
	return 0;
}
