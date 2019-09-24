#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class  BSTree {
    Node<T> *root;

    bool privateFind(T data, Node<T>* cur)
    {
        if (!cur) { return false; }
        else if (data == cur->data) { return true; }
        else if(data < cur->data) { return this->privateFind(data, cur->left); }
        else { return this->privateFind(data, cur->right); }
    }

    bool privateInsert(T data, Node<T>*& currentNode)
    {
        if (!currentNode) { currentNode = new Node<T>{data}; return true; } // tree was empty
        else if (data <= currentNode->data) { return this->privateInsert(data, currentNode->left); }
        else { return this->privateInsert(data, currentNode->right); }
    }

    Node<T>* privateFindMaximum(Node<T>*& temp) { // Left Rightmost Node
        if ( temp->right ) { return privateFindMaximum(temp->right); }
        return temp;
    }

    bool privateRemove(T& data, Node<T>*& current) {
        // Begin searching data to delete
        if ( !current ) { return false; }
        else if (data < current->data) { return this->privateRemove(data, current->left); }
        else if (data > current->data) { return this->privateRemove(data, current->right); }
        // End searching data to delete

        /* Case 1 : Two children */
        if (current->left && current->right) {
            auto temp = this->privateFindMaximum(current->left); // Finding Left Rightmost Node
            std::swap(current->data, temp->data);
            return this->privateRemove(temp->data, current->left);
        }
        /* Case 2 : One child ( also included no child: leaf Node ) */
        auto prevCurrent = current;
        if (current->left) { current = current->left; } // Omit these if there is a leaf node
        else { current = current->right; } // Omit these if there is a leaf node
        delete prevCurrent;

        return true;
    }

    size_t privateSize(Node<T>* traverseNode)
    {
        if (!traverseNode) { return 0; }
        return (this->privateSize(traverseNode->left) + 1 + this->privateSize(traverseNode->right) );
    }

    size_t privateFindHeight(Node<T>* current)
    {
        if (!current) { return 0; }
        int left = privateFindHeight(current->left);
        int right = privateFindHeight(current->right);
        return std::max( left, right ) + 1;
    }

    void privateTraversePreOrder(Node<T>* traverse)
    {
        if (!traverse) return;

        cout << traverse->data << " ";
        privateTraversePreOrder(traverse->left);
        privateTraversePreOrder(traverse->right);
    }

    void privateTraverseInOrder(Node<T>* traverse)
    {
        if (!traverse) return;
        privateTraverseInOrder(traverse->left);
        cout << traverse->data << " ";
        privateTraverseInOrder(traverse->right);
    }

    void privateTraversePostOrder(Node<T>* traverse)
    {
        if (!traverse) return;

        privateTraversePostOrder(traverse->left);
        privateTraversePostOrder(traverse->right);
        cout << traverse->data << " ";
    }

public:
        BSTree() : root(nullptr) {};

        bool find(T data)
        { // TO DO
            return this->privateFind(data, this->root);
        }

        bool insert(T data)
        { // TO DO
            return this->privateInsert(data, this->root);
        }

        bool remove(T data)
        { // TO DO
            return this->privateRemove(data, this->root);
        }

        size_t size()
        { // TO DO
            return this->privateSize(this->root);
        }

        size_t height()
        { // TO DO
            return privateFindHeight(this->root);
        }

        void traversePreOrder()
        { // TO DO
            this->privateTraversePreOrder(this->root);
        }

        void traverseInOrder()
        { // TO DO
            this->privateTraverseInOrder(this->root);
        }

        void traversePostOrder()
        { // TO DO
            this->privateTraversePostOrder(this->root);
        }

        Iterator<T> begin()
        { // TO DO
            if (!this->root) { return Iterator<T>(); }
            return Iterator<T>(this->root);
        }

        Iterator<T> end()
        { // TO DO
            return Iterator<T>();
        }

        ~BSTree()
        { // TO DO
            if (!this->root) { return; }
            else { this->root->killSelf(); }
        }
};

#endif
