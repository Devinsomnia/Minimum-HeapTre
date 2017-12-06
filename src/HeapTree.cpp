//
//  HeapTree.cpp
//  heapTree
//
//  Created by Tuncay Cansız on 6.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#include "HeapTree.hpp"

HeapTree::HeapTree(int capacity){
    elements = new int[capacity];
    this->capacity = capacity;
    nodeCount = 0;
}

int HeapTree::ParentIndex(int index){
    return (index-1)/2;
}

void HeapTree::HeapUp(int index){
    int parentIndex,temp;
    if (index != 0) {
        parentIndex = ParentIndex(index);
        if (elements[parentIndex] > elements[index]) {
            temp = elements[parentIndex];
            elements[parentIndex] = elements[index];
            elements[index] = temp;
            HeapUp(parentIndex);
        }
    }
}

int HeapTree::LeftChildIndex(int index){
    return 2*index+1;
}

int HeapTree::RightChildIndex(int index){
    return 2*index+2;
}

void HeapTree::HeapDown(int index){
    int leftChildIndex, rightChildIndex, smallestIndex, temp;
    leftChildIndex = LeftChildIndex(index);
    rightChildIndex = RightChildIndex(index);

    if (rightChildIndex >= nodeCount) {
        if (leftChildIndex >= nodeCount) return;
        else smallestIndex = leftChildIndex;
    }
    else{
        if (elements[leftChildIndex] <= elements[rightChildIndex]) smallestIndex = leftChildIndex;
        else smallestIndex = rightChildIndex;
    }

    if (elements[index] > elements[smallestIndex]) {
        temp = elements[index];
        elements[index] = elements[smallestIndex];
        elements[smallestIndex] = temp;
        HeapDown(smallestIndex);
    }
}

void HeapTree::Add(int number){
    //if(nodeCount == capacity) throw Error;
    elements[nodeCount] = number;
    nodeCount++;
    HeapUp(nodeCount-1);
}

bool HeapTree::isEmpty()const{
    return nodeCount == 0;
}

int HeapTree::SmallestMakeParent(){
    //if(isEmpty()) throw Error;
    int smallest = elements[0];
    elements[0] = elements[nodeCount-1];
    nodeCount--;
    if (nodeCount > 0) HeapDown(0);
    return smallest;
}

HeapTree::~HeapTree(){
    delete [] elements;
}
