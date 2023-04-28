//
// Created by kubas on 11.04.2023.
//

#include "HelpingTools.h"
#include <profileapi.h>

int HelpingTools::getRandomNumber() {
    if(rand() % 2 == 0)
        return (rand() % 99000) + 1000;
    return -1 * ((rand() % 99000) + 1000);

}

int HelpingTools::getRandomForHeap(){
    return (rand() % 99000) + 1000;
}


