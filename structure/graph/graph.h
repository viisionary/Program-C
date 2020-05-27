//
// Created by visionary on 2020/5/27.
//

#ifndef PROGRAM_C_GRAPH_H
#define PROGRAM_C_GRAPH_H

#endif //PROGRAM_C_GRAPH_H
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexNum, arcNum;
} MGraph;


typedef struct ArcNode {
    int adjVex;
    struct ArcNode *next;
    // 网的边权值
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;
    int vexNum, arcNum;
} ALGraph;
//十字 有向图
typedef struct xArcNode {
    int tailVex, headVex;
    struct ArcNode *hLink, *tLink;
} xArcNode;
//邻接多重表
// fn
//bool Adjacent(G, x, y);
 void Neighbors();
