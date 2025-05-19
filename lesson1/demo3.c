/*

1. data type (base, void, enum, other)   func1()
    C 语言中, bool 类型是通过 int 来指定的，!=0为true ==0为false  func2()
    引入 <stdbool.h> 之后通过bool定义
2. sizeof() func1()
3. max and min  (float)   func1()
    How to print int max?
4. output address   func3()
5. data type transfer func3()
*/
#include <stdio.h>
#include <float.h>
#include <limits.h>

#include <stdbool.h>

void func1();
void func2();
void func3();

int main() {
    func1();
    // func2();
    // func3();
    return 0;
}

/**
 * 测试基本数据类型
 */
void func1() 
{
    int i1;
    unsigned int ui1;
    printf("int: %d\n", sizeof(i1));
    printf("uint: %d\n", sizeof(ui1));
    puts("------------------------------");

    short s1;
    unsigned short us1;
    printf("short:%d\n", sizeof(s1));
    printf("ushort:%d\n", sizeof(us1));
    puts("------------------------------");

    long l1;
    unsigned long ul1;
    printf("long:%d\n", sizeof(l1));
    printf("ulong:%d\n", sizeof(ul1));
    puts("------------------------------");

    char c1 = 'a';
    unsigned char c2 = 'a';
    printf("char:%d\n", sizeof(c1));
    printf("uchar:%d\n", sizeof(c2));
    puts("------------------------------");

    float f1 = 3.14;
    // unsigned float f2 = 3.14; error!
    printf("float:%d\n", sizeof(f1));
    puts("------------------------------");

    double d1 = 3.14;
    // unsigned double d2 = 3.14; error!
    printf("double: %d\n", sizeof(d1));
    puts("------------------------------");

    char str1[] = "Hello, C\n";
    printf("string size:%d\n", sizeof(str1));     // 10
    puts("------------------------------");

    printf("Type float max: %E\n", FLT_MAX);
    printf("Type float min: %E\n", FLT_MIN);
    puts("------------------------------");

    /* int max and min (need limits.h) */
    printf("int max:%d\n", INT_MAX);
    printf("int min:%d\n", INT_MIN);

}

void func2() 
{
    int a = 1;
    if (a) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    int b = 0;
    if (b) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    int c = -1;
    if (c) {
        printf("true\n");
    } else {
        printf("false\n");
    }


    puts("---------------------------------");

    bool flag = true;
    if (flag) {
        puts("true");
    } else {
        puts("false");
    }
}

/**
 * 强制类型转换
 */
void func3() {
    int a = 10;
    char ch = 'a';
    printf("int addr: %#X\n", &a);      // base type need &
    printf("char addr:%#X\n", &ch);

    char str[20] = "MyStringTest";
    printf("string addr:%#X\n", str);
    puts("------------------------------");

    // big -> small
    double d2 = 3.14;
    int i2 = (int)d2;
    printf("i2 :%d\n", i2);

    // small -> big
    int i3 = 10;
    double d3 = (double)i3;
    printf("d3: %f\n", d3);

    // default  
    int i4 = 10;
    float f2 = 3.14;
    int sum1 = i4 + f2;
    float sum2 = i4 + f2;
    printf("sum1: %d\n", sum1);
    printf("sum2: %f\n", sum2);
}