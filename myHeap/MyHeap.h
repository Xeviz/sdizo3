//
// Created by Kuba on 15.04.2023.
//

#ifndef SDIZO1_MYHEAP_H
#define SDIZO1_MYHEAP_H


class MyHeap {
private:
    int currentSize;
    void heapify(int i); // naprawianie kopca od węzła i w dół
    void siftUp(int i); // naprawianie kopca od węzła i w górę
    int* heapArray;
    int arraySize;

public:
    MyHeap();
    void deleteHeap();
    void addNode();
    void addNode(int val);
    int getMax();
    void extractMax();
    void getSizeInfo();
    void removeUnderIndex(int index);
    void removeYoungestLeaf();
    void addManyNodes(int amount);
    void removeManyNodes(int amount);
    bool searchForValue(int value);
    void searchUnderIndex(int index);
    void loadFromFile();
    void addByHand();
    int getSize();
    void printHeap();
};





#endif //SDIZO1_MYHEAP_H
