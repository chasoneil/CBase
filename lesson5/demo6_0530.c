/**
 * C的命令行参数
 * 1. 通过主函数传递 main(int count, char *args[]) func1()
 */
#include <stdio.h>

void func1();

int main(int count, char *args[]) {

    func1(count, args);
    return 0;
}

/**
 * 至少有一个参数，执行程序本身
 * 其他参数通过空格分割，如果中间有空格，则参数的数量 + 1
 * 如果参数中有空格，那么就需要使用双引号将参数括起来 "a b" 这样也是一个参数
 */
void func1(int count, char *args[]) {
    printf("参数的数量:%d\n", count);
    int i;
    printf("参数值: ");
    for (i=0; i<count; i++) {
        printf("%s\n", args[i]);
    }
}