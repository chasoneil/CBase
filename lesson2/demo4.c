/**
 * 枚举
 * 1. 定义枚举的多种方式 func1()
 * 2. 枚举值的规则 和枚举的使用  func1()
 * 3. 遍历枚举中的元素  func2()
 * 4. 枚举和switch的配合使用 func3()
 * 5. 枚举和整形的转换 func4()
 */
#include <stdio.h>

void func1();
void func2();
void func3();
void func4();

 /* 可以使用宏定义出类似枚举的功能 */
#define A 1
#define B 2

int main() {

    func1();
    func2();
    func3();
    func4();

    return 0;
}

/* 多种定义枚举的方式 */
void func1() {
    /* 如果只定义枚举名 没有具体的值，会报错 */
    // enum DAY day;

    /* 如果不定义的话，枚举的值从0开始 */
    enum DAY {
        MON = 1, TUE, WND, THR, FRI, SAT, SUN
    };

    printf("Mon:%d\n", MON);

    /* 如果其中有一个重新定义了值，那么后面的从这个值开始 + 1 */
    enum SEASON {
        spr, sum, aut = 4, win
    }; 

    // 0 1 4 5
    printf("spr:%d\n", spr);
    printf("sum:%d\n", sum);
    printf("aut:%d\n", aut);
    printf("win:%d\n", win);

    /* 定义枚举的时候定义枚举名和值 可以只定义枚举名，只定义枚举值，或者名和值都不定义*/
    enum COLOR {
        green = 1, blue, yellow, red, pink
    } color;

    enum {
        Shanghai, Beijing, Shenzhen, Guangzhou 
    };

    // 枚举的使用
    enum DAY day;
    day = THR;

    printf("Today: %d\n", day);
}

/* 遍历枚举中的元素 */
void func2() {
    enum DAY {
        MON = 1, TUE, WND, THR, FRI, SAT, SUN
    };

    enum DAY day;

    /* 枚举值没有发生断层的变化的时候可以遍历 */
    for (day = MON; day <= SUN; day++) {
        printf("DAY:%d\n", day);
    }
}

/* enum and switch */
void func3() {

    enum COLOR {
        green = 1, blue, yellow, red, pink
    } color;

    printf("请输入你喜欢的颜色: 1. green, 2. blue, 3. yellow, 4. red, 5. pink \n");
    int favorate_color;
    scanf("%d", &favorate_color);

    switch (favorate_color)
    {
    case green:
        printf("Your favorate color is green\n");
        break;
    case blue:
        printf("Your favorate color is blue\n");
        break;
    case yellow:
        printf("Your favorate color is yellow\n");
        break;
    case red:
        printf("Your favorate color is red\n");
        break;
    case pink:
        printf("Your favorate color is pink\n");
        break;
    default:
        printf("Your favorate color is other\n");
        break;
    }
}

/* 将整数转换成枚举 */
void func4() {

    enum DAY {
        MON = 1, TUE, WND, THR, FRI, SAT, SUN
    };

    int today = 3;
    enum DAY day;

    /* 上下两种方式都可以 */
    // day = (enum DAY) today;
    day = today;  

    printf("Today: %d\n", day);
}