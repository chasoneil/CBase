/**
 * 值传递和引用传递
 * 1. 使用传值的方式调用函数并不会改变值本身 （和java不同） -> func1()
 * 2. 使用传递引用的方式(地址), 会改变值，因为相当于指针发生了变化 -> func2() 
 * 
 * 在函数内声明函数 func3()
 */
#include <stdio.h>

/* 传值的方式只会影响函数内 */
void swap(int a, int b) {
    if (a == b) {
        return;
    }

    printf("交换前:a=%d, b=%d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("交换后:a=%d, b=%d\n", a, b);
}

/* 引用传递的方式则会影响主函数 */
void swap1(int *x, int *y) {

    if (&x == &y) {
        return;
    }
    printf("交换前:x=%d, y=%d\n", *x, *y);
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("交换后:x=%d, y=%d\n", *x, *y);
}

/* 值传递 */
void func1() {
    int a = 10;
    int b = 8;
    swap(a, b);
    printf("退出交换:a=%d, b=%d\n", a, b);
}

/* 引用传递 */
void func2() {
    int x = 10;
    int y = 8;
    swap1(&x, &y);
    printf("退出交换:x=%d, y=%d\n", x, y);
}

/* 函数内部声明函数 */
void func3() {

    void test(int);
    test(3);

}

void test(int a) {
    printf("This is test, %d\n", a);
}

int main() {

    // func1();
    // func2();
    func3();
    return 0;
}