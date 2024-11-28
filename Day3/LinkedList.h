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

    void disconnectNode(Node* node) 
    {
        if (node == NULL) 
            return; 

        if (node == head) 
        {
            head = node->Next;
            if(head) head->Prev = NULL;
        }
        else if(node == tail)
        {
            tail = node->Prev;
            if(tail) head->Next = NULL;
        }
        else
        {
            node->Prev->Next = node->Next;
            node->Next->Prev = node->Prev;
        }

        node->Prev = NULL;
        node->Next = NULL;

    }

    void insertAfter(Node* nodeToInsert, Node* nodeToInsertAfter)
    {
        if (nodeToInsertAfter == NULL) 
        {
            cout << "The node to insert after cannot be nullptr!" << endl;
            return;
        }

        if (nodeToInsertAfter == head) 
        {
            nodeToInsert->Next = head->Next;
            nodeToInsert->Prev = head;
            if (head->Next != NULL) 
            {
                head->Next->Prev = nodeToInsert;
            }
            head->Next = nodeToInsert;
            return;
        }

        if (nodeToInsertAfter == tail) 
        {
            nodeToInsert->Prev = tail;
            tail->Next = nodeToInsert;
            tail = nodeToInsert;
            return;
        }

        nodeToInsert->Prev = nodeToInsertAfter;
        nodeToInsert->Next = nodeToInsertAfter->Next;
        if (nodeToInsertAfter->Next != NULL) 
        {
            nodeToInsertAfter->Next->Prev = nodeToInsert;
        }
        nodeToInsertAfter->Next = nodeToInsert;
    }

    void bubbleSortSN()
    {
        if (head == NULL || head->Next == NULL) 
            return;

        bool swapped;
        int iterations = 0;
        Node* temp, *tempNext;

        do 
        {
            swapped = false;
            temp = head;

            while (temp != NULL && temp->Next != NULL) 
            {
                if (temp->Data > temp->Next->Data) 
                {
                    tempNext = temp->Next;
                    disconnectNode(temp);
                    insertAfter(temp, tempNext);
                    swapped = true;
                }
                else
                {
                    temp = temp->Next;
                }
                iterations++;
            }
        } while (swapped);
        cout << "Iterations : " << iterations << endl;
    }

    void bubbleSortSD() 
    {
        if (head == NULL || head->Next == NULL) 
            return;

        bool swapped;
        Node* temp;

        do 
        {
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
