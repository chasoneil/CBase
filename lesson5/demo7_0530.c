/**
 * C 安全函数
 * 安全函数是普通函数的安全版本，主要包含字符串操作；格式化输出；内存操作；
 * 1. 安全函数的用法 func1()
 */
#include <stdio.h>
#include <string.h>

void func1();

int main() {

    func1();
    return 0;
}

void func1() {
    
    char buf[100];
    char *str = "Hello";

    strcpy_s(buf, str);
    printf("%s\n", buf);

}