//
// Created by visionary on 2020/5/21.
//

typedef struct BiTNode {
    int data;
    struct BiTNode *lChild;
    struct BiTNode *rChild;
} BiTNode, *BitTree;
// 线索二叉树
void createBitTree();
BiTNode initTree(int *array, int length);
void PreOrderBiTree(BiTNode *T);
void testTree();
