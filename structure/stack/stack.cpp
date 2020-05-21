#include <printf.h>
#include "stack.h"

//
// Created by visionary on 2020/5/21.
// 顺序存储
//

SqStack initStack(int *array, int length) {
    SqStack sqStack;
    sqStack.top = -1;
    sqStack.length = 0;
    for (int i = 0; i < length; ++i) {
        push(sqStack, array[i]);
    }
    return sqStack;
};


bool push(SqStack &sqStack, int x) {
    if (sqStack.top >= 49) {
        return false;
    }
    sqStack.length++;
    sqStack.data[++(sqStack.top)] = x;
    return true;
};

int pop(SqStack &sqStack) {
    if (sqStack.top <= -1) {
        return false;
    }
    sqStack.length--;
    int x = sqStack.data[sqStack.top--];
    return x;
};

void printStack(SqStack &sqStack) {
    printf("输出栈：");
    for (int i = 0; i < sqStack.length; ++i) {
        printf("%d ", sqStack.data[i]);
    }
    printf("\n");
};

void GetTop(){
}


int main(int argc, const char *argv[]) {
    int array[4] = {1, 3, 4, 2};
    SqStack sqStack = initStack(array, 4);
    printStack(sqStack);
    push(sqStack, 5);
    printStack(sqStack);
    int popNumber = pop(sqStack);
    printf("popNumber %d out\n", popNumber);
    printStack(sqStack);
    push(sqStack, 6);
    push(sqStack, 6);
    printStack(sqStack);
}
