/**
 * C语言递归
 * 1. 使用递归计算阶乘          func1()
 * 2. 使用递归计算斐波那契数列   func2()
 */
#include <stdio.h>

void func1();
void func2();

int fac();
int fab();

int main() {
    // func1();
    func2();
    return 0;
}

void func1() {
    int number = 4;
    int res = fac(4);
    printf("%d的阶乘:%d\n", number, res);
}

void func2 () {
    int number = 10;
    int res;
    int i;
    printf("%d位的斐波那契数列:\n", number);
    for (i=0; i<number; i++) {
        res = fab(i);
        printf("%d\n", res);
    } 
}

/* 计算n的阶乘 */
int fac(int n) {

    if(n == 1) {
        return 1;
    }

    return n * fac(n-1);
}

/* 斐波那契数列 */
int fab(int n) {

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fab(n-1) + fab(n-2);
}

