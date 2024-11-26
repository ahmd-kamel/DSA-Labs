#include <iostream>
#include "LinkedList.h"
using namespace std;


int main()
{
    LinkedList mylist;
    mylist.add(3);
    mylist.add(5);
    mylist.add(10);
    mylist.add(11);

    mylist.display();

    // Handling Insertion After
    mylist.insetAfter(5, 3);
    mylist.display();
    mylist.insetAfter(5, 11);
    mylist.display();
    mylist.insetAfter(5, 10);
    mylist.display();

    // Handling Insertion Before
    mylist.insetBefore(0, 3);
    mylist.display();
    mylist.insetBefore(0, 11);
    mylist.display();
    mylist.insetBefore(0, 10);
    mylist.display();

    // Handling Indexing
    cout <<"Data of idx [0] : " << mylist.getDataByIndex(0) << endl;
    cout <<"Data of idx [5] : " << mylist.getDataByIndex(5) << endl;

    // Handling Indexing
    cout <<"Size of Double Linked List : " << mylist.getCount() << endl;
    return 0;
}