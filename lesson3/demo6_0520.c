/**
 * C位域: 一种更节约空间的方式，把一个字节的二进制位分成几个区域，每个区域对应不同的值
 * 
 * 1. 定义位域 func1()
 * 2. 使用位域 func2()
 * 3. 位域的存放规则 func3()
 */
#include <stdio.h>

void func1();
void func2();
void func3();

int main() {

    // func1();
    // func2();
    func3();

    return 0;
}

void func1() {

    /* 位域一般在结构体中 */
    struct Data {
        // 性别只有 0/1 男/女 使用int占用4bytes
        int sex;
        // age 0-100 最大也就占 6bit (0-127)
        int age;
    } data;

    // 传统方式这个结构体占用8 byte
    printf("data size: %d bytes\n", sizeof(data));

    // 使用位域
    struct Person {
        int sex : 1;  // 每个变量的宽度为1位
        int age : 6;
    } person;

    // 4 虽然占用了4 bytes 但只有7（1 + 6） 位被用来存储值
    printf("person size: %d bytes\n", sizeof(person));
}

/* 使用位域 */
void func2() {
    
    struct Data {
        unsigned int i1 : 1;
        unsigned int i2 : 1;
        unsigned int age : 7;
    };

    // 位域不能直接通过初始化结构体赋值
    struct Data data;
    data.i1 = 1;
    data.i2 = 0;
    data.age = 100;

    printf("size: %d\n", sizeof(data));
    printf("data [i1=%u, i2=%u, age=%u]\n", data.i1, data.i2, data.age);

    // 如果超过了位域的位数，会警告但不会直接报错

    data.i1 = 2;
    printf("data [i1=%u]\n", data.i1); // 0 因为进位关系 最低位 = 0
    data.i1 = 3;
    printf("data [i1=%u]\n", data.i1); // 1
    printf("data [i1=%u, i2=%u, age=%u]\n", data.i1, data.i2, data.age);
}

/**
 * 一个位域存放在同一字节中，如果不够，则自动从下一个字节开始的位置开始存放
 * 也可以指定某些位域不存放
 */
void func3() 
{
    /**
     * 第一个字节 4位存放a
     * 后面四个字节不存放内容
     * b从第二个字节开始
     */
    struct Data 
    {
        unsigned int a : 4;
        unsigned       : 4; // 空域
        unsigned int b : 4;
    };

}