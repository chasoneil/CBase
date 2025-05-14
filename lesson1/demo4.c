/*

1. how to define outer variable? extern
    定义的变量没有初始化，值是什么?
2. how to define pointer?
*/

#include <stdio.h>
#include "demo4_2.c"

void testDefaultVariable();

int *ptr1;

int main() 
{
    testDefaultVariable();
    puts("------------------------------");

    /* global pointer */
    printf("global pointer:%p\n", ptr1);  // nil

    /*
        extern 表示声明一个外部变量，这个变量在编译的时候不会定义（不分配存储空间），作用是在多个文件中使用这个变量。
        extern 的声明和定义一般放在不同的文件中。
        extern 的用法详见 demo4_1.c demo4_2.c
    */

    return 0;
}

/* 测试值的初始化 */
void testDefaultVariable() 
{
    int a;
    printf("a:%d\n", a);

    static int b;
    printf("b:%d\n", b);

    float f1;
    printf("f1: %f\n", f1);

    static float f2;
    printf("f2: %f\n", f2);

    char ch1;
    printf("ch1: %c\n", ch1);

    static char ch2;
    printf("ch2: %c\n", ch2);

    int *ptr;
    printf("*ptr: %p\n", ptr);  // nil 初始化为空指针
}

