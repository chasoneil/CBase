/**
 * C位域: 一种更节约空间的方式
 * 1. 使用位域 func1()
 */
#include <stdio.h>

void func1();

int main() {

    func1();
    return 0;
}

void func1() {

    /* 位域一般在结构体中 */
    struct Data {
        // 性别只有 0/1 男/女 使用int占用4bytes
        int sex;
        // age 0-100 最大也就占 6bit (0-127)
        int age;
    } data;

    // 传统方式这个结构体占用8 byte
    printf("data size: %d bytes\n", sizeof(data));

    // 使用位域
    struct Person {
        int sex : 1;
        int age : 1;
    } person = {1, 100};

    // 4 虽然占用了4 bytes 但只有7（1 + 6） 位被用来存储值
    printf("person size: %d bytes\n", sizeof(person));
    printf("person:[sex=%d, age=%d]\n", person.sex, person.age);
}