/**
 * C内存管理 需要头文件 stdlib.h
 * void *calloc(int num, int size) 分配num个长度为size的连续空间并初始化为0
 * void free(void *address) 释放address地址的内存块
 * void *malloc(int num) 堆中分配指定大小的空间
 * void *realloc(void *addr, int new_size) 重新分配内存空间，将空间变成newsize 
 * 1. 尝试分配内存  func1()
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void func1();

int main() {

    func1();
    return 0;
}

/* 分配内存 */
void func1() {

    typedef struct {
        // name的空间是确定的
        char name[20];
        // addr是一个空指针，需要我们手动分配空间
        char *addr;
    } Student;

    Student student;

    strcpy(student.name, "chason");

    // 帮addr分配好空间
    student.addr = (char *)malloc(200 * sizeof(char)); // 分配200个char = 200bytes
    
    // student.addr = (char *)calloc(200, sizeof(char)); 也可以用来分配内存

    if (student.addr == NULL) {
        fprintf(stderr, "Malloc memory failed!");
        perror("message");
    }

    strcpy(student.addr, "Shanghai Pudong Lujiazui");

    printf("student: [name=%s, addr=%s]\n", student.name, student.addr);

    // 使用完需要回收内存
    free(student.addr);
}