#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer12.h"

int main(void)
{
	uint128 value;
	char *sValue;
	
	value = alphaTou128(" 0123456789999999999999999999876543210");
	sValue = u128ToString(value);
	printf("%s\n",sValue);
	free(sValue);
	return 0;
}
