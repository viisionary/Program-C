#include "tree.h"
#include<vector>
#include<stack>
#include <iostream>

using namespace std;


BiTNode *BuildTree(int &position, int datas[]) {
    int data = datas[position++];
    if (data == -1) {
        return nullptr;
    }
    BiTNode *root = new BiTNode(data);
    root->leftChild = BuildTree(position, datas);
    root->rightChild = BuildTree(position, datas);
    return root;
}

//先序遍历二叉树
void PreOrderBiTree(BiTNode *T) {
    if (T == nullptr) {
        return;
    } else {
        cout << T->data << " ";
        PreOrderBiTree(T->leftChild);
        PreOrderBiTree(T->rightChild);
    }
}

//中序遍历二叉树
void MiddleOrderBiTree(BiTNode *T) {
    if (T == nullptr) {
        return;
    } else {
        MiddleOrderBiTree(T->leftChild);
        cout << T->data << " ";
        MiddleOrderBiTree(T->rightChild);
    }
}

//后续遍历二叉树
void PostOrderBiTree(BiTNode *T) {
    if (T == nullptr) {
        return;
    } else {
        PostOrderBiTree(T->leftChild);
        cout << T->data << " ";
        PostOrderBiTree(T->rightChild);
    }
}

//二叉树的深度
int TreeDeep(BiTNode *T) {
    int deep = 0;
    if (T != nullptr) {
        int leftdeep = TreeDeep(T->leftChild);
        int rightdeep = TreeDeep(T->rightChild);
        deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
    }

    return deep;
}

//叶子节点个数
int LeafCount(BiTNode *T) {
    static int count;
    if (T != nullptr) {
        if (T->leftChild == nullptr && T->rightChild == nullptr) {
            count++;
        }

        LeafCount(T->leftChild);
        LeafCount(T->rightChild);
    }

    return count;
}

/**
 * 非递归的中序遍历
 */
void MiddleOrderBiTree_Non_Recursion(BiTNode *T) {
    stack<BitTree> stack;
    BitTree p = T;
    int i = 0;
    while (p != nullptr || stack.empty() != 1) {
        bool notNull = (p != nullptr);
        i++;
        if (notNull) {
            cout<< p;
            stack.push(p);
            p = p->leftChild;
//            p = p->leftChild != nullptr ? p->leftChild : nullptr;
        } else {
//            stack.pop();
            cout << p->data << " 2";
            p = p->rightChild;
//            p = p->rightChild != nullptr ? p->rightChild : nullptr;
        }
        if (i > 10) {
            return;
        }
    }
}

void levelOrder(BitTree T) {
    vector<BitTree> queue;
    BitTree p;
    queue.push_back(T);
    while (!queue.empty()) {
        p = queue.back();
//        p = queue[queue.end()];
        queue.pop_back();
        cout << p->data << " ";
        if (p->leftChild != nullptr) {
            queue.push_back(p->leftChild);
        }
        if (p->rightChild != nullptr) {
            queue.push_back(p->rightChild);
        }
    }
}

void inThread(BitTree &p, BitTree &pre) {
    if (p != nullptr) {
        inThread(p->leftChild, pre);
        if (p->leftChild == nullptr) {
            p->leftChild = pre;
            p->leftTag = 1;
        }
        if (pre != nullptr && pre->rightChild == nullptr) {
            pre->rightChild = p;
            pre->rightTag = 1;
        }
        pre = p;
        inThread(p->rightChild, pre);
    }
}

BiTNode *firstNode(BiTNode *p) {
    while (p && p->leftTag == 0) {
        p = p->leftChild;
    }
    return p;
}

BiTNode *nextNode(BiTNode *p) {
    if (p->rightTag == 0) {
        return firstNode(p->rightChild);
    }
    cout << "下一个是" << p->rightChild->data;

    return p->rightChild;
}

void inOrder(BiTNode *T) {
    for (BiTNode *p = firstNode(T); p != nullptr; p = nextNode(T)) {
        cout << "->" << p->data;
    }
}
