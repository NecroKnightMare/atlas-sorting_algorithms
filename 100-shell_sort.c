#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*use [gcc -Wall -Wextra -Werror -pedantic 100-main.c 100-shell_sort.c print_array.c -o shell]
to compile and ./shell to test output*/

void shell_sort(int *array, size_t size)