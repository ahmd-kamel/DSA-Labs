#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node * next;
        int data;
        Node(int data){
            this->data = data;
            next = NULL;
        }

    protected:

    private:
};

#endif // NODE_H