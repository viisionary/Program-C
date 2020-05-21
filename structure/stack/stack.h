//
// Created by visionary on 2020/5/21.
//

#define MAX_SIZE 50;
typedef int elemType;

typedef struct {
    int data[50];
    int top;
    int length;
} SqStack;
//SqStack initStack(int array[]);
//SqStack initStack(int array[]);
bool push(SqStack &sqStack, int x);
void isEmpty(SqStack &sqStack);
int pop(SqStack &sqStack);
void print(SqStack &sqStack);
