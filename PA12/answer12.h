/*
 * Do not edit this file
 */
#ifndef PA12_H
#define PA12_H

typedef __uint128_t uint128;

#define FALSE 0
#define TRUE 1

uint128 alphaTou128(const char * str);
/**
 * Convert the initial portion of C-string 'str' to an unsigned 128-bit integer
 *
 * This function should be just like atoi(...), except that it returns an 128
 * bit unsigned integer. Return 0 on any error. Don't forget you must skip 
 * any initial white-space.
 *
 * See PA02 for hints on implementing this function.
 */


char * u128ToString(uint128 value);
/**
 * Return a newly allocated C-string which represents the passed value.
 * The caller is responsible for freeing the allocated string.
 *
 * If you have already implemented alphaTou128(...) (see hint), then you should
 * be able to figure out how to implement u128ToString(...).
 */


int primalityTestParallel(uint128 value, int n_threads);
/**
 * Test if 'value' is prime.
 * 'n_threads' is the number of threads that will be created to complete 
 * this computation.
 * Return TRUE or FALSE.
 * 
 * LEAK NO MEMORY.
 *
 * Good luck!
 */


#endif
