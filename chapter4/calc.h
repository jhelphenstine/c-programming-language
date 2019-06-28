#define NUMBER '0'	/* signal that a number was found */

/* Exercise 4-3, Part II, extend calc to handle negative numbers */
extern int sign;	/* keep track of sign */

/* push:	push variable onto the value stack */
void push(double);

/* pop:		pop and return top value from stack */
double pop(void);

/* getop:	get next operator or numeric operand */
int getop(char []);

/* getch:	get a (possibly pushed back) character */
int getch(void);

/* ungetch:	push character back on input */
void ungetch(int);
