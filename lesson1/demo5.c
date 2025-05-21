/**
 * 存储类型关键字： auto register static extern
 * auto : 局部变量的默认类型  func1()
 * register: 被定义的变量 【可能】 存放在寄存器中(CPU缓存，而非内存RAM) | 他有更快的访问速度，但是他没有地址，无法通过地址获取，且大小受限 func1()
 * static: 修饰局部变量 -> 该变量在生命周期一直存在，不会因为方法暂时离开而销毁，每次也不会重置值  func2()
 *         修饰全局变量 -> 该变量的同文件的所有方法都能访问, 被修饰的变量只能本文件访问，其他文件不能通过extern访问了
 * extern： 见demo4
 * 运算符 && || ！, 三目运算符
 */

#include <stdio.h>
#include <stdbool.h>

// count 只能本文件访问，其他文件不能访问
static int count = 10;

void func1();
void func2();
void func3();

void doWork();

/* auto 与 register */
void func1() {
    int a = 10;
    auto int b = 20;  // 和 int b = 20; 本质上没有什么区别

    printf("a=%d, b=%d\n", a, b);

    // ch 将可能被存放在寄存器中, 如果被放在寄存器中，ch 没有内存地址
    register char ch = 'a';
    printf("ch:%c\n", ch);
    // printf("ch addr:%p\n", &ch); 报错，寄存器变量没有地址！
}

void func2() {
    while (count--) {
        doWork();
    }
}

void doWork() {
    // static 修饰的局部变量不会每次都重置，所以++会一直增加
    static int start = 5;
    start++;
    printf("start=%d, count=%d\n", start, count);
}

// 运算符
void func3() {

    int a = 7;
    int b = 5;

    /* 取余操作 */
    printf("a%b=%d\n", a % b);
    printf("a/b=%d\n", a / b);

    /* 逻辑运算符 */
    bool flag1 = true;
    bool flag2 = false;

    if (flag1 && flag2) {
        puts("all true");
    } else if (flag1 || flag2) {
        puts("one true");
    } else {
        puts("all false");
    }

    // 三目运算符
    int res;
    res = flag1 ? 1 : 2;    // 这里可以返回int 怎么返回字符串
    printf("%d\n", res); 

    // 如果你想使用一个字符串接住他，用字符数组不行，要用指针
    // 这里使用 char ans[] 会报错 
    char *ans = flag1 ? "real" : "lie";
    printf("%s\n", ans);
}

int main() {
     func1();
    // func2();
    // func3();
    return 0;
}