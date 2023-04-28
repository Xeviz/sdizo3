//
// Created by Kuba on 15.04.2023.
//

#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "MyHeap.h"
#include "../helpingTools/HelpingTools.h"

MyHeap::MyHeap() {
    currentSize = 0;
    arraySize = 1;
    heapArray = (int*) malloc(arraySize * sizeof(int));
}

void MyHeap::deleteHeap() {
    delete[] heapArray;
    heapArray = nullptr;
}

void MyHeap::heapify(int i) {
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    int largest = i;

    if (leftChild < currentSize && heapArray[leftChild] > heapArray[largest]) {
        largest = leftChild;
    }

    if (rightChild < currentSize && heapArray[rightChild] > heapArray[largest]) {
        largest = rightChild;
    }

    if (largest != i) {
        std::swap(heapArray[i], heapArray[largest]);
        heapify(largest);
    }
}

void MyHeap::siftUp(int i) {
    int parent = (i - 1) / 2;

    if (i > 0 && heapArray[i] > heapArray[parent]) {
        std::swap(heapArray[i], heapArray[parent]);
        siftUp(parent);
    }
}

void MyHeap::addNode() {
    int value = HelpingTools::getRandomForHeap();
    while(searchForValue(value)){
        value = HelpingTools::getRandomForHeap();
    }

    if (currentSize == arraySize) {
        arraySize *= 2;
        heapArray = (int*)realloc(heapArray, arraySize * sizeof(int));
    }

    heapArray[currentSize] = value;
    currentSize++;
    siftUp(currentSize - 1);
}

void MyHeap::addNode(int val) {
    int value = val;

    if (currentSize == arraySize) {
        arraySize *= 2;
        heapArray = (int*)realloc(heapArray, arraySize * sizeof(int));
    }

    heapArray[currentSize] = value;
    currentSize++;
    siftUp(currentSize - 1);
}

void MyHeap::printHeap() {
    int height = log2(currentSize) + 1;
    int index = 0;
    for (int i = 1; i <= height; i++) {
        int numNodes = pow(2, i-1);
        int spacesBefore = pow(2, height-i) - 1;
        int spacesBetween = pow(2, height-i+1) - 1;

        for (int j = 0; j < spacesBefore; j++) {
            std::cout << "   ";
        }

        for (int j = 0; j < numNodes; j++) {
            if (index < currentSize) {
                std::cout << std::setw(3) << heapArray[index];
            } else {
                std::cout << "   ";
            }
            for (int k = 0; k < spacesBetween; k++) {
                std::cout << "   ";
            }
            index++;
        }
        std::cout << std::endl;
    }


}

int MyHeap::getSize() {
    return currentSize;
}

int MyHeap::getMax() {
    if (currentSize == 0) {
        std::cerr << "Error: heap is empty" << std::endl;
        return -1;
    }
    return heapArray[0];
}

void MyHeap::extractMax() {
    if (currentSize == 0) {
        std::cerr << "Error: heap is empty" << std::endl;
    }
    int max = heapArray[0];
    heapArray[0] = heapArray[currentSize - 1];
    currentSize--;
    heapify(0);
}

void MyHeap::removeUnderIndex(int index) {
    if (index >= currentSize || index < 0) {
        return;
    }

    heapArray[index] = heapArray[currentSize - 1];
    currentSize--;

    int parent = (index - 1) / 2;
    if (index == 0 || heapArray[index] < heapArray[parent]) {
        heapify(index);
    } else {
        siftUp(index);
    }
}

bool MyHeap::searchForValue(int value) {
    for (int i=0;i<currentSize;i++){
        if (heapArray[i] == value){
            return true;
        }
    }
    return false;
}

void MyHeap::getSizeInfo() {
    std::cout << "Heap contains given amount of elements: " << currentSize;
}

void MyHeap::removeYoungestLeaf() {
    if (currentSize == 0) {
        return;
    }

    currentSize--;

    heapify(0);
}

void MyHeap::removeManyNodes(int amount) {
    if(amount<=currentSize) {
        for(int i = 0; i < amount; i++){
            removeYoungestLeaf();
        }
    }
}

void MyHeap::addManyNodes(int amount) {
    for(int i = 0; i < amount; i++){
        addNode();
    }
}

void MyHeap::searchUnderIndex(int index) {
    if (index >= currentSize || index < 0) {
        return;
    }

    std::cout << "value under given index: "<< heapArray[index] << std::endl;
}

void MyHeap::loadFromFile(){
    std::ifstream file("..\\dane.txt");
    int amount;
    int value;
    file >> amount;
    for(int i = 0; i < amount; i++) {
        file >> value;
        addNode(value);
    }
    file.close();
}

void MyHeap::addByHand() {
    int val;
    std::cout << "\nchoose value of addition: ";
    std::cin >> val;
    addNode(val);
}















