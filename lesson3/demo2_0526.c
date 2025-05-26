/**
 * 函数指针：一个指针，本质上是一个函数的入口
 * 1. 怎么定义函数指针: returnType (*fun_ptr_name)(param...);  func1()
 *    怎么使用函数指针: fun_ptr_name = &fun_name;
 * 回调函数：在函数的参数中传入一个函数指针(参数是一个函数)，在这个函数中就可以使用传入的函数指针这个函数 
 * 2. 传入回调函数并使用，回调函数是一个函数指针 func2()
 * 3. 有参数的函数指针使用 func3()
 */
#include <stdio.h>

int max(int a, int b);

void calling();
void doFilterNumber(int *arr[], int size, void (*callBack)(void));
void help1(int);

void func1();
void func2();
void func3();

int main() {
    // func1();
    // func2();
    func3();
    return 0;
}

/* 使用回调函数 */
void func2() {
    int *arr[] = {1, 4, 11, 8};
    doFilterNumber(arr, 4, calling);
}

// 怎么使用函数指针
void func1() {
    int (*m)(int, int) = &max; // *m 是一个函数指针 指向max函数
    int a = 10;
    int b = 20;
    int res = m(a, b);  // 通过指针调用
    printf("two max:%d\n", res);

    int c = 25;
    int res1 = m(m(a, b), c);
    printf("three max:%d\n", res1);
}

/* 比较两个整数谁大 */
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

/**
 * 创建函数指针并调用有参函数help1
 */
void func3() 
{
    void (*help)(int num) = &help1;
    int number = 18;
    help(18);
}

void help1(int number) {
    printf("do help1:%d\n", number);
}


