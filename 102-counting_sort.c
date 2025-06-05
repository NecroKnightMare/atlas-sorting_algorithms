#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/*use [gcc -Wall -Wextra -Werror -pedantic 102-main.c 102-counting_sort.c 
print_array.c -o counting] to compile and ./counting to test*/

void counting_sort(int *array, size_t size)