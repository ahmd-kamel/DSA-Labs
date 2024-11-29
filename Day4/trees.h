#ifndef TREES_H
#define TREES_H

#include "node.h"
using namespace std;

class BinaryTree 
{
private:
    Node* root;

    void deleteTree(Node* node) 
    {
        if (node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void insertDisplay(Node* node) 
    {
        if (node == NULL) return;
        insertDisplay(node->left);
        cout << node->data << " ";
        insertDisplay(node->right);
    }

    void insertNode(Node* node, int value) 
    {
        if (value < node->data) 
        {
            if (node->left == NULL) 
            {
                node->left = new Node(value);
            } 
            else 
            {
                insertNode(node->left, value);
            }
        } 
        else 
        {
            if (node->right == NULL) 
            {
                node->right = new Node(value);
            } 
            else 
            {
                insertNode(node->right, value);
            }
        }
    }

    int maxDepth(Node* node)
    {
        if(node == NULL) return 0;

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return (leftDepth > rightDepth) ? 1 + leftDepth : 1 + rightDepth;
    }

public:
    BinaryTree() : root(NULL) {}

    ~BinaryTree() 
    {
        deleteTree(root);
    }

    void insert(int value) 
    {
        if (root == NULL) 
        {
            root = new Node(value);
        }
        else 
        {
            insertNode(root, value);
        }
    }

    void inorderTraverse() 
    {
        cout << "Inorder: ";
        insertDisplay(root);
        cout << endl;
    }

    int getMaxDepth()
    {
        return maxDepth(root);
    }

};

#endif