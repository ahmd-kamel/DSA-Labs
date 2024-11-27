#ifndef QUEUE_H
#define QUEUE_H

using namespace std;
#include "node.h"

class Queue
{
    int size;
    int* arr;
    int front;
    int rear;

    public:

        bool isEmpty()
        {
            return front == rear;
        }

        bool isFull()
        {
            return (rear + 1) % size  == front;
        }

        bool enqueue(int data)
        {
            if(isFull())
            {
                return false;
            }
            else
            {
                front = (front == -1) ? 0 : front;
                arr[rear] = data;
                rear = (rear + 1) % size;
                return true;
            }
        }

        bool dequeue(int &data)
        {
            if(isEmpty())
            {
                return false;
            }
            else
            {
                data = arr[front];
                front = (front == rear) ? front = rear = -1 : (front + 1) % size;
                return true;
            }
        }

        void displayQueue()
        {
            if (isEmpty())
            {
                cout << "Queue is empty!" << endl;
                return;
            }

            cout << "Queue elements: ";
            int current = front;
            while (current != rear)
            {
                cout << "arr[" << current << "] = " << arr[current] << " ";
                current = (current + 1) % size;
            }
            cout << endl;
        }

        Queue(int size)
        {
            this->size = size;
            arr = new int[size];
            front = rear = -1;
        }

        ~Queue()
        {
            delete [] arr;
        }

};

#endif