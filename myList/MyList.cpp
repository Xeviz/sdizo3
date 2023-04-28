//
// Created by kubas on 11.04.2023.
//

#include <iostream>
#include <fstream>
#include "MyList.h"

MyList::MyList(){
    currentSize = 0;
    currentElement = nullptr;
    head = nullptr;
    tail = nullptr;
}

ListNode* MyList::findBeginning() {

    ListNode* current = head;
    return current;

}

ListNode* MyList::findEnd() {
    ListNode* current = tail;
    return current;
}

void MyList::addNodeFront(){
    ListNode* newNode = new ListNode();

    if(currentSize==0){
        currentElement = newNode;
        head = newNode;
        tail = newNode;
    } else if(currentSize==1){
        currentElement = newNode;
        head = newNode;
        head->setNext(tail);
        tail->setPrev(newNode);
    } else {
        currentElement = newNode;
        head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;
    }
    currentSize++;
}

void MyList::addNodeFront(int value){
    ListNode* newNode = new ListNode(value);

    if(currentSize==0){
        currentElement = newNode;
        head = newNode;
        tail = newNode;
    } else if(currentSize==1){
        currentElement = newNode;
        head = newNode;
        head->setNext(tail);
        tail->setPrev(newNode);
    } else {
        currentElement = newNode;
        head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;
    }
    currentSize++;
}

void MyList::addNodeBack() {
    ListNode* newNode = new ListNode();

    if(currentSize==0){
        currentElement = newNode;
        head = newNode;
        tail = newNode;
    } else if(currentSize==1){
        currentElement = newNode;
        tail = newNode;
        tail->setPrev(head);
        head->setNext(newNode);
    } else {
        currentElement = newNode;
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    currentSize++;
}

void MyList::addNodeBack(int value) {
    ListNode* newNode = new ListNode(value);

    if(currentSize==0){
        currentElement = newNode;
        head = newNode;
        tail = newNode;
    } else if(currentSize==1){
        currentElement = newNode;
        tail = newNode;
        tail->setPrev(head);
        head->setNext(newNode);
    } else {
        currentElement = newNode;
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    currentSize++;
}

void MyList::addNode(int index, int value) {
    if (index > currentSize) {
        std::cout << "Desired index is out of bounds!" << std::endl;
        return;
    }
    else if (index == currentSize) {
        addNodeBack(value);
        return;
    }
    else if (index == 0) {
        addNodeFront(value);
        return;
    }

    ListNode* newNode = new ListNode(value);
    ListNode* current = findBeginning();

    for (int i = 0; i < index - 1; i++) {
        current = current->getNext();
    }

    newNode->setNext(current->getNext());
    newNode->setPrev(current);
    current->getNext()->setPrev(newNode);
    current->setNext(newNode);

    currentSize++;
}

void MyList::addManyNodes(int amount) {
    for(int i = 0; i<amount; i++) {
        addNodeBack();
    }
}

void MyList::removeNodeFront() {
    if (currentSize == 0) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    ListNode* beginning = findBeginning();

    if (beginning->getNext() != nullptr) {
        head = beginning->getNext();
        beginning->getNext()->setPrev(nullptr);
    } else
        head = nullptr;

    if (currentElement == beginning) {
        currentElement = beginning->getNext();
    }

    delete beginning;

    currentSize--;
}

void MyList::removeNodeBack() {
    if (currentSize == 0) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    ListNode* end = findEnd();

    if (end->getPrev() != nullptr) {
        tail = end->getPrev();
        end->getPrev()->setNext(nullptr);
    } else
        tail = nullptr;

    if (currentElement == end) {
        currentElement = end->getPrev();
    }

    delete end;

    currentSize--;
}

void MyList::removeNode(int index) {
    if (index >= currentSize) {
        std::cout << "Desired index is out of bounds!" << std::endl;
        return;
    }
    else if (index == 0) {
        removeNodeFront();
        return;
    }
    else if (index == currentSize - 1) {
        removeNodeBack();
        return;
    }
    ListNode* current = findBeginning();

    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }

    current->getPrev()->setNext(current->getNext());
    current->getNext()->setPrev(current->getPrev());

    delete current;

    currentSize--;
}

void MyList::removeManyNodes(int amount) {

    if(amount<=currentSize) {
        for(int i = 0; i<amount; i++) {
            removeNodeBack();
        }
        return;
    } else {
        std::cout << "There are not enough elements to delete them!";
        return;
    }
}

void MyList::printList() {
    if (currentSize == 0) {
        std::cout << "List is empty! ";
        return;
    }
    ListNode* current = findBeginning();
    while (current != nullptr) {
        std::cout << current->getValue();
        if (current->getNext() != nullptr) {
            std::cout << " ";
        }
        current = current->getNext();
    }
}

void MyList::searchUnderIndex(int index) {
    if (currentSize == 0) {
        std::cout << "There is no such index" << std::endl;
        return;
    }

    if (index > currentSize - 1) {
        std::cout << "There is no such index" << std::endl;
        return;
    }

    ListNode* node;

    if (index > currentSize / 2) {
        node = findEnd();
        for (int i = currentSize - 1; i > index; i--) {
            node = node->getPrev();
        }
    }
    else {
        node = findBeginning();
        for (int i = 0; i < index; i++) {
            node = node->getNext();
        }
    }

    std::cout << "Value of element at index " << index << " is: " << node->getValue() << std::endl;
}

void MyList::searchForFirstAppearance(int value) {

    if(currentSize==0){
        std::cout << "There is no such value within List!" << std::endl;
        return;
    }

    ListNode* ptr = findBeginning();
    int index = 0;
    while (ptr != nullptr) {
        if (ptr->getValue() == value) {
            std::cout << "The value " << value << " appears for the first time at index " << index << std::endl;
            return;
        }
        ptr = ptr->getNext();
        index++;
    }
    std::cout << "There is no such value within List!" << std::endl;
}

void MyList::deleteList() {
    ListNode* current = findBeginning();
    while (current != nullptr) {
        ListNode* next = current->getNext();
        delete current;
        current = next;
    }
    currentElement = nullptr;
    currentSize = 0;
}

void MyList::getSizeInfo() {
    std::cout << "The list contains given amount of elements: " << currentSize;
}

void MyList::loadFromFile(){
    std::ifstream file("..\\dane.txt");
    int amount;
    int value;
    file >> amount;
    for(int i = 0; i < amount; i++) {
        file >> value;
        addNodeBack(value);
    }
    file.close();
}

void MyList::addByHand() {
    int val;
    std::cout << "\nchoose value of addition: ";
    std::cin >> val;
    addNodeBack(val);
}

int MyList::getSize(){
    return currentSize;
}