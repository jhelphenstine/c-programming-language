# Chapter 5
## Exercises 5-1 & 5-2
Introducing pointers! Pointers have long been my stumbling block in learning C, but I think I'm approaching the topic with sufficient momentum and understanding to break through. These first exercises use pointers to permit functions to alter variables in the calling function. I can already imagine how this could've saved me some flail on the polish calculator; this offers a way for functions to communicate beyond their return value, and without having to maintain global state variables. The type of a pointer specifies the 'amount of memory' it points to - the pointer itself holds an address, but when should a program stop reading? This is specified by the type of the pointer; a char should read 1 byte, while an int should read 4, all depending, of course, on your architecture's implementation. So far, so good.

## Exercise 5-4
I'm already improving older code. One of the tasks given was to implement
strend, which tests a string to see if its end matches another string. I chose
to reverse them and work from index 0, and called upon my recursive reverse
function from chapter 4. My previous version of that function relied on
initializing a variable for each initial recursion (and I mistakenly made that
static, which was unnecessary). I wanted this to be more severable, to put
reverse in its own source file, so that pushed me to figure out that adding a
third parameter of an int to track that variable would let me pass 0 to
accomplish my objective. So now I have an improved reverse, and I don't feel as
dirty about the implementation as I did on the initial cut of it.

## Exercise 5-6
Completing 5-6 gave me practice with refactoring prior code. I learned I'm glad for my gratuitous commenting, and that I still need to write more comments. I also noticed (and fixed) a bug in getop. Overall, I'm getting acquainted with pointers, just in time to roll into pointer arrays.

## Exercise 5-7
I hadn't yet transcribed alloc, but this exercise will call for it. That's just as well - while I know it's a far cry from malloc, it should help me start thinking in terms of allocating blocks for use, as well as freeing them upon completion. I note the provided examples for 5-7 don't use a free(), so I'll look to see if it makes sense to add something like that as 'good housekeeping'.

## Exercise 5-9
Pointers are really clicking for me after Exercise 5-9. ayayron helped me grok
the proper way to handle arithmetic, and this exercise was very useful.

## Exercise 5-10
It's fun to find assignments that ask to replicate basic components of the Linux
environment, such as `expr`. This one gave me unexpected behavior - because the
example they give includes a * which expands to a directory listing in bash.
This probably wasn't a problem in 1978 :) Also, pointers make functions such as
`push()` and `pop()` much quicker to write.
