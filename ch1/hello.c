#include <stdio.h>

/* We're already seeing the difference between C as it was in 1988
 * and modern compilers. It's now improper to declare main without 
 * a type, such as int...and int is the correct answer; void yields
 * compiler errors. Interestingly, I don't need to specify a return
 * for main - by default it returns 0.
*/

int main(void)
{
	printf("hello, world\n");
}
