/**
 * C语言的错误处理
 * C提供errno,0表示没有错误 
 * 1. 使用perror() 获取系统提供的错误信息  func1()
 * 2. C语言是自己判断可能出现的错误，返回对应的值 func2()
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>

void func1();
int func2();

int main() 
{
    // func1();
    func2();
    return 0;
}

/* perror and fprintf and strerror */
void func1() 
{
    FILE *file = fopen("D:/temp/1.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "errno: %d\n", errno);
        /* perror会将错误信息直接输出 */
        perror("perror message");     // perror message: No such file or directory  
        /* strerror 会根据错误码输出错误信息，需要头<string.h> */
        fprintf(stderr, "error message: %s\n", strerror(errno));  // error message: No such file or directory
    } else {
        printf("success open file");
        fclose(file);
    }
}

/* 根据返回值判断是否执行成功 */
int func2() 
{
    int num1 = 10;
    int num2 = 0;

    int result;
    // 自己去判断可能发生的问题
    if (num2 == 0) {
        fprintf(stderr, "num2 is 0\n");
        // exit(-1);
        return -1;
    } 
    result = num1 / num2;
    return 0;
}