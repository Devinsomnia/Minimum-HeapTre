//
//  HeapTree.hpp
//  heapTree
//
//  Created by Tuncay Cansız on 6.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#ifndef HeapTree_hpp
#define HeapTree_hpp

#include <iostream>
using namespace std;

class HeapTree{
private:
    int *elements;
    int capacity;
    int nodeCount;

    int LeftChildIndex(int);
    int RightChildIndex(int);
    int ParentIndex(int);

    void HeapUp(int);
    void HeapDown(int);

public:
    HeapTree(int);
    bool isEmpty()const;
    int SmallestMakeParent();
    void Add(int);
    ~HeapTree();
};

#endif /* HeapTree_hpp */
