#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

void push(int i);
int pop();
int stack[MAX] = {0};
int *pstack = stack;

/* expr: evalute a reverse Polish expression from the command line */
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++){
        char c = *argv[i];
        if(isdigit(c)){
            push(atoi(&c));
        }
        else{
            int x = pop();
            int y = pop();
            
            switch (*argv[i]) {
                case '+':
                    push(x + y);
                    break;
                case '-':
                    push(x - y);
                    break;
                case '*':
                    push(x * y);
                    break;
                case '/':
                    if(y == 0){
                        printf("Error, cannot divide by zero.\n");
                        return -1;
                    }
                    push (x / y);
                    break;
                default:
                    printf("Error, unsupported command: %c\n", *argv[i]);
                    return -1;
            }
        }
    }
    printf("%d\n", pop());



    return 0;
}

void push(int i)
{
    *pstack++ = i;
}

int pop()
{
    return *--pstack;
}