#include <iostream>
#include "stack.h"

using namespace std;

Stack* linearSearch(int* arr, int size, int data)
{
    Stack* results = new Stack;

    for (int i = 0; i < size; i++)
    {
        if(arr[i] == data)
        {
            results->push(i);
        }
    }
    return results;
}

int main()
{
    int arr[6] = {1, 1, 2, 2, 5, 5};
    Stack *result = linearSearch(arr, 6, 1);
    result->printStack();
    
    delete result;
    return 0;
}