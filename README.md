# Problem set 0

Binary
------

------------------------
|  1  |  0  |  1  |  1  |  0  | = 22 |
| --- | --- | --- | --- | --- | --- |
|  16 |   8 |   4 |   2 |   1 |     |

# LinksCS50 - Computer Science

* (edX)[https://courses.edx.org/dashboard]
* (2014 program)[http://prog1.mprog.nl/]
* (CS50 TV)[http://cs50.tv/2014/fall/]
* (CS50 Net)[http://cs50.net]
* (Submit projects)[http://apps.cs50.edx.org/]
* (Test code on the fly C and PHP)[http://run.cs50.net/]

SSH Login
---------
>ssh jharvard@192.168.79.128
>crimson

pset1
-----

* Why does float type has rounding errors? http://floating-point-gui.de/
* % operation is called modulo
* Use `man round` to see how to use function, what to include in your program and the get what link argument needs to be used to compile the program.
* Error "undefined reference" probably forgot to link something when compiling
* include <test.h> will make the the compiler understands when you use non standards functions/types, and the linking using -lcs50 for example will tell the compiler after compiling your program to merge in the cs50 library binary code.
* C99?

pset2
-----

* `undeclared identifier` forgot to include a header file
* atoi() function can be used to convert string to int