#include <stdio.h>

#define swap(t,x,y) t z = x; x = y; y = z;

int main(){
    int a = 1;
    int b = 2;
    printf("Before - a: %d\n", a);
    printf("Before - b: %d\n", b);
    swap(int, a, b);
    printf("After - a: %d\n", a);
    printf("After - b: %d\n", b);
    return 0;
}