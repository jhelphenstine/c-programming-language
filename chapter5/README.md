# Chapter 5
## Exercises 5-1 & 5-2
Introducing pointers! Pointers have long been my stumbling block in learning C, but I think I'm approaching the topic with sufficient momentum and understanding to break through. These first exercises use pointers to permit functions to alter variables in the calling function. I can already imagine how this could've saved me some flail on the polish calculator; this offers a way for functions to communicate beyond their return value, and without having to maintain global state variables. The type of a pointer specifies the 'amount of memory' it points to - the pointer itself holds an address, but when should a program stop reading? This is specified by the type of the pointer; a char should read 1 byte, while an int should read 4, all depending, of course, on your architecture's implementation. So far, so good.

## Exercises 5-5
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
