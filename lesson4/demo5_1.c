#include <stdio.h>
#include "demo5_1.h"
/**
 * 文件中是真实的实现，宏定义的内容
 * 方法的声明
 * 全局变量等放在头文件中
 */

int max(int a, int b) 
{
    return a > b ? a : b;
}

int add(int a, int b) 
{
    return a+b;
}

void print_message() 
{
    printf("message\n");
}