/**
 * 每种数据的类型的默认值 func1()
 */
#include <stdio.h>

void func1();

int *ptr1;

int main() {
    func1();
    /* global pointer */
    printf("global pointer:%p\n", ptr1);  // nil
    return 0;
}

/* 默认值 */
void func1() {
    int a;
    printf("a:%d\n", a);

    static int b;
    printf("b:%d\n", b);

    float f1;
    printf("f1: %f\n", f1);

    static float f2;
    printf("f2: %f\n", f2);

    char ch1;
    printf("ch1: %c\n", ch1);

    static char ch2;
    printf("ch2: %c\n", ch2);

    int *ptr;
    printf("*ptr: %p\n", ptr);  // nil 初始化为空指针
}

