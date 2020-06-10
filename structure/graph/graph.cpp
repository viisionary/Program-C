//
// Created by visionary on 2020/5/27.
//
#include<vector>
#include <cstdio>
#include "graph.h"
#include <iostream>

using namespace std;

int LocateVex(OLGraph *G, VertexType v) {
    int i = 0;
    //遍历一维数组，找到变量v
    for (; i < G->vexNum; i++) {
        if (G->xList[i].data == v) {
            break;
        }
    }
    //如果找不到，输出提示语句，返回 -1
    if (i > G->vexNum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

void createMGraph(MGraph *mGraph, EdgeType edgeType[4][4]) {
    mGraph->vexNum = 4;
    for (int i = 0; i < mGraph->vexNum; ++i) {
        for (int j = 0; j < mGraph->vexNum; ++j) {
            mGraph->Edge[i][j] = edgeType[i][j];
        }
    }

}

void printGraph(MGraph *mGraph) {
    for (int i = 0; i < mGraph->vexNum; ++i) {
        printf("[");
        for (int j = 0; j < mGraph->vexNum; ++j) {
            printf("%d ", mGraph->Edge[i][j]);
        }
        printf("]\n");
    }
};


void AdjEdge(MGraph *G, VertexType X, VertexType Y) {
    int indexX = -1;
    int indexY = -1;
    for (int i = 0; i < G->vexNum; ++i) {
        if (G->Vex[i] == X) {
            indexX = i;
        }
        if (G->Vex[i] == Y) {
            indexY = i;
        }
    }
    if (indexX == -1 || indexY == -1) {
        printf("\n顶点不存在");
        return;
    }
    if (G->Edge[indexX][indexY] == 1 && G->Edge[indexY][indexX] == 1) {
        cout << "\n存在边(" << X << "," << Y << ")" << endl;
        return;
    }
    if (G->Edge[indexX][indexY] == 1) {
        cout << "\n存在边<" << X << "," << Y << ">" << endl;
    }
};

void ALGraph2MGraph(ALGraph *alGraph, MGraph *mGraph) {

};

ALGraph MGraph2ALGraph(MGraph *mGraph) {
    vector<VNode> adjList;
    for (int i = 0; i < mGraph->vexNum; ++i) {
        // make顶点
        ArcNode firstNode = {mGraph->Vex[i]};
        VNode vNode = {};
        vNode.data = mGraph->Vex[i];
        vNode.first = &firstNode;
        for (int j = 0; j < mGraph->vexNum; ++j) {
            if (mGraph->Edge[i][j] == 1) {
                ArcNode childNode = {mGraph->Vex[j]};
                firstNode.next = &childNode;
            }
        }
        adjList.push_back(vNode);
    }
    ALGraph graph;
    graph.vertices = adjList;
    graph.vexNum = mGraph->vexNum;
    graph.arcNum = mGraph->arcNum;
    return graph;
};

void printALGraph(ALGraph *alGraph) {
    cout << "输出邻接表\n";
    for (int i = 0; i < alGraph->vexNum; ++i) {
        cout << alGraph->vertices[i].data << " ";
    }
}
