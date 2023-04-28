//
// Created by Kuba on 16.04.2023.
//
#include <windows.h>
#include <fstream>
#include "iostream"
#include "MyTree.h"
#include "../helpingTools/HelpingTools.h"

using namespace std;

MyTree::MyTree() {
    nilLeaf = new TreeNode();
    root = nilLeaf;
}

void MyTree::addValue(int value) {

    currentSize++;
    auto node = new TreeNode(value, nilLeaf);
    TreeNode* helper1 = root;
    TreeNode* helper2 = nullptr;
    while (helper1 != nilLeaf){
        helper2 = helper1;
        if (node->getValue() <= helper1->getValue())
            helper1= helper1->getChildLeft();
        else
            helper1 = helper1->getChildRight();
    }
    node->setParent(helper2);
    if (helper2 == nullptr){
        root = node;
        node->setColor('B');
        return;
    }else if(node->getValue() <= helper2->getValue())
        helper2->setChildLeft(node);
    else
        helper2->setChildRight(node);

    if (node->getParent()->getParent() == nullptr){
        return;
    }

    TreeNode* helper;
    while(node->getParent()->getColor() == 'R'){


        if (node->getParent() == node->getParent()->getParent()->getChildRight()){
            helper = node->getParent()->getParent()->getChildLeft();//stryj

            if (helper->getColor() == 'R'){
                helper->setColor('B');
                node->getParent()->setColor('B');
                node->getParent()->getParent()->setColor('R');
                node = node->getParent()->getParent();
            } else {

                if (node == node->getParent()->getChildLeft()){
                    node = node->getParent();
                    rotationRight(node);
                }
                node->getParent()->setColor('B');
                node->getParent()->getParent()->setColor('R');
                rotationLeft(node->getParent()->getParent());
            }
        }


        else{

            helper = node->getParent()->getParent()->getChildRight();
            if (helper->getColor() == 'R'){
                helper->setColor('B');
                node->getParent()->setColor('B');
                node->getParent()->getParent()->setColor('R');
                node = node->getParent()->getParent();
            }else{

                if (node == node->getParent()->getChildRight()){
                    node = node->getParent();
                    rotationLeft(node);
                }
                node->getParent()->setColor('B');
                node->getParent()->getParent()->setColor('R');
                rotationRight(node->getParent()->getParent());
            }
        }
        if (node == root)
            break;
    }
    root->setColor('B');
}

void MyTree::addMultipleElements(int amount) {
    for (int i = 0; i < amount; ++i) {
        int valueToAdd;
        do{
            valueToAdd = HelpingTools::getRandomForHeap();
        }while(searchIfExist(valueToAdd));
        addValue(valueToAdd);
    }
}

void MyTree::replaceNodes(TreeNode* node1, TreeNode* node2) {
    if (node1->getParent() == nullptr){
        root = node2;
    }else if (node1 == node1->getParent()->getChildLeft()){
        node1->getParent()->setChildLeft(node2);
    } else {
        node1->getParent()->setChildRight(node2);
    }
    node2->setParent(node1->getParent());
}

void MyTree::deleteValue(int val) {
    TreeNode* helper1 = nilLeaf;
    TreeNode* helper2;
    TreeNode* helper3;

    helper1 = searchValue(val);
    if (helper1 == nilLeaf){
        cout<<"Tree does not contain given value\n";
        return;
    }
    currentSize--;
    helper2 = helper1;
    char originColor = helper2->getColor();

    if(helper1->getChildLeft() == nilLeaf){
        helper3 = helper1->getChildRight();
        replaceNodes(helper1, helper1->getChildRight());
    }
    else if (helper1->getChildRight() == nilLeaf){
        helper3 = helper1->getChildLeft();
        replaceNodes(helper1, helper1->getChildLeft());
    }

    else{
        helper2 = findMin(helper2->getChildRight());
        originColor = helper2->getColor();
        helper3 = helper2->getChildRight();
        if (helper2->getParent() == helper1){
            helper3->setParent(helper2);
        }
        else{
            replaceNodes(helper2, helper2->getChildRight());
            helper2->setChildRight(helper1->getChildRight());
            helper2->getChildRight()->setParent(helper2);
        }
        replaceNodes(helper1, helper2);
        helper2->setChildLeft(helper1->getChildLeft());
        helper2->getChildLeft()->setParent(helper2);
        helper2->setColor(helper1->getColor());
    }

    delete helper1;

    if (originColor == 'B'){

        TreeNode* helper;
        while (helper3 != root && helper3->getColor() == 'B'){

            if (helper3 == helper3->getParent()->getChildLeft()){
                helper = helper3->getParent()->getChildRight();// brat

                if(helper->getColor() == 'R'){
                    helper->setColor('B');
                    helper3->getParent()->setColor('R');
                    rotationLeft(helper3->getParent());
                    helper = helper3->getParent()->getChildRight();
                }

                if(helper->getChildLeft()->getColor() == 'B' &&
                   helper->getChildRight()->getColor() == 'B'){
                    helper->setColor('R');
                    helper3 = helper3->getParent();
                }
                else{
                    if(helper->getChildRight()->getColor() == 'B'){
                        helper->getChildLeft()->setColor('B');
                        helper->setColor('R');
                        rotationRight(helper);
                        helper = helper3->getParent()->getChildRight();
                    }
                    helper->setColor(helper3->getParent()->getColor());
                    helper3->getParent()->setColor('B');
                    helper->getChildRight()->setColor('B');
                    rotationLeft(helper3->getParent());
                    helper3 = root;
                }
            }
            else{
                helper = helper3->getParent()->getChildLeft();
                if(helper->getColor() == 'R'){
                    helper->setColor('B');
                    helper3->getParent()->setColor('R');
                    rotationRight(helper3->getParent());
                    helper = helper3->getParent()->getChildLeft();
                }

                if(helper->getChildRight()->getColor() == 'B' &&
                   helper->getChildLeft()->getColor() == 'B'){
                    helper->setColor('R');
                    helper3 = helper3->getParent();
                }



                else{
                    if(helper->getChildLeft()->getColor() == 'B'){
                        helper->getChildRight()->setColor('B');
                        helper->setColor('R');
                        rotationLeft(helper);
                        helper = helper3->getParent()->getChildLeft();//ustawia helper na nowego brata
                    }

                    helper->setColor(helper3->getParent()->getColor());
                    helper3->getParent()->setColor('B');
                    helper->getChildLeft()->setColor('B');
                    rotationRight(helper3->getParent());
                    helper3 = root;
                }
            }
        }
        helper3->setColor('B');
    }
}

void MyTree::rotationLeft(TreeNode *node) {
    TreeNode* pom = node->getChildRight();
    node->setChildRight(pom->getChildLeft());

    if(pom->getChildLeft() != nilLeaf)
        pom->getChildLeft()->setParent(node);

    pom->setParent(node->getParent());

    if (node->getParent() == nullptr)
        root = pom;

    else if (node == node->getParent()->getChildLeft())
        node->getParent()->setChildLeft(pom);

    else node->getParent()->setChildRight(pom);

    pom->setChildLeft(node);
    node->setParent(pom);

}

void MyTree::rotationRight(TreeNode *node) {
    TreeNode* pom = node->getChildLeft();
    node->setChildLeft(pom->getChildRight());

    if (pom->getChildRight() != nilLeaf)
        pom->getChildRight()->setParent(node);

    pom->setParent(node->getParent());

    if (node->getParent() == nullptr)
        root = pom;

    else if (node == node->getParent()->getChildRight())
        node->getParent()->setChildRight(pom);

    else node->getParent()->setChildLeft(pom);

    pom->setChildRight(node);
    node->setParent(pom);
}

TreeNode* MyTree::searchValue(int key){
    TreeNode* node = searchValue(root, key);
    if (node == nilLeaf) cout << "Match not found\n";
    else cout<<"Match found\n";
    return node;
}

bool MyTree::searchIfExist(int val) {
    TreeNode* node = searchValue(root, val);
    if (node == nullptr || node == nilLeaf) return false;
    return true;
}

TreeNode* MyTree::searchValue(TreeNode* node, int val) {
    if (node != nilLeaf) {
        if (node->getValue() == val) {
            return node;
        } else if (node->getValue() > val) return searchValue(node->getChildLeft(), val);
        else return searchValue(node->getChildRight(), val);
    }
    return node;
}

TreeNode* MyTree::findMin(TreeNode *node) {
    TreeNode* minimum_node = node;
    while (minimum_node->getChildLeft() != nilLeaf) minimum_node = minimum_node->getChildLeft();
    return minimum_node;
}

int MyTree::getRoot() {
    return root->getValue();
}

int MyTree::getSize() {
    return currentSize;
}

void MyTree::printTree() {
    if (currentSize != 0)
        printTree(root,"");
    else
        cout << "The tree is empty!";
}

void MyTree::printTree(TreeNode* node, std::string interspace){

    if (node != nilLeaf){
        string actualColor;
        if(node->getColor()=='B'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            actualColor = "B";
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            actualColor = "R";
        }
        cout<<interspace;
        interspace += "\t";
        cout << node->getValue() << "(" << actualColor << ")" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        printTree(node->getChildLeft(),interspace);
        printTree(node->getChildRight(),interspace);
    }
}

void MyTree::loadFromFile(){
    std::ifstream file("..\\dane.txt");
    int amount;
    int value;
    file >> amount;
    for(int i = 0; i < amount; i++) {
        file >> value;
        addValue(value);
    }
    file.close();
}


void MyTree::deleteTree() {
    int val;
    while(currentSize>0){
        val = root->getValue();
        deleteValue(val);
    }
}



