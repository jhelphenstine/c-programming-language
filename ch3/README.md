# Chapter 3 - Control Flow
The journey continues. Exercise 3-4 turned out to be the most fun, because it gave me first-hand experience with the dangers of failing to declare an array properly. I'd done:
'char s[] = {};'

I wasn't even thinking about it - still new to C - but it sure compiled fine! However, I noticed that one of my 'int8_t' variables was changing! I'd passed it to a function, but by value, not reference; I haven't gotten to pointers yet. I set another variable to the 'int8_t's value, and it changed too! I was quite confused, and on the verge of asking my first stackoverflow question when I found one of the auto-suggested questions (so you don't duplicate questions): [c - int value changed unexpected](https://stackoverflow.com/questions/22832053/int-value-changed-unexpected). Someone else had the same problem!

I went back, now recognizing how I was overwriting my stack (such irony: I wrote a simple buffer overflow in a class this week!), and properly declared it:
'char s[5] = {};'

This is big enough to hold '-128' + a null terminator, and the program executes correctly. Fun!

# Chapter complete
I've completed Chapter 3, where I lingered the longest so far. I've picked up some examples of good habits along the way, and am beginning to understand common errors I've made, so that I can avoid them in the future. 'sizeof(char s[])', for example. I've also taken a detour into input validation. It's not fast; there's no silver bullet function that perfectly guards against invalid input, and I'll try to carry that lesson forward into the next chapters (as well as my future C programming).

Onward to Chapter 4!
