//
// Created by Kuba on 16.04.2023.
//

#ifndef SDIZO1_TREENODE_H
#define SDIZO1_TREENODE_H

#include <string>

//klasa pomocnicza
//przedstawia pojedynczy wezel drzewa czerwono czarnego
class TreeNode {
private:
    int value;
    char color;
    TreeNode* parent;
    TreeNode* childLeft;
    TreeNode* childRight;
public:
    TreeNode();
    TreeNode(int val, TreeNode* leaf);
    int getValue();
    TreeNode* getParent();
    TreeNode* getChildLeft();
    TreeNode* getChildRight();
    void setParent(TreeNode* newParent);
    void setChildLeft(TreeNode* newChildLeft);
    void setChildRight(TreeNode* newChildRight);
    void setColor(char newColor);
    char getColor();
};


#endif //SDIZO1_TREENODE_H
