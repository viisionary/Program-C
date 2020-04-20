#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
类型	存储大小	值范围
char	              1 字节	-128 到 127 或 0 到 255  1111 1111
unsigned char	      1 字节	0 到 255
signed char	          1 字节	-128 到 127
int	                  2 或 4 字节	-32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647
unsigned int	      2 或 4 字节	0 到 65,535 或 0 到 4,294,967,295
short	              2 字节	-32,768 到 32,767
unsigned short	      2 字节	0 到 65,535
long	              4 字节	-2,147,483,648 到 2,147,483,647
unsigned long	      4 字节	0 到 4,294,967,295
float	              4 字节	1.2E-38 到 3.4E+38	6 位小数
double	              8 字节	2.3E-308 到 1.7E+308	15 位小数
long double           16 字节	3.4E-4932 到 1.1E+4932	19 位小数
 */

// 函数外定义变量 x 和 y
int x;
int y;

int addTwoNum() {
    // 函数内声明变量 x 和 y 为外部变量
//    extern int x;
//    extern int y;
    // 给外部变量（全局变量）x 和 y 赋值
    x = 1;
    y = 2;

    return x + y;
}

//auto
//register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
//static
//extern 所有文件可见
void array() {
    int balance[10] = {1000, 2, 3, 7, 50};
    balance[5] = 5;
    int a[3][4] = {
            {0, 1, 2,  3},   /*  初始化索引号为 0 的行 */
            {4, 5, 6,  7},   /*  初始化索引号为 1 的行 */
            {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
    };
    for (int i = 0; i < 11; ++i) {
        printf("result 为: %d \n", balance[i]);
    }
}

void dataTypeSize() {
    printf("int 存储大小 : %lu \n", sizeof(x));

}

void enumTest() {
    enum DAY {
        // 只能是int
                MON = -1, TUE, WED = 1, THU, FRI, SAT, SUN
    };
    enum DAY day;
    int a = 8;
    // int转enum
    day = (enum DAY) a;
    // same as
    // enum DAY (枚举名称可省)
    //{
    //      MON=1, TUE, WED, THU, FRI, SAT, SUN
    //} day;
//    day = TUE;
    printf("%d", day);

}

void point() {
    int var1;
    char var2[10];
    printf("var1 变量的地址： %p\n", &var1);
    printf("var2 变量的地址： %p\n", &var2);

    int var = 20;   /* 实际变量的声明 */
    int *ip;        /* 指针变量的声明 */
    ip = &var;  /* 在指针变量中存储 var 的地址 */
    printf("Address stored in ip variable: %p\n", ip);
    printf("Value of *ip variable: %d\n", *ip);
    int *ptr = NULL;
//    %p 输出地址
    printf("ptr 的地址是 %p\n", ptr);
}

// 回调函数
// 原数组的指针，长度， 回调
void populate_array(int *array, size_t arraySize, int (*getNextValue)(int)) {
    for (size_t i = 0; i < arraySize; i++)
        array[i] = getNextValue(i);
}

// 获取随机值
int getNextRandomValue(int a) {
    return a;
}

void callbackFnTest() {
    int myArray[10];
    populate_array(myArray, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++) {
        printf("%d ", myArray[i]);
    }
}

void stringTest() {
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greeting2[5];

    //#include <string.h>
    printf("Greeting message:");

//    strcpy(greeting2, greeting);
//    char *index = strchr(greeting2, 'e');
//    printf("出现在第%s个", greeting2);
}

int main() {
//    printf("Greeting message:");

    stringTest();
//    int result = addTwoNum();
//    enumTest();
//    point();

}
