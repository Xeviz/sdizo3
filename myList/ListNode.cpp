//
// Created by kubas on 11.04.2023.
//

#include "ListNode.h"
#include "../helpingTools/HelpingTools.h"

ListNode::ListNode() {
    setValue();
}
ListNode::ListNode(int val) {
    setValue(val);
}

void ListNode::setValue() {
    value = HelpingTools::getRandomNumber();
}

void ListNode::setValue(int val) {
    value = val;
}

void ListNode::setNext(ListNode* node){
    next = node;
}

void ListNode::setPrev(ListNode* node){
    prev = node;
}

ListNode* ListNode::getNext() {
    return next;
}

ListNode* ListNode::getPrev() {
    return prev;
}

int ListNode::getValue() {
    return value;
}