//
// Created by kubas on 11.04.2023.
//

#include "MyMenu.h"
#include "../myArray/MyArray.h"
#include "HelpingTools.h"
#include "../myList/MyList.h"
#include "../myHeap/MyHeap.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>


void MyMenu::showOptions() {

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
        userChoice = getUserInput();
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
                std::cout << "AVL Tree";
                break;
            default:
                break;

        }
    } while(userChoice != 5);
    std::cout << "Thank you for using the application!";


}

int MyMenu::getUserInput() {
    int choice;
    std::cout << "\n=============\nYour Choice: ";
    std:: cin >> choice;
    return choice;

}

void MyMenu::showArrayOptions() {
    std::cout << "Choose what operation do you want to perform:\n";
    std::cout << "1. Add element in specified index\n";
    std::cout << "2. Add element in front\n";
    std::cout << "3. Add element on back\n";
    std::cout << "4. Add multiple elements\n";
    std::cout << "5. Remove element from specified index\n";
    std::cout << "6. Remove element on front\n";
    std::cout << "7. Remove element on back\n";
    std::cout << "8. Remove multiple elements\n";
    std::cout << "9. Search for for first appearance of specified value\n";
    std::cout << "10. Search for value under specified index\n";
    std::cout << "11. Check how many elements the array contains\n";
    std::cout << "12. Load array from a file\n";
    std::cout << "13. Add element manually\n";
    std::cout << "14. print Array\n";
    std::cout << "15. Delete whole array and quit\n";

}

void MyMenu::arrayMenu(){
    int userChoice;
    int userInput;
    MyArray myArray;
    do {
        system("cls");
        showArrayOptions();
        std::cout << "\npreview of an array:\n[ ";
        myArray.printArray();
        std::cout << " ]";
        userChoice = getUserInput();

        switch(userChoice){
            case 1:
                system("cls");
                std::cout << "Choose index of placement: ";
                std::cin >> userInput;
                myArray.addElement(userInput, HelpingTools::getRandomNumber());
                sleep(3);
                break;
            case 2:
                myArray.addElementFront(HelpingTools::getRandomNumber());
                break;
            case 3:
                myArray.addElementBack(HelpingTools::getRandomNumber());
                break;
            case 4:
                system("cls");
                std::cout << "Choose amount of values to add: ";
                std::cin >> userInput;
                myArray.addManyElements(userInput);
                break;
            case 5:
                system("cls");
                std::cout << "Choose index of removing operation: ";
                std::cin >> userInput;
                myArray.removeElement(userInput);
                break;
            case 6:
                myArray.removeElementFront();
                break;
            case 7:
                myArray.removeElementBack();
                break;
            case 8:
                system("cls");
                std::cout << "Choose amount of values to remove: ";
                std::cin >> userInput;
                myArray.removeManyElements(userInput);
                break;
            case 9:
                system("cls");
                std::cout << "Choose value which you are searching for: ";
                std::cin >> userInput;
                myArray.searchForFirstAppearance(userInput);
                sleep(3);
                break;
            case 10:
                system("cls");
                std::cout << "Choose index of which value you want to check: ";
                std::cin >> userInput;
                myArray.searchUnderIndex(userInput);
                sleep(3);
                break;
            case 11:
                system("cls");
                myArray.getSizeInfo();
                sleep(3);
                break;
            default:
                break;
        }
    } while (userChoice!=12);
    myArray.removeArray();
}

void MyMenu::showListOptions() {
    std::cout << "Choose what operation do you want to perform:\n";
    std::cout << "1. Add element in specified index\n";
    std::cout << "2. Add element in front\n";
    std::cout << "3. Add element on back\n";
    std::cout << "4. Add multiple elements\n";
    std::cout << "5. Remove element from specified index\n";
    std::cout << "6. Remove element on front\n";
    std::cout << "7. Remove element on back\n";
    std::cout << "8. Remove multiple elements\n";
    std::cout << "9. Search for for first appearance of specified value\n";
    std::cout << "10. Search for value under specified index\n";
    std::cout << "11. Check how many elements the list contains\n";
    std::cout << "12. Load list from file\n";
    std::cout << "13. Add element manually\n";
    std::cout << "14. printList\n";
    std::cout << "15. Delete whole list and quit\n";
}

void MyMenu::listMenu() {
    int userChoice;
    int userInput;
    MyList myList;
    do {
        system("cls");
        showListOptions();
        std::cout << "\npreview of an List:\n[ ";
        myList.printList();
        std::cout << "]";
        userChoice = getUserInput();

        switch(userChoice){
            case 1:
                system("cls");
                std::cout << "Choose index of placement: ";
                std::cin >> userInput;
                myList.addNode(userInput, userInput);
                break;
            case 2:
                myList.addNodeFront();
                break;
            case 3:
                myList.addNodeBack();
                break;
            case 4:
                system("cls");
                std::cout << "Choose amount of values to add: ";
                std::cin >> userInput;
                myList.addManyNodes(userInput);
                break;
            case 5:
                system("cls");
                std::cout << "Choose index of removing operation: ";
                std::cin >> userInput;
                myList.removeNode(userInput);
                break;
            case 6:
                myList.removeNodeFront();
                break;
            case 7:
                myList.removeNodeBack();
                break;
            case 8:
                system("cls");
                std::cout << "Choose amount of nodes to remove: ";
                std::cin >> userInput;
                myList.removeManyNodes(userInput);
                break;
            case 9:
                system("cls");
                std::cout << "Choose value which you are searching for: ";
                std::cin >> userInput;
                myList.searchForFirstAppearance(userInput);
                sleep(3);
                break;
            case 10:
                system("cls");
                std::cout << "Choose index of which value you want to check: ";
                std::cin >> userInput;
                myList.searchUnderIndex(userInput);
                sleep(3);
                break;
            case 11:
                system("cls");
                myList.getSizeInfo();
                sleep(3);
                break;
            default:
                break;
        }
    } while (userChoice!=12);
    myList.deleteList();

}

void MyMenu::showHeapOptions(){
    std::cout << "Choose what operation do you want to perform:\n";
    std::cout << "1. Add element\n";
    std::cout << "2. Add multiple elements\n";
    std::cout << "3. Remove element\n";
    std::cout << "4. Remove youngest leaf\n";
    std::cout << "5. Remove multiple elements\n";
    std::cout << "6. Search for specified value\n";
    std::cout << "7. Search under specified index\n";
    std::cout << "8. get root value\n";
    std::cout << "9. Remove root\n";
    std::cout << "10. Check currentSize of a Heap\n";
    std::cout << "11. load Heap from file\n";
    std::cout << "12. Add element manually\n";
    std::cout << "13. print Heap\n";
    std::cout << "14. Delete whole Heap and quit\n";
}

void MyMenu::heapMenu(){
    int userChoice;
    int userInput;
    MyHeap myHeap;
    do {
        system("cls");
        showHeapOptions();
        std::cout << "\npreview of a Heap:\n";
        myHeap.printHeap();
        userChoice = getUserInput();

        switch(userChoice){
            case 1:
                system("cls");
                myHeap.addNode();
                break;
            case 2:
                system("cls");
                std::cout << "Choose amount of elements to add: ";
                std::cin >> userInput;
                myHeap.addManyNodes(userInput);
                break;
            case 3:
                system("cls");
                std::cout << "Choose index of removing Operation: ";
                std::cin >> userInput;
                myHeap.removeUnderIndex(userInput);
                break;
            case 4:
                system("cls");
                myHeap.removeYoungestLeaf();
                break;
            case 5:
                system("cls");
                std::cout << "Choose amount of elements to remove: ";
                std::cin >> userInput;
                myHeap.removeManyNodes(userInput);
                break;
            case 6:
                system("cls");
                std::cout << "choose value of search: ";
                std::cin >> userInput;
                if(myHeap.searchForValue(userInput))
                    std::cout << "there is a given value within a heap";
                else
                    std::cout << "there is no given value within a heap";
                sleep(3);
                break;
            case 7:
                system("cls");
                std::cout << "choose index which do you want to check: ";
                std::cin >> userInput;
                myHeap.searchUnderIndex(userInput);
                sleep(3);
                break;
            case 8:
                system("cls");
                std::cout << "root has such value: " << myHeap.getMax();
                sleep(3);
                break;
            case 9:
                system("cls");
                myHeap.extractMax();
                break;
            case 10:
                system("cls");
                myHeap.getSizeInfo();
                sleep(3);
                break;
            default:
                break;
        }
    } while (userChoice!=11);
    myHeap.deleteHeap();

}


void MyMenu::showTreeOptions() {
    std::cout << "Choose what operation do you want to perform:\n";
    std::cout << "1. Add element manually\n";
    std::cout << "2. Add multiple elements\n";
    std::cout << "3. Remove element\n";
    std::cout << "4. Search if tree contains given value\n";
    std::cout << "5. load tree from a file\n";
    std::cout << "6. print Tree\n";
    std::cout << "7. get root value\n";
    std::cout << "8. Delete whole Tree and quit\n";
}
