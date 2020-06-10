//
// Created by visionary on 2020/5/21.
//
#include <cstdlib>
#include <printf.h>
#include <cstring>
#include "sqStack.h"

void createLiStack(LiStack **pLiStack) {
    *pLiStack = (LiStack *) malloc(sizeof(LiStack));
    if (*pLiStack == nullptr) {
    } else {
        (*pLiStack)->next = nullptr;
    }
}

int isEmpty(LiStack *pLiStack) {
    if (pLiStack->next == nullptr) {
        return 1;
    }
    return 0;
}

void printLiStack(LiStack *stack) {
    printf("输出栈：");
    if (!isEmpty(stack)) {
        LiStack *pMove;
        pMove = stack->next;
        while (pMove != nullptr) {
            printf("%c ", pMove->element);
            pMove = pMove->next;
        }
    } else {
    }
    printf("\n");
}

//压入一个元素
bool LiPush(LiStack *pNode, char value) {
    LiStack *pInsert;
    pInsert = (LiStack *) malloc(sizeof(LiStack));//需要检测分配内存是否成功 pInsert == NULL  ?
    memset(pInsert, 0, sizeof(LiStack));
    pInsert->next = nullptr;
    pInsert->element = value;
    pInsert->next = pNode->next;
    pNode->next = pInsert;
    return true;
}

//弹出一个元素
char LiPop(LiStack *pNode) {
    if (!isEmpty(pNode)) {
        LiStack *pNext;
        pNext = pNode->next;

        pNode->next = pNext->next;
        free(pNext);
        pNext = nullptr;
    }
    return '1';
};

char top(LiStack *pLiStack) {
    if (!isEmpty(pLiStack)) {
        return pLiStack->next->element;
    }
    return {};
}
