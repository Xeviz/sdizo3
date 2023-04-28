//
// Created by Kuba on 16.04.2023.
//

#ifndef SDIZO1_MYTREE_H
#define SDIZO1_MYTREE_H

#include "TreeNode.h"

class MyTree {
private:
    int currentSize = 0;
    TreeNode *root = nullptr;
    TreeNode *nilLeaf;
    void rotationRight(TreeNode *node);
    void rotationLeft(TreeNode *node);
public:
    MyTree();
    void deleteTree();
    TreeNode *findMin(TreeNode *node);
    int getRoot();
    void addValue(int value);
    void addMultipleElements(int amount);
    int getSize();
    TreeNode *searchValue(int key);
    TreeNode *searchValue(TreeNode *node, int val);
    bool searchIfExist(int val);
    void deleteValue(int val);
    void replaceNodes(TreeNode *node1, TreeNode *node2);
    void printTree();
    void printTree(TreeNode *node, std::string interspace);
    void loadFromFile();
};

#endif //SDIZO1_MYTREE_H