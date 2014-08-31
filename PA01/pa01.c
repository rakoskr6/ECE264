 
#include <stdio.h>
#include <stdlib.h>

// This includes the /definitions/ of the functions that you write
// in this assignment. Including the definitions allows you to use
// the functions in this file.
#include "answer01.h"

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
	printf("%d", array[ind]);
	if(ind != len - 1) {
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to 
    // include this line to ensure that our output is immediately
    // printed out output.
    fflush(stdout); 
}

void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". sum = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[] = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    // Test cases with decimals
    int array3[5] = {3.2,5.4,3.2};
    int len3 = 3;
    int expected3 = 11.8;
    test_arraySum(array3, len3, expected3);

    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len); 
    printf(". count = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}

void test_01_arrayCountNegative()
{
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    // You can add more test-cases here
    // ...

    printf("\n");
}

void test_arrayIsIncreasing(int * array, int len, int expected)
{
    printArray(array, len);
    int increase  = arrayIsIncreasing(array,len); 
    printf(". Increasing = %d, expected = %d.", increase, expected);
    if(increase != expected)
	printf(" FAIL");
    printf("\n");
}

void test_02_arrayIsIncreasing()
{
    printf("Testing arrayIsIncreasing(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayIsIncreasing(array1, len1, 0);

    int array2[] = {};
    int len2 = 0;
    test_arrayIsIncreasing(array2, len2, 1);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayIsIncreasing(array3, len3, 1);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayIsIncreasing(array4, len4, 0);

    // You can add more test-cases here
    // ...

    printf("\n");
}

void test_arrayindexRFind(int needle, int * haystack, int len, int expected)
{
    printArray(haystack, len);
    int needleind  = arrayIndexRFind(needle, haystack, len); 
    printf(". Location = %d, expected = %d.", needleind, expected);
    if(needleind != expected)
	printf(" FAIL");
    printf("\n");
}

void test_03_arrayindexRFind()
{
    printf("Testing Find Index(...)\n");

    int haystack1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    int needle1 = 4;
    test_arrayindexRFind (needle1, haystack1, len1, 3);

    int haystack2[] = {};
    int len2 = 0;
    int needle2 = 4;
    test_arrayindexRFind (needle2, haystack2, len2, -1);

     int haystack3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    int needle3 = -2;
    test_arrayindexRFind (needle3, haystack3, len3, -1);

    int haystack4[] = { -1, -2, -3, -1 };
    int len4 = 4;
    int needle4 = -1;
    test_arrayindexRFind (needle4, haystack4, len4, 3);

    // You can add more test-cases here
    // ...

    printf("\n");
}

void test_arrayFindSmallest(int * haystack, int len, int expected)
{
    printArray(haystack, len);
    int needleind  = arrayFindSmallest(haystack, len); 
    printf(". Smallest = %d, expected = %d.", needleind, expected);
    if(needleind != expected)
	printf(" FAIL");
    printf("\n");
}

void test_04_arrayFindSmallest()
{
    printf("Testing Find Smallest(...)\n");

    int haystack1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayFindSmallest (haystack1, len1, 2);

    int haystack2[] = {};
    int len2 = 0;
    test_arrayFindSmallest (haystack2, len2, 0);

     int haystack3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayFindSmallest (haystack3, len3, 0);

    int haystack4[] = { -9, -2, -3, -9 };
    int len4 = 4;
    test_arrayFindSmallest (haystack4, len4, 0);

    // You can add more test-cases here
    // ...

    printf("\n");
}



int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n\n");

    // Uncomment to run two example (incomplete) testcases.


    test_00_arraySum();
    test_01_arrayCountNegative();
    test_02_arrayIsIncreasing();
    test_03_arrayindexRFind();
    test_04_arrayFindSmallest();


    return EXIT_SUCCESS;
}


