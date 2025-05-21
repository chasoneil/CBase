/**
 * 变量
 * 1. 定义变量和常量  func1()
 * 2. 怎么创建方法，调用方法 func2();
 * 3. 怎么从键盘输入数据并接收，有什么注意点  func3()
 * 4. 构建字符串和宏 func4()
 */
#include <stdio.h>

#define PI 3.14

// define a function
int add(int a, int b);

void func1();
void func2();
void func3();
void func4();

int main() 
{
    // func1();
    // func2();
    // func3();
    func4();
    return 0;
}

// implementation function
int add(int a, int b){
    return a + b;
}

/**
 * 定义常量和变量
 * 除此之外使用宏定义的也是常量
 */
void func1() {
    const int val1 = 10;  // constant
    int val2 = 10;
    // val1 = 15; error!  常量不能改
    val2 = 15;
    printf("val1: %d\n", val1);
    printf("val2: %d\n", val2);
}

/**
 * 创建方法并使用他
 */
void func2() {
    int val1 = 10;
    int val2 = 5;
    int res = add(val1, val2);
    printf("val1+val2=%d\n", res);
}

/**
 * 输入和输出
 */
void func3() {
    int input1;
    int input2;
    printf("Please input two numbers:\n");
    /*
        1. scanf 不能有提示词
        2. scanf 不能有\n
    */
    scanf("%d %d", &input1, &input2);
    int ans = add(input1, input2);
    printf("Your input: %d %d\n", input1, input2);
    printf("Sum of your input: %d\n", ans);
}

/**
 * 创建一个字符串和宏
 */
void func4() {

    // 使用字符数组
    char str[] = "Hello, C\n";
    printf("%s", str);

    // 使用指针
    char *ptr = "This is C pointer\n";
    printf("%s", ptr);

    // 宏可以定义在方法内，但是一般不这么做
    #define ME "chason"

    printf("ME:%s\n", ME);  // chason
    printf("PI:%f\n", PI);  // PI:3.140000
}