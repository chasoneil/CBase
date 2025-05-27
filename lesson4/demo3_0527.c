/**
 * 文件读写
 * 1. fopen() fclose -> demo2.c
 * 2. fputc() fputs() 写入文件 func1()
 * 3. fgetc() fgets() fscanf() 读取文件 func2()
 * 4. fread() fwrite() 二进制读取和写入 func3()...
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func1();
void func2();
void func3();

int main() 
{
    // func1();
    // func2();
    func3();
    return 0;
}

/**
 * fputc(int c, FILE *fp)
 * fputs(const char *s, FILE *fp)
 */
void func1() 
{
    /* 如果文件不存在 会创建文件， 存在则文件长度被截断 */
    FILE *file = fopen("/chason/postgres/temp/test1.txt", "w+"); 
    int str_res = fputs("Hello, C.\n", file);
    if (str_res != EOF) {
        printf("字符串写入成功！\n");
    } else {
        printf("字符串写入失败！\n");
        return;
    }
    fclose(file);

    FILE *file1 = fopen("/chason/postgres/temp/test2.txt", "w+");
    int ch_res = fputc('a', file1);
    if (ch_res != EOF) {
        printf("字符写入成功！\n");
    } else {
        printf("字符写入失败！\n");
        return;
    }
    fclose(file1);
}

/**
 * fgetc(FILE *fp) 读取一个字符
 * fgets(char *buf, int n, FILE *fp) 读取指定的字符数 n个，读到缓冲区中
 * fscanf(FILE *fp, const char *format, ...) 从文件中读取字符，遇到空格或者换行停止
 */
void func2() 
{
    /* 允许文件读写 */
    FILE *file = fopen("/chason/postgres/temp/read.txt", "r+");

    int ch = fgetc(file);
    printf("fgetc: %c\n", ch); 
    fclose(file);

    file = fopen("/chason/postgres/temp/read.txt", "r+");
    char buf[21];
    fgets(buf, 20, file);   // 只会读一行数据
    printf("fgets-1: %s", buf);
    
    fgets(buf, 20, file);   // 继续读第二行数据
    printf("fgets-2: %s", buf);
    fclose(file);

    file = fopen("/chason/postgres/temp/read.txt", "r+");
    fscanf(file, "%s", buf);        // 这种读取方法遇到空格会中断
    printf("fscanf: %s\n", buf);
}

/**
 * size_t fread(void *ptr, size_t size, size_t number, FILE *file)
 * size_t fwrite(const void *ptr, size_t size, size_t number, FILE *file)
 * size : 每个数据单元的大小
 * number: 要读取的数量
 */
void func3() 
{
    FILE *fp;
    fp = fopen("/chason/postgres/temp/data.bin", "w+b");  // 二进制文件的读写
    if (fp == NULL) {
        printf("文件打开失败\n");
        return;
    }

    char *str = "Binary Test.";
    int len = strlen(str);
    size_t result = fwrite(str, strlen(str), 1, fp);
    if (result != 1) 
    {
        printf("写入失败\n");
        return;
    }

    printf("数据写入成功\n");
    fclose(fp);                 // 一定要先关闭文件，再打开文件，因为两种大开的方式不同

    fp = fopen("/chason/postgres/temp/data.bin", "rb");
    char buf[30];
    result = fread(buf, strlen(str), 1, fp);
    if (result != 1) 
    {
        printf("读取二进制文件失败\n");
        return;
    }
    printf("读取二进制文件的结果: %s\n", buf);

    fclose(fp);
}