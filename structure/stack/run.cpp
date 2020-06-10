#include <printf.h>
#include "sqStack.h"
#include "../graph/graph.h"

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
    LiPush(liStack, 'h');
    LiPush(liStack, 'e');
    LiPush(liStack, 'a');
    LiPush(liStack, 'b');
    printLiStack(liStack);
    LiPop(liStack);
    printLiStack(liStack);
}

void testGraph() {
    /**
     * 有向图
     */
    EdgeType matrix[MaxVertexNum][MaxVertexNum] = {{0, 1, 1, 0},
                                                   {0, 0, 0, 0},
                                                   {0, 0, 0, 1},
                                                   {1, 0, 0, 0}};
    MGraph initGraph = {};
    initGraph.vexNum = 4;
    initGraph.arcNum = 4;
    VertexType vertexA = 'a';
    VertexType vertexB = 'b';
    VertexType vertexC = 'c';
    VertexType vertexD = 'd';

    initGraph.Vex[0] = vertexA;
    initGraph.Vex[1] = vertexB;
    initGraph.Vex[2] = vertexC;
    initGraph.Vex[3] = vertexD;

    MGraph *mGraph = &initGraph;
    createMGraph(mGraph, matrix);
    printGraph(mGraph);
    printf("是否存在边<A,B>");
    AdjEdge(mGraph, vertexA, vertexB);
//    ALGraph *alGraph ={};
    ALGraph alGraph = MGraph2ALGraph(mGraph);
    printALGraph(&alGraph);
}

