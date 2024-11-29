#include <iostream>
#include "trees.h"
using namespace std;

int main()
{
    BinaryTree bTree;
    bTree.insert(20);
    bTree.insert(10);
    bTree.insert(5);
    bTree.insert(15);
    bTree.insert(30);
    bTree.insert(40);
    bTree.insert(50);

    bTree.inorderTraverse();
    cout << "Max depth: " << bTree.getMaxDepth() << endl;

    return 0;
}