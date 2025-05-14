/**
 * 1. 使用传值的方式调用函数并不会改变值本身 （和java不同） -> swap()
 * 2. 使用传递引用的方式(地址), 会改变值，因为相当于指针发生了变化 -> swap1()  
 * 
 * 3. 函数的声明可以在主函数内 func1()
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

int main() {

    int a = 10;
    int b = 8;

    int x = 10;
    int y = 8;

    // swap(a, b);
    // swap1(&x, &y);

    // printf("主函数中: a=%d, b=%d\n", a, b);     // a = 10, b = 8 主函数中不变
    // printf("主函数中: x=%d, y=%d\n", x, y);

    int func1(int, int); // 如果加上这句，那么编译中的未声明函数的警告就消失了

    int res = func1(a, b);
    printf("res = %d\n", res);

    return 0;
}

int func1(int a, int b) {
    if (a > b) {
        return a + b;
    } else {
        return a - b;
    }
}