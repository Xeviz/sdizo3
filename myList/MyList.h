//
// Created by kubas on 11.04.2023.
//

#ifndef SDIZO1_MYLIST_H
#define SDIZO1_MYLIST_H


#include "ListNode.h"

class MyList {
private:
    int currentSize;
    ListNode* currentElement;
    ListNode* head;
    ListNode* tail;
public:
    MyList();
    void addNode(int index, int value);
    void addNodeFront();
    void addNodeFront(int value);
    void addNodeBack();
    void addNodeBack(int value);
    void addManyNodes(int amount);
    void removeNode(int index);
    void removeNodeFront();
    void removeNodeBack();
    void removeManyNodes(int amount);
    void deleteList();
    void searchForFirstAppearance(int value);
    void searchUnderIndex(int index);
    void getSizeInfo();
    void printList();
    ListNode* findBeginning();
    ListNode* findEnd();
    void loadFromFile();
    void addByHand();
    int getSize();


};


#endif //SDIZO1_MYLIST_H
