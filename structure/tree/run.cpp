//
// Created by visionary on 2020/5/22.
//

#include "tree.h"

void testTree() {
    int array[11] = {1, 3, 4, -1, -1, 2, -1, -1, 4, -1 - 1};
    BiTNode tree = initTree(array, 11);
    PreOrderBiTree(&tree);
}
