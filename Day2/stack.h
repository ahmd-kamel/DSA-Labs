#ifndef STACK_H
#define STACK_H

using namespace std;
#include "node.h"

class Stack
{
    Node* top;

    public:
        Stack()
        {
            top = NULL;
        }

        bool isEmpty()
        {
            return top == NULL;
        }

        bool peek(int &data) 
        {
            if (top != nullptr) 
            {
                data = top->data;
                return true;
            } 
            else 
            {
                return false;
            }
        }

        void pop() 
        {
            if (!isEmpty()) 
            {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

        void push(int value) 
        {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        void printStack()
        {
            Node* current = top;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        ~Stack()
        {

        }


};

#endif