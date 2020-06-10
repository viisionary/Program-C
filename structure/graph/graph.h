//
// Created by visionary on 2020/5/27.
//
#include<vector>

#define  InfoType int//图中弧或者边包含的信息的类型
#define MaxVertexNum 4
typedef char VertexType;
typedef int EdgeType;
/**
 * 邻接矩阵
 */
typedef struct {
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexNum, arcNum;
} MGraph;

/**
 * 邻接表
 */
typedef struct ArcNode {
    int adjVex;//邻接点在数组中的位置下标
    struct ArcNode *next;
    // 网的边权值
    InfoType *info;//信息域
} ArcNode;

// 顶点
typedef struct VNode {
    VertexType data;
    ArcNode *first;//指向邻接点的指针
} VNode;

//typeAdjList[MaxVertexNum];//存储各链表头结点的数组

typedef struct {
    std::vector<VNode> vertices;
    int vexNum, arcNum;//记录图中顶点数和边或弧数
} ALGraph;

//
/** 十字
 * 仅适用于存储有向图和有向网。不仅如此，十字链表法还改善了邻接表计算图中顶点入度的问题。
 */
typedef struct xArcNode {
    int tailVex, headVex; //弧尾、弧头对应顶点在数组中的位置下标
    struct ArcNode *hLink, *tLink;//分别指向弧头相同和弧尾相同的下一个弧
    InfoType *info;//存储弧相关信息的指针
} xArcNode;

typedef struct VexNode {
    VertexType data;//顶点的数据域
    xArcNode *firstIn, *firstOut;//指向以该顶点为弧头和弧尾的链表首个结点
} VexNode;

typedef struct {
    VexNode xList[MaxVertexNum];//存储顶点的一维数组
    int vexNum, arcNum;//记录图的顶点数和弧数
} OLGraph;

//邻接多重表
// fn
//bool Adjacent(G, x, y);
void Neighbors();

void CreateDG(OLGraph *G);

void testGraph();

void AdjEdge(MGraph *G, VertexType X, VertexType Y);

void ALGraph2MGraph(ALGraph *alGraph, MGraph *mGraph);

void createMGraph(MGraph *mGraph, EdgeType matrix[4][4]);

void printGraph(MGraph *mGraph);

void neighEdge(MGraph *mGraph, VertexType X);

ALGraph MGraph2ALGraph(MGraph *mGraph);

void printALGraph(ALGraph *alGraph);
