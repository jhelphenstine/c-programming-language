#include <stdio.h>
#include <string.h>

/* strcmp_n: compare at most n characters of string cs to string ct;
            return < 0 if cs < ct, 0 if ==, > 0 if cs > ct

            replicates behavior of strncmp
*/
int strcmp_n(char *cs, char *ct, int n);

int main()
{
    char *first = "Healer";
    char *second = "Heals";
    int reps = (strlen(first) < strlen(second)) ? strlen(first) : strlen(second);
    for(int i = 0; i < reps; i++){
        int result = strcmp_n(first, second, i);
        printf("Result: %d\n", result);
    }

    return 0;
}

int strcmp_n(char *cs, char *ct, int n)
{
    for(int i = 0; i <= n; i++){
        if(cs[i] == ct[i]){
            continue;
        }
        else if(cs[i] > ct[i]){
            return 1;
        }
        else{
            return -1;
        }
    }
    return 0;
}