#include <stdio.h>

/*
    1. 数组指针
    2. 遍历输出数组的元素
 */
int main() 
{
    // 数组指针其实就是当我们定义一个数组的时候的变量，他指向的是数组的第一个元素
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    // 输出数组的第一个元素
    printf("%d\n", *p);
    printf("%d\n", *arr);    // 在这里  * 表示取值

    char str[] = "hello world";
    char *p2 = str;

    // 输出字符串的第一个元素
    printf("%c\n", *p2);
    // 输出整个字符串
    printf("%s\n", str);

    puts("-------------------------------------");

    // 遍历输出数组的元素
    int length = sizeof(arr) / sizeof(arr[0]);
    // for (int i=0; i<length; i++) {
    //     printf("%d ", *arr+i);
    // }

    for (int i=0; i<3; i++) {
        printf("%d ", i);
    }
    
    return 0;
}