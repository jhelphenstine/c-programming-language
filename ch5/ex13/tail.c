#include <stdio.h>
#include "tail.h"

// int main(int argc, char *argv[])
int main(void)
{
    char *lineptr[42] = {0};
    size_t length = sizeof(lineptr);
    size_t newlength = 0;
    char *newlineptr = extend_array(lineptr, length, &newlength);
    printf("Testing: sizeof newlineptr is %lu\n", sizeof(newlineptr));
    printf("Testing: Length of array returned by extend_array is %lu\n", newlength);
}
