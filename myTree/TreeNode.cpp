//
// Created by Kuba on 16.04.2023.
//

#include "iostream"
#include "TreeNode.h"

TreeNode::TreeNode() {
    value = NULL;
    color = 'B';
    parent = nullptr;
    childLeft = nullptr;
    childRight = nullptr;
}

TreeNode::TreeNode(int val, TreeNode* leaf) {
    value = val;
    color = 'R';
    childLeft = leaf;
    childRight = leaf;
    parent = nullptr;
}

int TreeNode::getValue() {
    return value;
}

TreeNode* TreeNode::getParent() {
    return parent;
}

TreeNode* TreeNode::getChildRight() {
    return childRight;
}

TreeNode* TreeNode::getChildLeft() {
    return childLeft;
}

char TreeNode::getColor() {
    return color;
}

void TreeNode::setParent(TreeNode *newParent) {
    parent = newParent;
}

void TreeNode::setChildLeft(TreeNode *newChildLeft) {
    childLeft = newChildLeft;
}

void TreeNode::setChildRight(TreeNode *newChildRight) {
    childRight = newChildRight;
}

void TreeNode::setColor(char newColor) {
    color = newColor;
}


