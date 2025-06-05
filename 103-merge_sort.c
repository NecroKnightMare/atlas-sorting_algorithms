#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/*use [gcc -Wall -Wextra -Werror -pedantic 103-main.c 103-merge_sort.c
print_array.c -o merge] to compile  and ./merge to test output*/

void merge_sort(int *array, size_t size)