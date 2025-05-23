/**
 * typedef 关键字：为类型取一个新的名字
 * 1. 怎么使用 func1()
 * 2. 常见用法： 定义结构体 和 枚举 func2()
 */
#include <stdio.h>

void func1();
void func2();

int main() 
{
    // func1();
    func2();
    return 0;
}

void func1() 
{
    // 为 unsigned char 取了个别名 CHAR 
    typedef unsigned char CHAR;

    CHAR ch1, ch2;
    ch1 = 'a';
    ch2 = 'A';

    printf("ch1:%c, ch2:%c\n", ch1, ch2); // ch1:a, ch2:A
}

/* typedef 定义结构体和枚举 */
void func2() {

    typedef struct Student 
    {
        unsigned int age;
        char name[20];
    } STUDENT;

    // 如果是常规模式 需要使用 struct Student student 比较麻烦
    STUDENT student;
    strcpy(student.name, "Zhangsan");
    student.age = 20;
    printf("student [name=%s, age=%u]\n", student.name, student.age);

    // 枚举
    typedef enum DAY {
        MON, TUE, WND, THR, FRI, SAT, SUN
    } Day;

    // 传统的方式是 enum DAY day;
    Day day;
    day = 3;
    printf("day=%d\n", day);

}