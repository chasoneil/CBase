/**
 * I/O:
 * 1. 输出float保留指定位数  func1()
 * 2. getchar() putchar()   func2()
 * 3. gets() 和 fgets()   func3()
 */
#include <stdio.h>

void func1();
void func2();
void func3();

int main() 
{
    // func1();
    // func2();
    func3();
    return 0;
}

void func1() 
{

    float pi = 3.1415;
    // 传统的方式，小数点后6位
    printf("pi: %f\n", pi);     // 3.141500

    // 保留小数点后两位
    printf("pi: %.2f\n", pi);   // 3.14
}

/* getchar() putchar() */
void func2() 
{
    printf("请输入一个字符:");
    int ch = getchar();             // 只能获取第一个字符
    printf("你输入的字符是:%c\n", ch);
    printf("putchar输出:");
    putchar(ch);
    printf("\n");
}

/* gets() fgets() */
void func3() 
{
    // gets() 从标准输入读取字符串 不推荐使用, 推荐使用fgets()
    char str[50];
    printf("请输入字符串:");
    char *ptr = gets(str);
    printf("你输入的内容:%s\n", ptr);

    printf("请再次输入字符串:");
    fgets(str, sizeof(str), stdin);
    printf("你再次输入的内容:%s\n", str);

    

}

