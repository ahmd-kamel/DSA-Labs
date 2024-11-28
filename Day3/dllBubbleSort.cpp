#include <iostream>
#include "LinkedList.h"

using namespace std;


int main()
{
    LinkedList list;
    list.add(9);
    list.add(8);
    list.add(6);
    list.add(1);
    list.add(7);
    list.display();

    list.bubbleSort();
    list.display();

    return 0;
}