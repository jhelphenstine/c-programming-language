#include <stdio.h>
#include <stdbool.h>
#include "calc.h"
#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;			/* next free stack position */
double val[MAXVAL] = {0};	/* value stack */
bool var[MAXVAL] = {false};	/* tracks values representing variables */
double memory[27] = {0.0};	/* holds variables */
bool mem_set[27] = {false};	/* tracks if memory is set */
double lastVal = 0.0;	/* define lastVar */
bool sig_stack_cleared = false;

/* push: push f onto value stack */
/* Called by:
	main()
*/
void push(double f)
{
	/* Check to see if we should clear the stack */
	if (sig_clear == 1){
		for (int i = 0; i < sp; i++){
			val[i] = 0.0;	/* zero out val */
			var[i] = false;	/* zero out var */
		}
		sp = 0; /* has this been my problem? */
		sig_clear = false;	/* reset the clear flag */
		sig_stack_cleared = true; /* tell getop the stack was cleared */
	}
	else if(sp < MAXVAL){
		/* This is where we need to check if we're pushing to memory */
		if (mem_index > -1){
			/* We have an address to store f in */
			/* This requires mem_index to hold a 0-25 value */
			memory[mem_index] = f;	/* load value into memory */
			mem_set[mem_index] = true;	/* flag this as set memory */
			mem_index = -1;	/* reset index */
			var[sp] = true;	/* set flag for this var in val[] */
		}
		else if (sig_variable){
			/* We're storing a variable, need to set flag in var[sp] */
			var[sp] = true;
		}
		val[sp++] = f;
		lastVal = f;
		sig_variable = false;	/* clear this flag */
	}
	else {
		printf("[!] Error: Stack full! Cannot push %g\n", f);
	}
}

/* pop: pop and return top value from stack */
/* Called by:
	main()
*/
double pop(void)
{
	if (sp > 0){
	/* This is better than doing 'sp-1' all over the place */
	int vp = sp-1;
	/* Check to see if we're returning a variable */
		if(var[vp] && dereference){
			/* val[sp] represents index to memory */
			/* For ease of reading */
			int index = (int)val[vp];
			if (index >= 65){ /* janky normalization. but idc! i want done with 4-6. */
				index -= 65;
			}
			if(mem_set[index]){
				/* Memory is set; we can return value */
				//sig_variable = true;
				var[vp] = false;	/* clear this flag */
				sp--;	/* still need to decrement this */
				return memory[index]; /* return value */
			}
			else {
				/* convert to string for error output */
				var[vp] = false;	/* clear this flag */
				//sig_variable = true;
				sp--;	/* still need to decrement this */
				return 0.0;
			}
		}
		else if(var[vp] && !dereference){
			/* We don't want to dereference. Return a value, flag as variable */
			sig_variable = true;
			return val[--sp];
		}
		else {
			/* We're not returning a variable; proceed onward */
			sig_variable = false;
			return val[--sp];
		}
	}
	else {
		printf("[!] Error: Stack empty!\n");
		return 0.0;
	}
}
