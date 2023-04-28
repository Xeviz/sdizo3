//
// Created by kubas on 11.04.2023.
//

#ifndef SDIZO1_HEAPNODE_H
#define SDIZO1_NODE_H


class ListNode {
private:
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    int value;
public:
    ListNode();
    ListNode(int val);
    void setValue();
    void setValue(int val);
    int getValue();
    void setNext(ListNode* node);
    void setPrev(ListNode* node);
    ListNode* getNext();
    ListNode* getPrev();

};


#endif //SDIZO1_HEAPNODE_H
