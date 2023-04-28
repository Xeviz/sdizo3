//
// Created by kubas on 10.04.2023.
//

#ifndef SDIZO1_MYARRAY_H
#define SDIZO1_MYARRAY_H


class MyArray {
private:
    int* allocatedMemory;
    int currentSize;
public:
    MyArray();
    void addElement(int index, int value);
    void addElementFront(int value);
    void addElementBack(int value);
    void addManyElements(int amount);
    void removeElementFront();
    void removeElementBack();
    void removeElement(int index);
    void removeManyElements(int amount);
    void searchForFirstAppearance(int value);
    void searchUnderIndex(int index);
    void getSizeInfo();
    void removeArray();
    void printArray();
    void loadFromFile();
    void addValueByHand();
    int getSize();

};


#endif //SDIZO1_MYARRAY_H
