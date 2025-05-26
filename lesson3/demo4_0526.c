/**
 * 结构体：用于定义一组不同类型的变量, 有点类似java中的bean
 * 1. 怎么定义一个结构体  func1()
 * 2. 结构体内容的初始化  func2()
 * 3. 结构体作为函数的参数 func3()
 * 4. 结构体指针 func4();
 */
#include <stdio.h>
#include <string.h>

void func1();
void func2();
void func3();

void func4();

struct Student {
    char name[20];      // 20bit 3byte 
    int age;            // 4byte
};

void printStudent(struct Student student);  // 函数声明中的结构体需要在声明之前

int main() {
    // func1();
    // func2();
    // func3(); 
    // func4();
    return 0;
}

void func1() {

    // 最常见的结构体模式
    struct Employee {
        char *name;
        char *id;
        int sex;
        float salary;
    } employee;

    // 结构体包含结构体
    struct Company {
        char *c_name;
        struct Employee employee1;
    };
    
    // 结构体包含指向自己的指针 常见的单链表结构
    struct NODE {
        int val;
        struct NODE *next;
    };
}

/*结构体初始化*/
void func2() {

    /* 1. 创建的时候初始化 */
    struct Student {
        char *name;
        int age;
    } s1 = {"chason", 18};  // 这种初始化的方式必须指定变量名 例如 s1

    printf("s1:[name=%s, age=%d]\n", s1.name, s1.age);

    /* 2. 先创建再初始化 */
    struct Person {
        char *firstName; 
        char lastName[10]; // 直接给定长度的就不需要初始化，可以直接strcpy
        int sex;
        int age;
    };

    struct Person p1;
    p1.firstName = "chason";   // 指针可以直接使用 = "xxxx" 进行初始化
    strcpy(p1.lastName, "eil");  // 字符数组不能直接使用 = "xxx", 需要使用 strcpy()
    p1.age = 18;
    p1.sex = 1;

    printf("p1:[name=%s %s, age=%d, sex=%d]\n", p1.firstName, p1.lastName, p1.age, p1.sex);
}

/**
 * 结构体作为函数的参数
 */
void printStudent(struct Student student) {
    printf("student:[name=%s, age=%d]\n", student.name, student.age);
}

void func3() {
    struct Student s1;
    strcpy(s1.name, "zhangsan");
    s1.age = 18;

    // 将结构体传递给函数
    printStudent(s1);
}

void func4() {

    struct Student s1;
    strcpy(s1.name, "zhangsan");
    s1.age = 18;

    struct Student *s1_ptr;
    s1_ptr = &s1;

    // 结构体指针使用 -> 访问成员
    printf("s1_ptr:[name=%s, age=%d]\n", s1_ptr->name, s1_ptr->age);
    printf("结构体大小:%dbytes\n", sizeof(s1_ptr));
}

