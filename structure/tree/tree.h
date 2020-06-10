//
// Created by visionary on 2020/5/21.
//

typedef struct BiTNode {
    int data;
    struct BiTNode *leftChild;
    struct BiTNode *rightChild;

    BiTNode(int data) : data(data), leftChild(nullptr), rightChild(nullptr) {};
    int leftTag, rightTag; //1 child是前驱,线索化
} BiTNode, *BitTree;


BiTNode *BuildTree(int &position, int datas[]);

void PreOrderBiTree(BiTNode *T);

void MiddleOrderBiTree(BiTNode *T);
void MiddleOrderBiTree_Non_Recursion(BiTNode *T);
void PostOrderBiTree(BiTNode *T);

void testTree();

int TreeDeep(BiTNode *T);

int LeafCount(BiTNode *T);

void levelOrder(BitTree T);

// 线索化
void inOrder(BiTNode *T);

void inThread(BitTree p);
