#include <cstdio>
#include <cstdlib>

typedef struct Objects {
    int number;
} Object;

//值传递
Object pointerExample3(Object object) {
    object.number = 3;
    return object;
}

// 地址传递
void pointerExample(Object *object) {
    object->number = 1;
//    (*object).number = 11;
}

// 饮用传递
void pointerExample2(Object &object) {
    object.number = 2;
//    *&object.number=2;
}

void pointerExample4(Object **pObject) {
    *pObject = (Objects *) malloc(sizeof(Objects));
    (*pObject)->number = 4;
}

void test() {
    Object myObject;
    myObject.number = 0;
    Object myObject3 = {0};
    Object *myObject2 = &myObject3;
    Object *myObject4 = {nullptr};
    printf("--------------------取指针的值\n");
    printf("%d\n", myObject2->number);
    printf("%d\n", (*myObject2).number);
    printf("--------------------地址\n");
    printf("%p\n", &myObject3);
    printf("%p\n", myObject2);
    printf("--------------------值传递改值\n");
    Object newObject = pointerExample3(myObject);
    printf("%d\n", myObject.number);
    printf("%d\n", newObject.number);
    printf("--------------------地址\n");
    pointerExample(myObject2);
    printf("myObject2 %p\n", myObject2);
    printf("myObject2 %d\n", myObject2->number);
    pointerExample(&myObject3);
    printf("myObject3 %p\n", &myObject3);
    printf("myObject3 %d\n", myObject3.number);
    pointerExample(&myObject);
    printf("myObject %p\n", &myObject);
    printf("myObject %d\n", myObject.number);
    printf("--------------------引用\n");
    pointerExample2(myObject);
    printf("myObject %p\n", &myObject);
    printf("myObject %d\n", myObject.number);
    pointerExample2(myObject3);
    printf("myObject3 %p\n", &myObject3);
    printf("myObject3 %d\n", myObject3.number);
    pointerExample2(*myObject2);
    printf("myObject2 %p\n", myObject2);
    printf("myObject2 %d\n", myObject2->number);
    printf("--------------------**引用\n");
    pointerExample4(&myObject4);
    printf("myObject4 %d\n", myObject4->number);
    printf("myObject4 %d\n", (*myObject4).number);
}
