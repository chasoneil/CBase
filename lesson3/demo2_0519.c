/**
 * 函数指针：一个指针，本质上是一个函数的入口
 * 1. 怎么定义函数指针: typedef int (*fun_ptr)(int, int);
 * 
 * 回调函数：在函数的参数中传入一个函数指针(参数是一个函数)，在这个函数中就可以使用传入的函数指针这个函数
 * 
 */
#include <stdio.h>

int max(int a, int b);

void calling();
void doFilterNumber(int *arr[], int size, void (*callBack)(void));

void func1();
void func2();

int main() {
    // func1();

    func2();
    return 0;
}

void func2() {
    int *arr[] = {1, 4, 11, 8};
    doFilterNumber(arr, 4, calling);
}

// 怎么使用函数指针
void func1() {
    int (*m)(int, int) = &max; // *m 是一个函数指针 指向max函数
    int a = 10;
    int b = 20;
    int res = m(a, b);
    printf("two max:%d\n", res);

    int c = 25;
    int res1 = m(m(a, b), c);
    printf("three max:%d\n", res1);
}

int max(int a, int b) {
    return a > b ? a : b;
}

void doFilterNumber(int *arr[], int size, void (*callBack)(void)) {
    int i;
    for (i=0; i<size; i++) {
        printf("check number:%d\n", arr[i]);
        // 触发回调机制
        if (arr[i] > 10) {
            callBack();
        }
    }
}

void calling() {
    printf("calling executed!\n");
}


