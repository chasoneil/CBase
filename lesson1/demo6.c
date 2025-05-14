#include <stdio.h>

/*
    1. 使用指针修改变量的值
    2. ++*p 和 *p++
    3. 关于指针变量初始化
    Q: 给定一个字符串 使用char pointer, 输出字符串
*/
int main() 
{

    int a = 15, b = 20, c=25, *p;
    p = &a;   // 这时  *p == a
    *p = b;   // 等同于 a = b;
    c = *p;

    printf("%d %d %d %d\n", a, b, c, *p);

    puts("------------------------------");

    int *ptr = &a;
    printf("%d\n", ++*ptr);
    printf("%d\n", *ptr++);
    printf("%d\n", *ptr);       // 输出一个随机值，地址发生改变

    puts("------------------------------");

    // int *ptr1 = 10;  // 不能使用这种方式初始化， 10 是个常量不是引用，不是地址
    char *ptr1 = "Abc";  // 可以使用这种方式初始化
    printf("%c\n", *ptr1);

    puts("------------------------------");

    // Q: 给定一个字符串 使用char pointer, 输出字符串
    printf("%s\n", ptr1);  // 输出字符串 直接使用ptr1 即可

    return 0;
}