/**
 * C数据类型
 * 1. 基本数据类型： int char short long double float  func1()
 * 2. bool 类型     func2()
 * 3. sizeof()函数与 输出地址  func3()
 * 4. 获取float 和int类型的最大值和最小值  func3()
 * 5. 数据类型转化 (隐式、显式) func4()
 */



#include <stdio.h>
#include <float.h>
#include <limits.h>

#include <stdbool.h>

void func1();
void func2();
void func3();
void func4();

int main() {
    // func1();
    // func2();
    func3();
    // func4();
    return 0;
}

/**
 * 测试一些基本数据类型
 */
void func1() 
{
    int i1;
    unsigned int ui1;
    printf("int: %d\n", sizeof(i1));
    printf("uint: %d\n", sizeof(ui1));

    short s1;
    unsigned short us1;
    printf("short:%d\n", sizeof(s1));
    printf("ushort:%d\n", sizeof(us1));

    long l1;
    unsigned long ul1;
    printf("long:%d\n", sizeof(l1));
    printf("ulong:%d\n", sizeof(ul1));

    char c1 = 'a';
    unsigned char c2 = 'a';
    printf("char:%d\n", sizeof(c1));
    printf("uchar:%d\n", sizeof(c2));

    float f1 = 3.14;
    // unsigned float f2 = 3.14; error!
    printf("float:%d\n", sizeof(f1));

    double d1 = 3.14;
    // unsigned double d2 = 3.14; error!
    printf("double: %d\n", sizeof(d1));

    char str1[] = "Hello, C";
    printf("string size:%d\n", sizeof(str1));     // 10
}


/**
 * bool 类型
 */
void func2() {
    
    /*
        C中默认没有boolean类型，一般来说 = 0 意味着false !=0 意味着true
    */
    int t1 = -1;
    int t2 = 1;
    int f1 = 0;
    
    if (t1) {
        printf("t1 true\n");
    } else {
        printf("t1 false\n");
    }

    if (t2) {
        printf("t2 true\n");
    } else {
        printf("t2 false\n");
    }

    if (f1) {
        printf("f1 true\n");
    } else {
        printf("f1 false\n");
    }

    /* C在 <stdbool.h> 中引入了bool类型 */

    bool flag = true;
    if (flag) {
        puts("true");
    } else {
        puts("false");
    }
}

/**
 * 1. sizeof()与输出地址
 * 2. int 类型的最大最小值 <limit.h>
 * 3. float类型的最大最小值 <float.h>
 */
void func3() {

    /* sizeof()： 字段大小，数组总空间，字符串长度 */
    int num = 5;
    printf("sizeof 5:%d\n", sizeof(num));

    int arr[] = {3, 2, 4, 5};
    printf("arr len:%d\n", sizeof(arr));    // 16

    char str[] = "Hello C";
    printf("str len:%d\n", sizeof(str));    // 8

    int a = 10;
    char ch = 'a';
    printf("int addr: %#X\n", &a);      // base type need &
    printf("char addr:%#X\n", &ch);

    char str1[20] = "MyStringTest";
    printf("string addr:%#X\n", str1);

    /*need float.h*/
    printf("Type float max: %E\n", FLT_MAX);
    printf("Type float min: %E\n", FLT_MIN);

    /* int max and min (need limits.h) */
    printf("int max:%d\n", INT_MAX);
    printf("int min:%d\n", INT_MIN);
}

/**
 * 数据类型转换
 */
void func4() {

    // 1. 大类型 -> 小类型 丢失精度
    float f1 = 3.14;
    int i1 = (int) f1;
    printf("i1:%d\n", i1);  // 3

    // 2. 小 -> 大  增加了精度
    int i2 = 3;
    float f2 = (float) i2;
    printf("f2:%f\n", f2);  // 3.000000

    // 3. 不同的数据类型做计算根据接收的类型决定
    int i3 = 1;
    float f3 = 1.2;

    int res1 = i3 + f3;
    float res2 = i3 + f3;
    printf("res1:%d\n", res1);  // 2
    printf("res2:%f\n", res2);  // 2.200000
}