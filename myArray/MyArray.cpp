//
// Created by kubas on 10.04.2023.
//

#include <iostream>
#include <fstream>
#include "MyArray.h"
#include "../helpingTools/HelpingTools.h"


MyArray::MyArray() {
    currentSize = 0;
    allocatedMemory = (int *) malloc(currentSize * sizeof(int));
}

int MyArray::getSize() {
    return currentSize;
}

void MyArray::addElement(int index, int value) {
    if (index < 0 || index > currentSize) {
        std::cout << "There is no such index in current Array!";
        return;
    } else {
        currentSize++;
        allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
        if(currentSize == index){
            allocatedMemory[currentSize-1] = value;
            return;
        } else {
            for(int i = currentSize - 1; i > index; i--) {
                allocatedMemory[i] = allocatedMemory[i - 1];
            }
            allocatedMemory[index] = value;
            return;
        }
    }
}

void MyArray::addElementFront(int value) {
    currentSize++;
    allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
    if(currentSize < 2){
        allocatedMemory[currentSize-1] = value;
        return;
    } else {
        for(int i = currentSize; i > 0; i--) {
            allocatedMemory[i] = allocatedMemory[i - 1];
        }
        allocatedMemory[0] = value;
        return;
    }
}

void MyArray::addElementBack(int value) {
    currentSize++;
    allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
    allocatedMemory[currentSize-1] = value;
}

void MyArray::addManyElements(int amount) {
    for(int i = 0; i < amount; i++) {
        addElementBack(HelpingTools::getRandomNumber());
    }
}

void MyArray::removeElement(int index) {
    if (index < 0 || index > currentSize || currentSize == 0) {
        std::cout << "There is no such index in current Array!";
        return;
    } else {
        if(currentSize == index){
            currentSize--;
            allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
            return;
        } else {
            for(int i = index; i < currentSize-1; i++) {
                allocatedMemory[i] = allocatedMemory[i + 1];
            }
            currentSize--;
            allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
            return;
        }
    }
}

void MyArray::removeElementBack() {
    if(currentSize == 0)
        return;
    currentSize--;
    allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
}

void MyArray::removeElementFront() {
    if(currentSize == 0)
        return;
    for(int i = 0; i < currentSize-1; i++) {
        allocatedMemory[i] = allocatedMemory[i + 1];
    }
    currentSize--;
    allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
}

void MyArray::removeManyElements(int amount) {
    for(int i = 0; i < amount; i++) {
        if(currentSize == 0)
            return;
        currentSize--;
        allocatedMemory = (int *) realloc(allocatedMemory, currentSize*sizeof(int));
    }
}

void MyArray::searchForFirstAppearance(int value) {
    for (int i = 0; i<= currentSize; i++) {
        if(allocatedMemory[i] == value) {
            std::cout << "First appearance of a given value is under such index: " << i;
            return;
        }
    }
    std::cout << "there is no such value within array!";
}

void MyArray::searchUnderIndex(int index) {
    if(index>=0 && index < currentSize){
        std::cout << "Given index contains such value:" <<  allocatedMemory[index];
        return;
    }
    std::cout << "there is no such index!";
}

void MyArray::getSizeInfo() {
    std::cout << "the array contains given amount of elements: " << currentSize;
}

void MyArray::removeArray() {
    currentSize = 0;
    delete [] allocatedMemory;
}

void MyArray::printArray() {
    if (currentSize == 0) {
        std::cout << "Array is empty!";
    } else {
        for (int i = 0; i < currentSize; i++) {
            std::cout << allocatedMemory[i] << "  ";
        }
    }
}

void MyArray::loadFromFile(){
    std::ifstream file("..\\dane.txt");
    int amount;
    int value;
    file >> amount;
    for(int i = 0; i < amount; i++) {
        file >> value;
        addElementBack(value);
    }
    file.close();
}

void MyArray::addValueByHand() {
    int ind;
    int val;
    std::cout << "choose index of addition: ";
    std::cin >> ind;
    std::cout << "\nchoose value of addition: ";
    std::cin >> val;
    addElement(ind, val);
}
