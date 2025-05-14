/*
1. define constant func1()
2. define variables func1()
3. create a simple method and use it  func2()
4. input something then show it       func3() 
    advance: how to input string then show it?
    scanf no annotation and no \n!
5. define string func4()
6. define hong
*/

#include <stdio.h>

#define PI 3.14

// define a function
int add(int a, int b);

void func1();
void func2();
void func3();

int main() 
{
    // func1();
    // func2();
    // func3();

    func4();

    printf("PI:%f\n", PI);  // PI:3.140000
 
    return 0;
}

// implementation function
int add(int a, int b)
{
    return a + b;
}

/**
 * 定义常量和变量
 */
void func1() {
    const int val1 = 10;  // constant
    int val2 = 10;
    // val1 = 15; error!
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
    scanf("%d %d", &input1, &input2);
    int ans = add(input1, input2);
    printf("Your input: %d %d\n", input1, input2);
    printf("Sum of your input: %d\n", ans);
}

/**
 * 创建一个字符串
 */
void func4() {

    // 使用字符数组
    char str[] = "Hello, C\n";
    printf("%s", str);

    // 使用指针
    char *ptr = "This is C pointer\n";
    printf("%s", ptr);
}