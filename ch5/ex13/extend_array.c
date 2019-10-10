/* Takes an array, allocs double the size of the array, copies the old array
    into the new array, and returns a pointer to the new array.

    @params:
    void *subject       -- pointer to the first byte of the source array
    size_t length       -- length of the source array
    size_t *newlength   -- output parameter to track the length of the new array

    @returns:
    char *              -- pointer to the new array
*/
#include <stdlib.h>
#include <string.h>
#include "tail.h"

char *extend_array(void *subject, size_t length, size_t *newlength)
{
    *newlength = length * 2;
    char *result = alloc(*newlength);
    memcpy(result, subject, length);
    return result;
}
