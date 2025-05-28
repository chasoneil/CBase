/**
 * 可变参数
 * 1. 怎么定义和使用可变参数?  func1()
 * 2. 使用可变参数的形式编写一个获取平均数的函数  func2()
 */
#include <stdio.h>
#include <stdarg.h>

void func1();
void func2();

void method1(int count, ...);
int get_average(int count, ...);

int main() {
    // func1();
    func2();
    return 0;
}

/* 使用可变参数需要 stdarg.h */
void func1() {
    // 4个参数
    method1(4, 3, 4, 5, 8);
}

void func2() {
    int avg = get_average(3, 5, 7, 9);
    printf("平均数是:%d\n", avg);
}

/**
 * 使用... 定义可变参数
 * func(int count, ...) 
 * count 表示参数的个数
 * ... 可以添加count个对应的参数
 */ 
void method1(int count, ...) {

    // stdarg.h 中定义的宏
    va_list lists;

    // va_start() 是头文件中定义好的
    va_start(lists, count);  // 初始化参数列表

    int i;
    for (i=0; i<count; i++) {
        printf("param:%d\n", va_arg(lists, int)); // 获取参数列表中的每个值
    }
    
    va_end(lists); // 清理内存
}

int get_average(int count, ...) {

    va_list lists;

    va_start(lists, count);

    int i;
    int sum = 0;
    for (i=0; i<count; i++) {
        sum += va_arg(lists, int);
    }
    va_end(lists);

    return sum / count;
}