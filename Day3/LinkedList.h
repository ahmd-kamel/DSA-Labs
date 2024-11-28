#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void add(int data)
    {
        Node *node = new Node(data);
        if (head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->Next = node;
            node->Prev = tail;
            tail = node;
        }
    }

    void display()
    {
        Node *current = head;
        if (current == nullptr)
        {
            cout << "Linked List is Empty \n";
            return;
        }
        while (current != nullptr)
        {
            cout << current->Data << "\t";
            current = current->Next;
        }
        cout << endl;
    }

    void swapData(Node* node1, Node* node2) 
    {
        int temp = node1->Data;
        node1->Data = node2->Data;
        node2->Data = temp;
    }


    void bubbleSort() {
        if (head == NULL || head->Next == NULL) 
            return;

        bool swapped;
        Node* temp;

        do {
            swapped = false;
            temp = head;

            while (temp != NULL && temp->Next != NULL) 
            {
                if (temp->Data > temp->Next->Data) 
                {
                    swapData(temp, temp->Next);
                    swapped = true;
                }
                temp = temp->Next;
            }
        } while (swapped);
    }
};

#endif // LINKEDLIST_H
