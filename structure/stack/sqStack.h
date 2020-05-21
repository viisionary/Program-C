#define MAX_SIZE 50;

typedef struct {
    int data[50];
    int top;
    int length;
} SqStack;

typedef struct LiStack {
    char element;
    struct LiStack *next;
} LiStack;

SqStack initStack(int *array, int length);

bool push(SqStack &sqStack, int x);
int pop(SqStack &sqStack);
void printStack(SqStack &sqStack);

bool LiPush(LiStack *stack, char x);
char LiPop(LiStack *stack);
void printLiStack(LiStack *stack);
void createLiStack(LiStack **stack);

LiStack initLiStack(char *string, int length);

void testLiStack();
void testSqStack();
