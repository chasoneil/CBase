/**
 * I/O:
 * 1. 输出float保留指定位数  func1()
 * 2. getchar() putchar()   func2()
 * 3. gets() 和 fgets()   func3()
 * 4. puts() 和 fputs()  fun4()
 * 5. fopen() 和 fclose() func5()
 */
#include <stdio.h>

void func1();
void func2();
void func3();
void func4();
void func5();

int main() 
{
    // func1();
    // func2();
    // func3();
    // func4();
    func5();
    return 0;
}

void func1() 
{

    float pi = 3.1415;
    // 传统的方式，小数点后6位
    printf("pi: %f\n", pi);     // 3.141500

    // 保留小数点后两位
    printf("pi: %.2f\n", pi);   // 3.14
}

/* getchar() putchar() */
void func2() 
{
    printf("请输入一个字符:");
    int ch = getchar();             // 只能获取第一个字符
    printf("你输入的字符是:%c\n", ch);
    printf("putchar输出:");
    putchar(ch);
    printf("\n");
}

/* gets() fgets() */
void func3() 
{
    // gets() 从标准输入读取字符串 不推荐使用, 推荐使用fgets()
    char str[50];
    printf("请输入字符串:");
    char *ptr = gets(str);
    printf("你输入的内容:%s\n", ptr);

    printf("请再次输入字符串:");
    fgets(str, sizeof(str), stdin);
    printf("你再次输入的内容:%s\n", str);
}

/**
 * puts(xxx) 将xxx输出到标准输出并自动添加换行
 * fputs(const char *str, stream) 将指定的字符串输出到指定流
 */
void func4() 
{
    char *str = "Hello output";
    puts(str);

    fputs(str, stdout);
    printf("\n");
}

/**
 * FILE fopen(const char *fileName, const *char mode) 用于打开一个文件
 * int fclose(const *file);
 */
void func5() 
{
    FILE *file;
    file =  fopen("/chason/postgres/temp/1.txt", "r");          // 文件运行在linux上
    if (file == NULL) {
        printf("文件打开失败!\n");
        return;
    }

    int res = fclose(file);
    if (res == EOF) {
        printf("关闭文件失败!\n");
    } else {
        printf("关闭文件成功!\n");
    }
}

