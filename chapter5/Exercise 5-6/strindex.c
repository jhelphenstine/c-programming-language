#include <stdio.h>
#include <string.h>

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char t);

int main()
{
    char *source = "This is the song that never ends";
    char marker = 't';
    int first_loc = strindex(source, marker);
    if (first_loc != -1){
        printf("%c found at index %d\n", marker, first_loc);
    }
    else {
        printf("%c not found in %s\n", marker, source);
    }

    return 0;
}

int strindex(char *s, char t)
{
    int found = 0;
    char *p = s;
    while ((*p++ != t) && (*p != 0)){
        found++;
    }
    if(p == (strlen(s) + s)){
        found = -1; /* we didn't find it */
    }
    return found;
}