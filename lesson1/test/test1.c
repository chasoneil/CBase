#include <stdio.h>

static int a = 10;  // 被static 修饰，只能在本文件中使用

int b = 20; // 可以在其他文件中使用

void test1_f() 
{
    printf("a=%d, b=%d\n", a, b);
}