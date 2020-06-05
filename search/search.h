//
// Created by visionary on 2020/6/4.
//


#ifndef PROGRAM_C_SEARCH_H
#define PROGRAM_C_SEARCH_H

#endif //PROGRAM_C_SEARCH_H

#define keyType int
typedef struct {
    keyType key;//查找表中每个数据元素的值
    //如果需要，还可以添加其他属性
}ElemType;

typedef struct{
    ElemType *elem;//存放查找表中数据元素的数组
    int length;//记录查找表中数据的总数量
}SSTable;

void sequentialSearch();
void dichotomySearch();
