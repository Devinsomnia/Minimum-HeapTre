//
//  main.cpp
//  heapTree
//
//  Created by Tuncay Cansız on 6.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#include "HeapTree.hpp"
#include <cstdlib>
#include <ctime>
int main(int argc, const char * argv[]) {

    int index = 0;
    srand((unsigned)time(NULL));

    HeapTree *tree = new HeapTree(50);
    int *array = new int[50];

    cout << "The array is initial stuation : ";
    for (int i = 0; i < 50; i++) {
        array[i] = rand() % 100 + 1;
        tree->Add(array[i]);
        cout << array[i] << " ";
    }

    cout << "\n\n";
    while (!tree->isEmpty()) {
        array[index] = tree->SmallestMakeParent();
        index++;
    }

    cout << "The array is last status : ";
    for (int i = 0; i < 50; i++) {
        cout << array[i] << " ";
    }

    cout << "\n\n";
    delete [] array;
    delete tree;
    return 0;
}
