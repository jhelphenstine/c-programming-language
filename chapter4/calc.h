#define NUMBER '0'	/* signal that a number was found */
#define calc_VERSION_MAJOR @calc_VERSION_MAJOR@
#define calc_VERSION_MINOR @calc_VERSION_MINOR@

/* Exercise 4-3, Part II, extend calc to handle negative numbers */
extern int sign;	/* keep track of sign */

/* Exercise 4-4, Part I, provide ability to read last val put wtihout pop() */
extern double lastVal;

/* External variable to signal stack clear */
extern int sig_clear;

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
