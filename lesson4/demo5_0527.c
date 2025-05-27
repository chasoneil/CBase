/**
 * C语言头文件
 * 建议把所有的常量，宏，系统全局变量和函数原型写在头文件中
 */
#include <stdio.h>
#include "demo5_1.h"

/* 当需要根据需求引入多个头文件的时候 */
#if SYSTEM_1
    #include "demo5_2.h"
#elif SYSTEM_2
    #include <stdlib.h>
#else
    #include <string.h>
#endif

void func1();

int main() 
{
    func1();
    return 0;
}

void func1() 
{
    printf("PI: %.2f\n", PI);

    int res = max(3, 4);
    printf("max: %d\n", res);

    res = add(3, 4);
    printf("add: %d\n", res);

    printf("count: %d\n", count); // 10
}