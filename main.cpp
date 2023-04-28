#include <iostream>
#include "myArray/MyArray.h"
#include "helpingTools/MyMenu.h"
#include "myList/MyList.h"
#include "myHeap/MyHeap.h"
#include "MyTree/MyTree.h"
#include <cstdlib>
#include <unistd.h>
#include <windows.h>

long long counterStart = 0;
double PCFreq = 0.0;
void arrayMenu();
void listMenu();
void heapMenu();
void treeMenu();
void startClock();
double stopClock();

int main() {



    srand(time(nullptr));
    int userChoice;
    do {
        system("cls");
        std::cout << "Choose on which structure do you want to work with:\n";
        std::cout << "1. Array\n";
        std::cout << "2. List\n";
        std::cout << "3. Heap\n";
        std::cout << "4. Black-Red Tree\n";
        std::cout << "5. Quit\n";
        userChoice = MyMenu::getUserInput();
        switch(userChoice) {
            case 1:
                arrayMenu();
                break;
            case 2:
                listMenu();
                break;
            case 3:
                heapMenu();
                break;
            case 4:
                treeMenu();
                break;
            default:
                break;

        }
    } while(userChoice != 5);
    std::cout << "Thank you for using the application!";
}

void arrayMenu(){
    int userChoice;
    int userInput;
    double operationTime=0;
    int val;
    int ind;
    MyArray myArray;
    do {
        system("cls");
        MyMenu::showArrayOptions();
        if(myArray.getSize()<15) {
            std::cout << "preview of an array: \n[ ";
            myArray.printArray();
            std::cout << "]\n";
        }
        std::cout << "\nperformance time of last operation in microseconds: " << operationTime;
        userChoice = MyMenu::getUserInput();
        switch(userChoice){
            case 1:
                system("cls");
                std::cout << "Choose index of placement: ";
                std::cin >> ind;
                std::cout << "Choose value: ";
                std::cin >> val;
                startClock();
                myArray.addElement(ind, val);
                operationTime = stopClock();
                break;
            case 2:
                std::cout << "Choose value: ";
                std::cin >> val;
                startClock();
                myArray.addElementFront(val);
                operationTime = stopClock();
                break;
            case 3:
                std::cout << "Choose value: ";
                std::cin >> val;
                startClock();
                myArray.addElementBack(val);
                operationTime = stopClock();
                break;
            case 4:
                system("cls");
                std::cout << "Choose amount of values to add: ";
                std::cin >> val;
                startClock();
                myArray.addManyElements(val);
                operationTime = stopClock();
                break;
            case 5:
                system("cls");
                std::cout << "Choose index of removing operation: ";
                std::cin >> ind;
                startClock();
                myArray.removeElement(ind);
                operationTime = stopClock();
                break;
            case 6:
                startClock();
                myArray.removeElementFront();
                operationTime = stopClock();
                break;
            case 7:
                startClock();
                myArray.removeElementBack();
                operationTime = stopClock();
                break;
            case 8:
                system("cls");
                std::cout << "Choose amount of values to remove: ";
                std::cin >> userInput;
                startClock();
                myArray.removeManyElements(userInput);
                operationTime = stopClock();
                break;
            case 9:
                system("cls");
                std::cout << "Choose value which you are searching for: ";
                std::cin >> val;
                startClock();
                myArray.searchForFirstAppearance(val);
                operationTime = stopClock();
                sleep(3);
                break;
            case 10:
                system("cls");
                std::cout << "Choose index of which value you want to check: ";
                std::cin >> ind;
                startClock();
                myArray.searchUnderIndex(ind);
                operationTime = stopClock();
                sleep(3);
                break;
            case 11:
                system("cls");
                startClock();
                myArray.getSizeInfo();
                operationTime = stopClock();
                sleep(3);
                break;
            case 12:
                system("cls");
                startClock();
                myArray.loadFromFile();
                operationTime = stopClock();
                break;
            case 13:
                system("cls");
                startClock();
                myArray.addValueByHand();
                operationTime = stopClock();
                break;
            case 14:
                system("cls");
                startClock();
                std::cout << "[ ";
                myArray.printArray();
                std::cout << "]";
                operationTime = stopClock();
                sleep(3);
                break;
            default:
                break;
        }

    } while (userChoice!=15);
    myArray.removeArray();
}

void listMenu() {
    int userChoice;
    int userInput;
    int val;
    int ind;
    double operationTime=0;
    MyList myList;
    do {
        system("cls");
        MyMenu::showListOptions();
        if(myList.getSize()<15) {
            std::cout << "preview of an List: \n[ ";
            myList.printList();
            std::cout << "]\n";
        }
        std::cout << "\nperformance time of last operation in microseconds: " << operationTime;
        userChoice = MyMenu::getUserInput();

        switch(userChoice){
            case 1:
                system("cls");
                std::cout << "Choose index of placement: ";
                std::cin >> ind;
                std::cout << "Choose value: ";
                std::cin >> val;
                startClock();
                myList.addNode(ind, val);
                operationTime = stopClock();
                break;
            case 2:
                system("cls");
                std::cout << "Choose value: ";
                std::cin >> val;
                startClock();
                myList.addNodeFront(val);
                operationTime = stopClock();
                break;
            case 3:
                system("cls");
                std::cout << "Choose value: ";
                std::cin >> val;
                startClock();
                myList.addNodeBack(val);
                operationTime = stopClock();
                break;
            case 4:
                system("cls");
                std::cout << "Choose amount of values to add: ";
                std::cin >> val;
                startClock();
                myList.addManyNodes(val);
                operationTime = stopClock();
                break;
            case 5:
                system("cls");
                std::cout << "Choose index of removing operation: ";
                std::cin >> ind;
                startClock();
                myList.removeNode(ind);
                operationTime = stopClock();
                break;
            case 6:
                startClock();
                myList.removeNodeFront();
                operationTime = stopClock();
                break;
            case 7:
                startClock();
                myList.removeNodeBack();
                operationTime = stopClock();
                break;
            case 8:
                system("cls");
                std::cout << "Choose amount of nodes to remove: ";
                std::cin >> userInput;
                startClock();
                myList.removeManyNodes(userInput);
                operationTime = stopClock();
                break;
            case 9:
                system("cls");
                std::cout << "Choose value which you are searching for: ";
                std::cin >> userInput;
                startClock();
                myList.searchForFirstAppearance(userInput);
                operationTime = stopClock();
                sleep(3);
                break;
            case 10:
                system("cls");
                std::cout << "Choose index of which value you want to check: ";
                std::cin >> userInput;
                startClock();
                myList.searchUnderIndex(userInput);
                operationTime = stopClock();
                sleep(3);
                break;
            case 11:
                system("cls");
                startClock();
                myList.getSizeInfo();
                operationTime = stopClock();
                sleep(3);
                break;
            case 12:
                system("cls");
                startClock();
                myList.loadFromFile();
                operationTime = stopClock();
                break;
            case 13:
                system("cls");
                startClock();
                myList.addByHand();
                operationTime = stopClock();
                break;
            case 14:
                system("cls");
                startClock();
                std::cout << "[";
                myList.printList();
                std::cout << "]";
                operationTime = stopClock();
                sleep(3);
                break;
            default:
                break;
        }
    } while (userChoice!=15);
    myList.deleteList();

}

void heapMenu(){
    int userChoice;
    int userInput;
    double operationTime=0;



    MyHeap myHeap;
    do {
        system("cls");
        MyMenu::showHeapOptions();
        if(myHeap.getSize()<15) {
            std::cout << "preview of a heap: \n ";
            myHeap.printHeap();
            std::cout << "\n";
        }
        std::cout << "\nperformance time of last operation in microseconds: " << operationTime;
        userChoice = MyMenu::getUserInput();

        switch(userChoice){
            case 1:
                system("cls");
                startClock();
                myHeap.addNode();
                operationTime = stopClock();
                break;
            case 2:
                system("cls");
                std::cout << "Choose amount of elements to add: ";
                std::cin >> userInput;
                startClock();
                myHeap.addManyNodes(userInput);
                operationTime = stopClock();
                break;
            case 3:
                system("cls");
                std::cout << "Choose index of removing Operation: ";
                std::cin >> userInput;
                startClock();
                myHeap.removeUnderIndex(userInput);
                operationTime = stopClock();
                break;
            case 4:
                system("cls");
                startClock();
                myHeap.removeYoungestLeaf();
                operationTime = stopClock();
                break;
            case 5:
                system("cls");
                std::cout << "Choose amount of elements to remove: ";
                std::cin >> userInput;
                startClock();
                myHeap.removeManyNodes(userInput);
                operationTime = stopClock();
                break;
            case 6:
                system("cls");
                std::cout << "choose value of search: ";
                std::cin >> userInput;
                startClock();
                if(myHeap.searchForValue(userInput))
                    std::cout << "there is a given value within a heap";
                else
                    std::cout << "there is no given value within a heap";
                operationTime = stopClock();
                sleep(3);
                break;
            case 7:
                system("cls");
                std::cout << "choose index which do you want to check: ";
                std::cin >> userInput;
                startClock();
                myHeap.searchUnderIndex(userInput);
                operationTime = stopClock();
                sleep(3);
                break;
            case 8:
                system("cls");
                startClock();
                std::cout << "root has such value: " << myHeap.getMax();
                operationTime = stopClock();
                sleep(3);
                break;
            case 9:
                system("cls");
                startClock();
                myHeap.extractMax();
                operationTime = stopClock();
                break;
            case 10:
                system("cls");
                startClock();
                myHeap.getSizeInfo();
                operationTime = stopClock();
                sleep(3);
                break;
            case 11:
                system("cls");
                startClock();
                myHeap.loadFromFile();
                operationTime = stopClock();
                break;
            case 12:
                system("cls");
                startClock();
                operationTime = stopClock();
                myHeap.addByHand();
                break;
            case 13:
                system("cls");
                startClock();
                myHeap.printHeap();
                operationTime = stopClock();
                sleep(3);
                break;
            default:
                break;
        }
    } while (userChoice!=14);
    myHeap.deleteHeap();

}

void treeMenu(){
    int userChoice;
    int userInput;
    double operationTime=0;

    MyTree myTree;
    do {
        system("cls");
        MyMenu::showTreeOptions();
        if(myTree.getSize()<15) {
            std::cout << "preview of a Tree: \n ";
            myTree.printTree();
            std::cout << "\n";
        }
        std::cout << "\nperformance time of last operation in microseconds: " << operationTime;
        userChoice = MyMenu::getUserInput();

        switch(userChoice){
            case 1:
                system("cls");
                std::cout << "choose value of addition: ";
                std::cin >> userInput;
                startClock();
                myTree.addValue(userInput);
                operationTime = stopClock();
                break;
            case 2:
                system("cls");
                std::cout << "Choose amount of elements to add: ";
                std::cin >> userInput;
                startClock();
                myTree.addMultipleElements(userInput);
                operationTime = stopClock();
                break;
            case 3:
                system("cls");
                std::cout << "Choose value of removing Operation: ";
                std::cin >> userInput;
                startClock();
                myTree.deleteValue(userInput);
                operationTime = stopClock();
                break;
            case 4:
                system("cls");
                std::cout << "choose value of searching: ";
                std::cin >> userInput;
                startClock();
                if(myTree.searchIfExist(userInput)){
                    std::cout << "yes, tree contains given value";
                } else{
                    std::cout << "there is no such element within tree";
                }
                operationTime = stopClock();
                sleep(3);
                break;
            case 5:
                system("cls");
                startClock();
                myTree.loadFromFile();
                operationTime = stopClock();
                break;
            case 6:
                system("cls");
                startClock();
                myTree.printTree();
                operationTime = stopClock();
                sleep(3);
                break;
            case 7:
                system("cls");
                startClock();
                std::cout << "root contains given value: " << myTree.getRoot();
                operationTime = stopClock();
                sleep(3);
                break;
            default:
                break;
        }
    } while (userChoice!=8);
    myTree.deleteTree();
}

void startClock() {
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        std::cout << "Couldn't start clock! Try again.\n";

    PCFreq = double(li.QuadPart) / 1000000.0;
    QueryPerformanceCounter(&li);
    counterStart = li.QuadPart;
}

double stopClock() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - counterStart) / PCFreq;
}
