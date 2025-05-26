/**
 * 字符串 结束的标识 "\0"
 * 1. 定义一个字符数组，以数组和字符串的形式输出
 * 2. 常见的字符串函数
 *      strcpy(dst, src);
 *      strcat(s1, s2);
 *      strlen(s1);
 *      strchr(s1, c1);
 *      strstr(s1, s2);
 *      strcmp(s1, s2);
 */
#include <stdio.h>
#include <string.h>

void func1();

int main() {

    // func1();
    func2();
    return 0;
}

void func1() {

    // 定义了一个 char 数组
    char arr[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    int i;
    for (i=0; i<5; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");

    // 以字符串的形式输出
    printf("%s\n", arr);
}

/* 字符串常见函数 */
void func2() {

    char *s1 = "abc";
    // char *s2;
    char cp[4];
    strcpy(cp, s1);
    // strcpy(s2, s1); error 申请的指针没有初始化是 nil,就算初始化了，也是个只读的内存，不能改
    printf("%s\n", cp);
    
    char str1[] = "Hello";
    char str2[8];
    char str3[] = " World";

    char str4[] = "Hello1";
    char str5[] = "Iello";

    // 将 str1 copy 到 str2
    strcpy(str2, str1);
    printf("str1:%s\n", str1);
    printf("str2:%s\n", str2);

    // 连接字符串 将str3连接到str1的末尾
    strcat(str1, str3);
    printf("str1: %s\n", str1);

    // strcmp(a, b) a==b return 0 ; a<b return below 0 ; a>b return above 0
    /* result: -49 -1 说明和长度先后都有关系 */
    printf("Hello vs Hello1: %d\n", strcmp(str2, str4));
    printf("Hello vs Iello: %d\n", strcmp(str2, str5));

    // strchr(str, ch)
    // 返回的是一个指针，指向ch第一次出现的位置，如果想要知道在字符串中的位置，需要减掉字符串本身
    char ch = 'l';
    char *res = strchr(str4, ch);
    if (res == NULL) {
        printf("字符串中不存在该字符\n");
    } else {
        printf("存在字符，位置为:%d\n", res - str4);
    }

    // strstr(str1, str2) 
    // 返回一个指针，上面函数的高级形式，判断一个字符串在另一个字符串中首先出现的位置

    char *p_str1 = "abcdacdaca";
    char *p_str2 = "c1d";
    char *s_res = strstr(p_str1, p_str2);

    if (s_res == NULL) {
        printf("字符串中不存在该子字符串\n");
    } else {
        printf("存在子串，位置为: %d\n", s_res - p_str1);
    }

    // strlen(str1) 获取字符串的长度
    int len = strlen(p_str1);
    printf("p_str1 len:%d\n", len);
}