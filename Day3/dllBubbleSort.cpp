#include <iostream>
#include "LinkedList.h"

using namespace std;

void swapArray(int & first , int & second)
{
    int temp=first;
    first=second;
    second=temp;
}
void bubbleSort(int *items,int size)
{
    int iterations=0,sorted=0;
    for(int j=0; sorted==0; j++)
    {//J=0,1,2,3,4,5 ==>1,3,4,5,6,8
        sorted=1;
        for(int i=0; i<size-1-j; i++)
        { //0 --> 4
        //Flag
            if(items[i]>items[i+1])
            {
                //Swap
                swapArray(items[i],items[i+1]);
                sorted=0;
            }
            iterations++;
        }

    }
    cout << "Iterations : " << iterations << endl;
}

void displayArray(int *items,int size)
{

    for(int i=0; i<size; i++)
    {
        cout<<items[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[5]={9,8,6,1,7};

    bubbleSort(arr,5);
    displayArray(arr,5);
    cout<<"============================"<<endl;
    LinkedList list;
    list.add(9);
    list.add(8);
    list.add(6);
    list.add(1);
    list.add(7);
    list.display();

    list.bubbleSortSN();
    list.display();

    // list.bubbleSortSD();
    // list.display();

    return 0;
}