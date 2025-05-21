/**
 * 指针: 一个指向内存地址的变量
 * 1. 定义指针变量并输出地址 func1()
 * 2. 空指针 NULL func2()   
 *      怎么用指针定义字符串并输出?
 * 3. 指针的计算 ++ -- func3()
 *      关于 *p++ 和 ++*p
 * 4. 在数组中使用指针遍历 func4()
 * 5. 结构体指针 【结构体学完再来看】
 * 6. 指针的比较 func5()
 * 7. 仅通过指针遍历数组 func6()
 */
#include <stdio.h>

void func1();
void func2();
void func3();
void func4();
void func5();
void func6();

int main() {

    //func1();
    //func2();
    //func3();
    //func4();
    //func5();
    //func6();

    return 0;
}

/**
 * 指针变量没法直接给常量值 int *p = 10; 这种方式是错误的
 * 因为直接的值没有办法取地址
 */
void func1() {
    int number = 10;
    int *p;
    p = &number;

    printf("*p的值: %d\n", *p);
    printf("*p的地址:%p\n", p);
}

/**
 * 只有初始化为NULL的指针才是空
 * 没有初始化的 int *p; 指向随机地址
 */
void func2() {
    int *p = NULL;
    printf("空指针的地址:%p\n", p);  // nil

    int *p1;
    printf("没初始化的*p1:%p\n", p1);  // 随机地址
}

/*  ++ 操作指针大小每次增加对应数据类型的大小 */
// 这个特性在访问数组中的数据时特别有效
void func3() {
    int a = 10;
    int *p;
    p = &a;

    printf("p指针的内存地址: %p\n", p);
    p++;
    printf("++后的内存地址:%p\n", p);  // 地址前进了4
    p--;
    printf("--后的内存地址:%p\n", p); // 回到了原地址

    int number = 5;
    int *p1 = &number;

    printf("p1 addr:%p\n", p1);
    printf("p1 val: %d\n", *p1);

    ++*p1; // 执行顺序 *p1 然后++ 将原本的值 +1
    printf("++*p1 addr:%p\n", p1);      // 地址没有发生变化
    printf("++*p1 val: %d\n", *p1);     // val + 1

    int number1 = 8;
    int *p2 = &number1;

    printf("p2 addr:%p\n", p2);
    *p2++;  // 执行顺序 p2++ 再取值  p2是一个地址，地址++ 向后前进一个Int单位 4byte  值完全随机
    printf("*p2++ addr:%p\n", p2);      // 地址增加 int 4byte
    printf("*p2++ val:%d\n", *p2);      // 完全是一个随机的值
}

/* 在数组中使用指针遍历 */
void func4() {

    int arr[] = {5, 10, 20};
    int *p = arr; // arr 是数组， arr 是一个引用，指向数组的首地址 这里使用 &arr 也可以

    int i;
    for (i=0; i<3; i++) {
        printf("当前内存地址: %p\n", p);
        printf("当前地址值:%d\n", *p);
        p++;
    }

    char str[] = "Hello";  // 字符数组
    char *cp = str;

    // 输出第一个字符
    printf("first char:%c\n", *cp);

    cp++;
    // 输出第二个字符
    printf("second char:%c\n", *cp);

    // 输出整个字符串
    printf("%s\n", str);
}

/* 指针的比较 */
void func5() {

    int a = 10;
    int b = 10;
    int *p1 = &a;
    int *p2 = &a;
    int *p3 = &b;

    // 判断p1 p2两个指针的地址是不是相同
    if (p1 == p2) {
        printf("p1 == p2\n");
    } else {
        printf("p1 != p2\n");
    }

    if (p1 == p3) {
        printf("p1 == p3\n");
    } else {
        printf("p1 != p3\n");
    }

    int arr[] = {5, 10, 20};

    int *p = arr;       // 指向数组开头的位置
    int *q = &arr[2];   // 指向最后一个元素的位置

    printf("p的地址:%p\n", p);
    printf("q的地址:%p\n", q);

    if (p < q) {
        printf("p在q的前面\n");
    } else {
        printf("p在q的后面\n");
    }
}

/* 仅使用指针的方式遍历数组 */
void func6() {

    int arr[] = {5, 10, 20};

    int *start = arr;
    int *end = &arr[2];

    int *p;
    printf("arr: ");
    for (p = start; p <= end; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}