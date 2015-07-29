# CS50

These are my personal notes on the CS50 courses and solutions for the problem sets.

## LinksCS50 - Computer Science

* [edX](https://courses.edx.org/dashboard)
* [2014 program](http://prog1.mprog.nl/)
* [CS50 TV](http://cs50.tv/2014/fall/)
* [CS50 Net](http://cs50.net)
* [Submit projects](http://apps.cs50.edx.org/)
* [Test code on the fly C and PHP](http://run.cs50.net/)

## SSH Login

>ssh jharvard@192.168.79.128<br />
>crimson

## pset0

Binary

------------------------
|  1  |  0  |  1  |  1  |  0  | = 22 |
| --- | --- | --- | --- | --- | --- |
|  16 |   8 |   4 |   2 |   1 |     |

## pset1

* Why does float type has rounding errors? http://floating-point-gui.de/
* % operation is called modulo
* Use `man round` to see how to use function, what to include in your program and the get what link argument needs to be used to compile the program.
* Error "undefined reference" probably forgot to link something when compiling
* include <test.h> will make the the compiler understands when you use non standards functions/types, and the linking using -lcs50 for example will tell the compiler after compiling your program to merge in the cs50 library binary code.
* C99?

## pset2

* `undeclared identifier` forgot to include a header file
* atoi() function can be used to convert string to int

### Segmentation fault

Reading argv with a random index, for example `argv[100]` will read out a piece of memory that is not set by my program. If you'll use a really high index you'll probably get a `segmentation fault` which lets you know you are trying to read a piece of memory that is not owned by your program.
The reason this is possible is probably because if you have a program:

```
void main(int argc, string argv[])
{
 printf("hello %s", argv[1]);
}
```

because we don't specify a size for our argv array argument we will get a specific block of memory allocated. In this allocated block of memory that we can access there is still garbage memory data from the previous "owner".

### Bubble sort

Loop over an array of number and every time compare 2 values and swap them if the are out of order.
This will result in each cycle a number at the end is in the correct place.

2 4 3 1
-------
2 4 3 1
2 3 4 1
2 3 1 4
-------
2 3 1 4
2 1 3 4
2 1 3 4
-------
1 2 3 4
1 2 3 4
1 2 3 4

[See wiki for more info](http://en.wikipedia.org/wiki/Bubble_sort)


_Other sort alorithms_
* selection sort: where you loop over the line and find the smallest number, pull it out and place it in the correct position, move the number that is on that position to the open spot.
* insertion sort: create new array and place numbers one by one in the correct position of the new array, shift elements one by one if it needs to be placed between two numbers
* merge sort: merge sort is much more faster then the above ones (n log n) but is needs more memory because we have to use a second array for doing the merging.

_Complexity_

Based on buble sort we can say the first iteration we will have to do (n - 1) comparision, the second iteration (n - 2) because with each iteration an extra element on the end of the list is sorted.
So we can write this like:

(n - 1) + (n - 2) + (n - 3) + .... + 1

the `+ 1` at the end is because the last iteration is just comparing the first item with the second in the list.
This can be simplified as:

>n^2/2 - n/2

I we would like to write this in the `O` notation we will remove all parts that don't have a big impact on the result.
In this case the `- n/2` and `/2` will not have a big impact on the result if use input a large number for `n`.
Therefor we can say bubble sort is on the order of (big O of) `n^2`.
The only part that is important is the part that will grow when our input gets bigger.
So big O can be used to indicate the performance or the running time of an algorithm.

Also big O is an upper bound on the running time.

An example of a `O(n)` alorithm could be finding a person in a list.

* `O(log n)` refers to an alogrithm like the phone book example were you split the problem in two halfs each time. 
* `O(1)` doesn't mean the algorithm takes only one step but it means that it's equally fast for small and large problems
* `Ω(n)` is used to describe the lower bound (best case scenario)
* `Θ(n)` theta means the lower bound and upper bound are the same for the algorithm
* `T(n)=O(1)` T(n) means running time of `n` is big O of 1
* prototype in c means that you announce to the compiler that somewhere in the code will be a function x

### Other

* `main` return value can indicated what has gone wrong in a program that crashes, all non zero values indicate that something has gone wrong

## pset  3

* gdb: GNU Debugger for stepping line by line through a program
* With `echo $?` you can check the return code of an executed cli program
