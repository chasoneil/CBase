/**
 * 预处理
 * #include 
 * #define #undef #ifdef #ifndef  func1()
 * #if #else #elif #endif   func2()
 * #error
 * #pragma
 * 预定义的宏 func3()
 * 宏的其他用法 func4()
 */
#include <stdio.h>

void func1();
void func2();
void func3();
void func4();

int main() 
{
    // func1();
    // func2();
    // func3();
    func4();
    return 0;
}

void func1() 
{
    #define PI 3.14
    #define T 3
    printf("PI: %.2f\n", PI);
    printf("T: %d\n", T);
    #undef T

    // printf("T: %d\n", T); error!

    #ifdef PI
        printf("定义了 PI\n");
    #endif

    #ifndef T
        printf("没有定义 T\n");
    #endif

    #ifndef MESSAGE
        #define MESSAGE "Your message!"
    #endif 

    #ifdef DEBUG
        /* 只有在DEBUG模式下才会运行的代码 */
    #endif

}

/**
 * #if 如果条件为true 则编译代码
 */
void func2() 
{
    int num = 10;
    #if num > 8
        #define MESSAGE ">8"
    #elif num < 0
        #define MESSAGE "<0"
    #else
        #define MESSAGE "other"
    #endif

    printf("message: %s\n", MESSAGE);
}

/**
 * 系统预定义的宏
 */
void func3() 
{
    printf("FILE: %s\n", __FILE__);  // 文件绝对路径
    printf("DATE: %s\n", __DATE__);
    printf("TIME: %s\n", __TIME__);
    printf("LINE: %d\n", __LINE__);  // 当前代码所在行数
    printf("ANSI: %d\n", __STDC__);
}

/**
 * 1. \ 宏拼接
 * 2. # 字符串常量化运算符
 * 3. 使用宏定义方法
 */
void func4() 
{
    #define message_for(a, b) \
        printf(#a " and " #b " are good friends.")  // #a #b 将会被替换成传入的字符串常量

    message_for("chason", "fox");   // chason and fox are good friends.

    #define square(x) ((x) * (x))   // 使用宏定义方法

    int res = square(3);
    printf("3 square: %d\n", res);
}