#include "tree.h"
#include<vector>
#include<stack>
#include <iostream>
#include <queue>

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
        PostOrderBiTree(T->rightChild);
        cout << T->data << " ";
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
    while (p != nullptr || stack.empty() != 1) {
        if (p != nullptr) {
            stack.push(p);
            p = p->leftChild;
        } else {
            p = stack.top();
            cout << p->data << " ";
            stack.pop();
            p = p->rightChild;
        }
    }
}

void levelOrder(BitTree T) {
    vector<BitTree> queue;
    BitTree p;
    queue.push_back(T);
    while (!queue.empty()) {
        p = queue.back();
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
    return p->rightChild;
}

void inOrder(BiTNode *T) {
    for (BiTNode *p = firstNode(T); p != nullptr; p = nextNode(p)) {
        cout << p->data << " ";
    }
}

void createInTread(BitTree T) {
    BitTree pre = nullptr;
    if (T != nullptr) {
        inThread(T, pre);
        pre->rightChild = nullptr;
        pre->leftTag = 1;
    }
}

void postOrderBiTree_Non_Recursion(BiTNode *T) {
    stack<BitTree> stack;
    BitTree p = T;
    BitTree r = nullptr;
    while (p != nullptr || stack.empty() != 1) {
        if (p != nullptr) {
            stack.push(p);
            p = p->leftChild; //取到最左边 入栈 4 2 1
        } else {
            p = stack.top(); // 第一次栈顶4 第二次栈顶是2 第三次是1
            if (p->rightChild && (p->rightChild != r)) {
                // 1的右存在
                p = p->rightChild;
                // 3入栈    3->1
                stack.push(p);
                p = p->leftChild; //p=（3的左子树） p=null
            } else {
                // 4的右子树不存在。4出
                // 2的右也不存在。2出
                // 3的右不存在 3出
                // 1出
                stack.pop();
                cout << p->data << " ";
                r = p; //r = 4; //r =2 //r=3
                p = nullptr; // p 为空
            }
        }
    }
};

/**
 * 自上而下自右到左
 * @param T
 */
void levelBottom2Top(BiTNode *T) {
    stack<BitTree> stack;
    queue<BitTree> queue;
    BitTree p = T;
    if (p == nullptr) {
        return;;
    }
    queue.push(T);
    while (queue.empty() != 1) {
        p = queue.front();
        queue.pop();
        stack.push(p);
        if (p->leftChild) {
            queue.push(p->leftChild);
        }
        if (p->rightChild) {
            queue.push(p->rightChild);
        }
    }
    while (stack.empty() != 1) {
        cout << stack.top()->data << " ";
        stack.pop();
    }
}
