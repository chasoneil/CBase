/**
 * 共用体：一种可以存放多种数据类型的结构
 * 1. 怎么定义一个共用体 func1()
 * 2. 初始化和使用结构体 func2()
 */
#include <stdio.h>

void func1();
void func2();

int main() {

    // func1();
    func2();
    return 0;
}

/* 定义共用体 */
void func1() {
    
    // 最常规的方式 和定义结构体类似
    union Data {    
        int i;
        float f;
        char name[20];
    } data;         // data 可以存 int float char[]中的一种数据
    
    printf("data size:%d\n", sizeof(data)); //20 按照最大的那个数据类型

    // 可以省略实例名
    union Data1 {
        int i;
        float f;
    };

    union Data1 d1;
    printf("d1 size:%d\n", sizeof(d1));

    // 可以都省略, 但是这种一般在结构体内部使用
    union {
        int i;
        float f;
    };
    
}

/* 初始化和使用union */
void func2() {

    union Data {
        int i;
        float f;
        char c[10];
    };

    union Data data;
    data.f = 3.14f;
    printf("data f:%f\n", data.f);

    data.i = 3;
    printf("data i:%d\n", data.i);
    printf("data f after i:%f\n", data.f);  // 当i被使用，原来的f就会被覆盖，因为使用的是同一段内存

    strcpy(data.c, "Hello C");
    printf("data c:%s\n", data.c);
}

void func3() {
    
}