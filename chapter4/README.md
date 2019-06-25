# Chapter 4
## Exercises 4-1 && 4-2
Exercise 4-1 proved very straightforward. For exercise 4-2, I took the time to write out how the authors implemented atof(), and worked through how I'd extend the features. It's turning out to be very helpful to write out my thoughts in a notebook (with a pencil, no less), liberally commenting to ensure I have a coherent narrative before putting fingers to keyboard. I learned about `gcc's -lm`, [which tells gcc which files to link against](https://stackoverflow.com/a/8671386/11639518); I received an error stating `math.h`'s `pow()` wasn't defined, even as I `#include <math.h>`. Now I'll know what that means next time.

## Miscellany
I'm switching from `cc` to `gcc`, with the -Wall -Werror -Wextra flags as suggested by my mentor. I got my hand slapped (politely) for declaring an array with {}; this isn't valid post C99, so I'm switching compilers to avail myself of the warnings & error messages that should help me write more compliant code.
