/**
 * 指针高级
 * 1. 指针遍历字符串数组  func1()
 * 2. 定义指针数组，并初始化数据 func2()
 * 3. 指向指针的指针 (双指针)  func3()
 * 4. 向函数传递指针 func4()
 * 5. 向函数传递一个数组指针，并遍历这个数组 func5()
 */
#include <stdio.h>

void func1();
void func2();
void func3();
void func4(int *p, char *str);
void func5(int *arr[], int size);

int main() {

    // func1();
    // func2();
    // func3();

    // int num = 10;
    // char *str = "Hahaha";
    // func4(&num, str);

    int *arr[] = {1, 2, 3};
    func5(arr, 3);

    return 0;
}

/**
 * 使用指针遍历字符串数组
 */
void func1() {

    /*定义字符串数组*/
    char *names[] = {"Chason", "Bob", "Fox"};
    int i;
    for (i=0; i<3; i++) {
        printf("names:[%d]: %s\n", i+1, names[i]);
    }
}

/**
 * 指针数组
 * 定义单个数的时候 
 * int a = 10;
 * int *p;
 * p = &a;
 * 现在变成了数组而已
 */
void func2() {

    int num1 = 10, num2 = 20, num3 = 30;

    // 先定义再初始化
    int *ptr[3];
    ptr[0] = &num1;
    ptr[1] = &num2;
    ptr[2] = &num3;

    int i;
    for (i=0; i<3; i++) {
        printf("*ptr[%d]: %d\n", i, *ptr[i]);
    }

    // 定义并初始化
    int *arr[] = {1, 2, 3};
    for (i=0; i<3; i++) {
        printf("%d\n", arr[i]);
    }
}

/**
 * 双指针
 */
void func3() {

    int num = 10;
    int *p1 = &num;

    int **p2;   // 如果是 *p2 那么他的值是p1地址的值
    p2 = &p1;

    printf("p1 val: %d\n", *p1);
    printf("p1 addr: %p\n", p1);

    printf("p2 val: %d\n", **p2);
    printf("p2 addr val: %d\n", *p2);   // random value
    printf("p2 addr: %p\n", p2);
}

/* 向函数传递指针 */
void func4(int *p, char *str) {

    if (*p < 0) {
        printf("under 0\n");
    } else if (*p == 0) {
        printf("equal 0\n");
    } else {
        printf("above 0\n");
    }

    printf("%s\n", str);
}

/* 传入数组指针并遍历 */
void func5(int *arr[], int size) {

    if (size == 0) {
        printf("arr is empty.");
    } else {
        int i;
        for (i=0; i<size; i++) {
            printf("%d\n", arr[i]);
        }
    }

}