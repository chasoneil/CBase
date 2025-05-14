#include <stdio.h>

// extern int a; 编译报错
extern int b;

extern void test1_f();

void test2_f() 
{
    printf("b=%d\n", b);
}

int main() 
{

    test1_f();
    puts("-----------------");
    test2_f();    

    return 0;
}