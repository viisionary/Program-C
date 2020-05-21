#include <printf.h>
#include "sqStack.h"

//
// Created by visionary on 2020/5/21.
//
void testSqStack() {
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
};

void testLiStack() {
    LiStack *liStack;
    createLiStack(&liStack);
    LiPush(liStack,'h');
    LiPush(liStack,'e');
    LiPush(liStack,'a');
    LiPush(liStack,'b');
    printLiStack(liStack);
    LiPop(liStack);
    printLiStack(liStack);
}



