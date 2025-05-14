#include <stdio.h>  // standard input/output file

int main() 
{
    printf("Hello C\n");

    // print with newline
    puts("Hello line2");
    puts("Hello line3");

    return 0;
}

/*
How to compile?

use gcc [filename.c] -o [output_filename]
if we are not define -o option, the output file will be a.out

Example:

gcc main.c -o myprogram

we can compile multiple files at once:

gcc main.c hello.c -o myprogram

Linux: use ./xx.out to run a file
*/