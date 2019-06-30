#include <stdio.h>
#include <stdbool.h>
#include "calc.h"
#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;			/* next free stack position */
double val[MAXVAL] = {0};	/* value stack */
bool var[MAXVAL] = {false};	/* tracks values representing variables */
double memory[26] = {0.0};	/* holds variables */
bool mem_set[26] = {false};	/* tracks if memory is set */
double lastVal = 0.0;	/* define lastVar */

/* push: push f onto value stack */
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
	}
	else if(sp < MAXVAL){
		/* This is where we need to check if we're pushing to memory */
		if (mem_index > -1){
			printf("stack.c: push: mem_index is > -1\n");
			/* We have an address to store f in */
			/* This requires mem_index to hold a 0-25 value */
			printf("stack.c push: storing %g at index %d\n", f, mem_index);
			memory[mem_index] = f;	/* load value into memory */
			mem_set[mem_index] = true;	/* flag this as set memory */
			mem_index = -1;	/* reset index */
			var[sp] = true;	/* set flag for this var in val[] */
			printf("stack.c push: var[%d] = true\n", sp);
			printf("stack.c: push: reset mem_index to -1\n");
		}
		if (sig_variable){
			/* We're storing a variable, need to set flag in var[sp] */
			printf("stack.c: push: sig_variable is set\n");
			printf("stack.c: push: treating %g as a variable\n", f);
			printf("stack.c push: var[%d] = true\n", sp);
			var[sp] = true;
		}
		printf("stack.c: push: set val[%d] to %g\n", sp, f);
		val[sp++] = f;
		lastVal = f;
		sig_variable = false;	/* clear this flag */
		printf("stack.c push: leaving push; clearing sig_variable\n");
	}
	else {
		printf("[!] Error: Stack full! Cannot push %g\n", f);
	}
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0){
	/* This is better than doing 'sp-1' all over the place */
	int vp = sp-1;
	printf("stack.c: entering pop: sp is %d\n", sp);
	/* Check to see if we're returning a variable */
		if(var[vp] && dereference){
			/* val[sp] represents index to memory */
			/* For ease of reading */
			int index = (int)val[sp];
			if (index >= 65){ /* janky normalization. but idc! i want done with 4-6. */
				index -= 65;
			}
			printf("stack.c: in pop: using this as index into memory: %d\n", index);
			if(mem_set[index]){
				/* Memory is set; we can return value */
				//sig_variable = true;
				printf("stack.c: in pop: I'm popping a variable: %g\n", memory[index]);
				var[vp] = false;	/* clear this flag */
				sp--;	/* still need to decrement this */
				printf("stack.c: exiting pop\n");
				return memory[index]; /* return value */
			}
			else {
				/* convert to string for error output */
				printf("stack.c: in pop: error: variable not set: %s\n", ("A" + (int)val[vp]));
				var[vp] = false;	/* clear this flag */
				//sig_variable = true;
				sp--;	/* still need to decrement this */
				printf("stack.c: exiting pop\n");
				return 0.0;
			}
		}
		else if(var[vp] && !dereference){
			/* We don't want to dereference. Return a value, flag as variable */
			printf("stack.c: in pop: I'm popping a variable: %g\n", val[vp]);
			sig_variable = true;
			printf("stack.c: exiting pop\n");
			return val[--sp];
		}
		else {
			/* We're not returning a variable; proceed onward */
			printf("stack.c: in pop: I'm not returning a variable. Popping: %g\n", val[sp-1]);
			sig_variable = false;
			printf("stack.c: exiting pop\n");
			return val[--sp];
		}
	}
	else {
		printf("stack.c: exiting pop\n");
		printf("[!] Error: Stack empty!\n");
		return 0.0;
	}
}
