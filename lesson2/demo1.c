/**
 * 1. 条件结构 switch case  func1()
 * 2. 循环结构 goto     func2()
 *      we do not recomand any goto statement.
 */

#include <stdio.h>

/* switch case */
void func1() {
    int num;
    printf("Please input a number:\n");
    scanf("%d", &num);      // 注意 & 不能丢

    switch (num) {
        case 0:
            printf("your input is 0\n");
            break;
        case 1:
            printf("your input is 1\n");
            break;
        default:
            printf("your input is not 0 and 1\n");
            break;
    }
}

/* goto */
void func2 () {
    int a = 10;
    while (a < 20) {
        a++;
        if (a == 15) {
            goto END;
        }
        printf("a=%d\n", a);
    }

    END: printf("func2 finished!\n");
}

int main() {
    // func1();
    func2();
    return 0;
}