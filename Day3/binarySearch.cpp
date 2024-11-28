#include <iostream>

using namespace std;


int binarySearch(int *arr, int size, int data)
{
    int start = 0, end = size - 1, mid = 0; 
    while (start <= end)
    {
        mid = (start + end) / 2;
        if(arr[mid] == data)
        {
            return mid;
        }
        else if (arr[mid] > data)
        {
            end = mid - 1;
        }
        else if (arr[mid] < data)
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    // must be sorted
    int arr[6] = {0, 1, 2, 3, 4, 5};
    cout << "Index : " << binarySearch(arr, 6, 1) << endl;
    cout << "Index : " << binarySearch(arr, 6, -5) << endl;
    return 0;
}