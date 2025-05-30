/**
 * C语言中的未定义行为
 * 1. 出现错误  func1()
 */
#include <stdio.h>
#include <errno.h>

void func1();

int main() {
    func1();
    return 0;
}

/**
 * 数组越界访问
 */
void func1() {
    int arr[] = {1, 2, 3};
    printf("%d\n", arr[4]);     // 数组越界，出现未定义行为,但是可以正常输出，也没有错误信息
    perror("error message:");
}