//
// Created by visionary on 2020/5/22.
//

#include "tree.h"
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

void testTree() {
    int datas[9] = {1, 2, 4, -1, -1, -1, 3, -1, -1};
    int position = 0;
    BiTNode *biTNode = BuildTree(position, datas);
    cout << "先序遍历：";
    PreOrderBiTree(biTNode);
    cout << "\n中序遍历：";
    MiddleOrderBiTree(biTNode);
    cout << "\n非递归中序遍历：";
    MiddleOrderBiTree_Non_Recursion(biTNode);
    cout << "\n后序遍历：";
    PostOrderBiTree(biTNode);
    cout << "\n非递归后序遍历：";
    postOrderBiTree_Non_Recursion(biTNode);
    int deep = TreeDeep(biTNode);
    cout << "\n深度：" << deep;
    int count = LeafCount(biTNode);
    cout << "\n子节点数：" << count;
    cout << "\n层次遍历：";
    levelOrder(biTNode);
    cout << "\n下至上左至右层次遍历：";
    levelBottom2Top(biTNode);
    cout << "\n线索化：";
    createInTread(biTNode);
    inOrder(biTNode);
}
