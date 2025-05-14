/*

1. define constant
2. define variables
3. create a simple method and use it 
4. input something then show it       
    advance: how to input string then show it?
    scanf no annotation and no \n!
5. define string 
6. define hong

*/

#include <stdio.h>

#define PI 3.14

// define a function
int add(int a, int b);

int main() 
{

    /* use const to define a constant */
    const int VAL = 10;  // constant we always use uppercase
    printf("VAL:%d\n", VAL);
    // VAL = 20; error ,const can not be changed.
    puts("---------------------------");

    // define a variable
    int num1 , num2, sum;
    num1 = 10;
    num2 = 20;
    sum = add(num1, num2);
    printf("Sum of two number:%d\n", sum);
    puts("---------------------------");

    printf("Please input two numbers:");
    scanf("%d %d", &num1, &num2);
    sum = add(num1, num2);
    printf("Sum of two number from input:%d\n", sum);
    puts("---------------------------");

    /* String */
    char str1[] = "Hello, C\n";
    printf("str1:%s\n", str1);

    char *ptr = "Hello, C1\n";
    printf("ptr: %s\n", ptr);
    puts("---------------------------");

    printf("PI:%f\n", PI);  // PI:3.140000
 
    return 0;
}

// implementation function
int add(int a, int b)
{
    return a + b;
}