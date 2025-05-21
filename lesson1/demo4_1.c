
/**
 * extern 关键字的用法
 * 1. 使用extern声明变量
 * 2. 使用extern声明方法
 */
#include <stdio.h>

/* 这两个变量在demo4_2.c中已经定义了, 现在想在本文件中使用 */
extern int num;
extern float pi;

/* 变量和方法都可以被修饰 */
extern void print();
extern void printMessage();

int x;
int y;

int add() 
{
    x = 1;
    y = 2;
    return x+y;
}

int main() 
{
    printf("num:%d\n", num);
    printf("pi: %f\n", pi);

    print();
    printMessage();

    puts("----------------------");

    int sum = add();
    printf("sum: %d\n", sum);

    return 0;
}
