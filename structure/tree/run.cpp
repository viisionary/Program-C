//
// Created by visionary on 2020/5/22.
//

#include "tree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void testTree() {
    int datas[7] = {1, 2, 3, -1, -1, -1, -1};
    int position = 0;
    BiTNode *biTNode = BuildTree(position, datas);
    cout << "先序遍历\n";
    PreOrderBiTree(biTNode);
    cout << "\n中序遍历\n";
    MiddleOrderBiTree(biTNode);
    cout << "\n非递归中序遍历\n";
    MiddleOrderBiTree_Non_Recursion(biTNode);
    cout << "\n\n后序遍历\n";
    PostOrderBiTree(biTNode);
    int deep = TreeDeep(biTNode);
    cout << "\n深度：" << deep;
    int count = LeafCount(biTNode);
    cout << "\n子节点数：" << count;
    cout << "\n层次遍历：";
    levelOrder(biTNode);
    cout<<"\n线索化";
    BiTNode *threadNode;
//    inThread(biTNode);
//    inOrder(biTNode);
}
