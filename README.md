# README

This is a repository that documents all my efforts to finish the labs of CSAPP.

## Lab1 Data

`isTmax(x)`, `conditional`, `isLessOrEqual`, and `howManyBits` puzzles are a little tricky. See the comments which explain the ideas of solution in detail.

## Lab2 Bomb

`psol.txt` is the answer sheet. Phase3 is similar to `switch` branches and has several solutions. Phase5 also has multiple answers(tip: **reminders** are *9, f e, 5, 6, 7*). Phase6 is a little complex(tip: *decrement order of an array*).

## Lab3 Attack

Each phases' hex byte code and raw string representation of *exploit* strings are written into files as `exploit.txt` and `exploit_raw.txt`. 

Tips:

+ The stack positions will be consistent from one run to the next so you are able to know the address of stack by checking register %rsp via *GDB*.
+ To avoid *segmentation fault*, do not inject executable code out the bound of the return address of caller frame. In other word, try to write code into buffer and unused region to finish Part One.
+ You would better place strings in some place where they would not be modified. Remember, many instructions like `push`, and `call` will change the contents of stack. 
