#ifndef __RETARR_FUNCTIONS_H__
#define __RETARR_FUNCTIONS_H__

/*
 * Demonstrates returning a pointer to an array. Other ways to declare this 
 * function would be:
 * 
 * int *return_array_function(int ai[10], int increment);
 * int *return_array_function(int *ai[10], int increment);
 */
int *return_array_function(int *ai, int size, int increment);

auto populate_array_function(int i) -> int;

#endif
