#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    private:
        Node * head;
        Node * tail;
        Node * getNodeUsingData(int data){
            Node *current=head;
            while(current != NULL){
                if(current->Data==data){
                    return current;
                }
                //Jump
                current=current->Next;
            }
            return NULL;
        }

    public:
        LinkedList() {
            head=tail=NULL;
        }
        void add(int data){
            //Create Node
            Node * node = new Node(data); //Create Object Node , Data=data , next,prev=null

                if(head == NULL){//First Node
                    head=tail=node;
                    //node->Next=node->prev=NULL;
                }
                else{//Not First Node
                    tail->Next =node; //Old->Next=NewNode
                    node->Prev=tail; //newNode->prev=old(Node)
                    tail=node;//tail=node;
                }
        }
        void display(){
            Node * current =head;//NULL
            if(current == NULL){
                cout<<"Linked List is Empty \n";
                return ;
            }
            while(current != NULL){
                //Display
                cout<<current->Data<<"\t";
                //Increment Jump Node
                current=current->Next;
            }
            cout<<endl;
        }


    void removeNode(int data){
        //Search Linked List
        Node * node = getNodeUsingData(data);
        if(node == NULL){
            cout<<"Element Not Found , Can't Remove \n";
            return;
        }
        else{
            //Remove First
            if(node == head){
                if(node == tail){
                    tail=head=NULL;
                }
                else{
                    head=node->Next;
                    head->Prev=NULL;
                }

            }
            else if (node == tail){ //Remove Last
                tail=node->Prev;
                tail->Next=NULL;
            }
            else{//Remove Mid
                Node * A=node->Prev;
                Node * B=node->Next;
                A->Next=B;
                B->Prev=A;
            }

            delete(node);

        }

    }

    int search_using_data(int data){
        Node * node = getNodeUsingData(data);
        if(node == NULL){
            return 0;
        }
        else{
            return 1;
        }
    }

    void insetAfter(int data, int afterData)
    {
        Node* node = getNodeUsingData(afterData);
        if (node == NULL)
        {
            cout << "There ain't node contains " << afterData << endl;
            return;
        }
        else
        {

            Node* nodeToInsert = new Node(data);

            if (node == head)
            {
                if (node == tail)
                {
                    head->Next = nodeToInsert;
                    nodeToInsert->Prev = head;
                    tail = nodeToInsert;
                }
                else
                {
                    nodeToInsert->Next = head->Next;
                    head->Next->Prev = nodeToInsert;
                    head->Next = nodeToInsert;
                    nodeToInsert->Prev = head;
                }

            }
            else if (node == tail)
            {
                tail->Next = nodeToInsert;
                nodeToInsert->Prev = tail;
                // very imp
                tail = nodeToInsert;
            }
            else
            {
                nodeToInsert->Next = node->Next;
                // very imp
                node->Next->Prev = nodeToInsert;
                nodeToInsert->Prev = node;
                node->Next = nodeToInsert;
            }
        }

    }

    void insetBefore(int data, int beforeData)
    {
        Node* node = getNodeUsingData(beforeData);
        if (node == NULL)
        {
            cout << "There ain't node contains " << beforeData << endl;
            return;
        }
        else
        {
            Node* nodeToInsert = new Node(data);
            
            if (node == head)
            {
                head->Prev = nodeToInsert;
                nodeToInsert->Next = head;
                head = nodeToInsert;
            }
            else if (node == tail)
            {
                nodeToInsert->Prev = node->Prev;
                tail->Prev->Next = nodeToInsert;
                node->Prev = nodeToInsert;
                nodeToInsert->Next = tail;
            }
            else
            {
                nodeToInsert->Prev = node->Prev;
                // very imp
                node->Prev->Next = nodeToInsert;
                nodeToInsert->Next = node;
                node->Prev = nodeToInsert;
            }
        }
    }

    int getCount()
    {
        int count = 0;
        Node* current = head;
        while (current != NULL)
        {
            count++;
            current = current->Next;
        }
        return count;
    }

    int getDataByIndex(const int index)
    {
        Node* current = head;
        for(int i = 0; i < index; i++)
        {
            current = (current == NULL) ? NULL : current->Next;
        }
        return current == NULL ? -5000 : current->Data;
    }
    protected:

};

#endif // LINKEDLIST_H
