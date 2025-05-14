#include <stdio.h>

/**
 * 1. define array
 * 2. how to calculate arrary length
 * 3. 使用宏定义 array length
 * 4. 数组变量名和指针的转化
 * 5. 常见的多维数组： 2维数组
 * 
 */

#define LENGTH(arr) sizeof(arr) / sizeof(arr[0])

void testArray1();

void testArray2();

void testDArray();

void print_array(int arr[], int length);

int main() {
    testArray1();

    testArray2();
    testDArray();
    
    return 0;
}

void testArray1() {

    // int short[];  error! 定义的数组要指定空间

    int arr[3];  
    for (int i=0; i<3; i++) {
        arr[i] = i;
    }

    int arr_length = sizeof(arr) / sizeof(arr[0]);
    printf("arr length:%d\n", arr_length); 

    printf("LENGTH(arr):%d\n", LENGTH(arr));

    // 输出数组中每个元素的值
    printf("arr: ");
    for (int j=0; j<arr_length; j++) {
        printf("%d ", arr[j]);
    }

    printf("\n");
    puts("-------------------------------");

    // arr[] = {1, 2, 3};  error! 使用直接初始化数组的方式只能在定义的时候直接初始化
    char arr1[] = {'a', 'b', 'c'};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("arr1: ");
    for (int k=0; k<length1; k++) {    
        printf("%c ", arr1[k]);
    }

    printf("\n");
    puts("-------------------------------");
}

/* 数组类型的变量和指针的转化 */
void testArray2() {
    int arr[] = {3, 2, 1};
    int *arr_ptr = arr;  

    int length = sizeof(arr) / sizeof(arr[0]);
    // int *arr_ptr = arr[0];  使用这种方式也是支持的

    print_array(arr, length);
    puts("-------------------------------");
}

/* 在array的相关方法中，length 一般是传递进来的 */
void print_array(int arr[], int length) {

    printf("[");
    for (int i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void testDArray() {

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ",arr[i][j]);
        }
    }

    printf("\n");
}