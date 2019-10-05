#include <stdio.h>
#include <math.h>
#include <string.h> /* for strlen */

#define MAX 100
int itoa(int test, char s[]);
void reverse(int length, char from[]);

/* Test variable */
int test = 102;

/* itoa: convert integer into a string using recursion */
static int x = 1;
static int z = 0;
static int pos = 0;
char s[MAX]; /* output string */

int main()
{
    printf("Integer version: %d\n", test);
    int endex = itoa(test, s);
    s[endex] = '\0';
    printf("String version: %s\n", s);
    reverse(strlen(s), s);
    printf("Reversed string: %s\n", s);
    return 0;
}

int itoa(int test, char s[])
{
    if(test / x)
    {
        s[pos] = (test % 10) + '0';
        test /= 10;
        pos++;
        itoa(test, s);
        return pos;
    }
    else{
        return 0;
    }
}

void reverse(int length, char target[]){
    if(z < (length/2)){
        /* We aren't past the halfway mark yet */
        char swap;
        swap = target[z];
        target[z] = target[length-(z+1)];
        target[length-(z+1)] = swap;
        z++;
        reverse(length, target);
    }
    else{
        return;
    }
}

//void reverse(char from[])
//{
//	char buffer[strlen(from)-1];	/* temporary storage */
//
//	for(int i = 0; i < strlen(from); ++i){
//		buffer[i] = from[(strlen(from)-1)-i]; /* place a reverse into storage */
//	}
//	for(int i = 0; i < strlen(from); ++i){
//		from[i] = buffer[i];				/* overwrite array with its reverse */
//	}
//}