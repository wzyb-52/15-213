# README

This is a repository that contains the implementation of labs of CSAPP.

## Lab0 C Programming

Due to the smattering of `malloc()` and other concepts about memory management of C, I failed several times at the beginning. Command `man` will be very helpful when having trouble with the usages of some C functions. Remember, every `malloc()` should correspond to a `free()`. 

## Lab1 Data

`isTmax(x)`, `conditional`, `isLessOrEqual`, and `howManyBits` puzzles are a little tricky. See the comments which explain the ideas of solution in detail.

## Lab2 Bomb

`psol.txt` is the answer sheet. Phase3 is similar to `switch` branches and has several solutions. Phase5 also has multiple answers(tip: **reminders** are *9, f e, 5, 6, 7*). Phase6 is a little complex(tip: *decrement order of an array*).

## Lab3 Attack

Each phases' hex byte code and raw string representation of *exploit* strings are written into files as `exploit.txt` and `exploit_raw.txt`. 

Tips:

+ The stack positions will be consistent from one run to the next so you are able to know the address of stack by checking register %rsp via *GDB*.
+ To avoid *segmentation fault*, do not inject executable code out the bound of the return address of caller frame. In other word, try to write code into buffer and unused region to finish Part One.
+ You would better place strings in some places where they would not be modified. Remember, many instructions like `push`, and `call` will change the contents of stack. 
+ Phase 5 may need to construct some instruction beyond `pop`, `mov`, and `nop`. I didn't have any idea about how to resolve this phase by only using these instructions.
