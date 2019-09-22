#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <stack>
#include <queue>
template <typename T> 
class  BSTree {
    Node<T> *root;

    size_t size(Node<T>* traverseNode)
    {
        if (!traverseNode) { return 0; }
        return (this->size(traverseNode->left) + 1 + this->size(traverseNode->right) );
    }

    void traversePreOrder(Node<T>* traverse)
    {
        if (!traverse) return;

        cout << traverse->data << " ";
        traversePreOrder(traverse->left);
        traversePreOrder(traverse->right);
    }

    void traverseInOrder(Node<T>* traverse)
    {
        if (!traverse) return;
        traverseInOrder(traverse->left);
        cout << traverse->data << " ";
        traverseInOrder(traverse->right);
    }

    void traversePostOrder(Node<T>* traverse)
    {
        if (!traverse) return;

        traversePostOrder(traverse->left);
        traversePostOrder(traverse->right);
        cout << traverse->data << " ";
    }

    int findHeight(Node<T>* current){
        if (!current) { return 0; }
        int left = findHeight(current->left);
        int right = findHeight(current->right);
        return std::max( left, right ) + 1;
    }

    public:
        BSTree() : root(nullptr) {};
//        T getRoot(){ return this->root->data; }
        bool find(T data) { // TO DO
            auto current = this->root;

            while (current != nullptr)
            {
                if (data == current->data) { return true; }
                else if (data < current->data) { current = current->left; }
                else { current = current->right; }
            }

            return false;
        }

        bool insert(T data) { // TO DO
            auto newNode = new Node<T>{data};
//            if (find(data)) { return false; }

            if (!this->root) {
                this->root = newNode;
            } else {
                auto current = this->root, prev = this->root;
                while (current != nullptr)
                {
                    prev = current;
                    if (data <= current->data) { current = current->left; }
                    else { current = current->right; }
                }
                if (data <= prev->data) { prev->left = newNode; }
                else { prev->right = newNode; }
            }

            return true;
        }

        bool remove(T data) { // TO DO
            
            if ( !find(data) ) { return false; }

            else {
                // SEARCHING DELETE NODE
                auto subTreeRoot = this->root;
                auto prevSubTreeRoot = this->root;
                while (prevSubTreeRoot->right != subTreeRoot || prevSubTreeRoot->left != subTreeRoot) {
                    if (data == subTreeRoot->data) { break; }
                    else if (data < subTreeRoot->data) {
                        prevSubTreeRoot = subTreeRoot;
                        subTreeRoot = subTreeRoot->left;
                    }
                    else {
                        prevSubTreeRoot = subTreeRoot;
                        subTreeRoot = subTreeRoot->right;
                    }
                }

                // Case 2 : Two child GOOD
                if ((subTreeRoot->left != nullptr) && (subTreeRoot->right != nullptr)) {
                    auto subTreeLeftRightmost = subTreeRoot;
                    Node<T> *prevSubTreeLeftRightmost= subTreeRoot;

                    subTreeLeftRightmost = subTreeLeftRightmost->left;

                    if (!subTreeLeftRightmost->right) {
                        std::swap(subTreeLeftRightmost->data, subTreeRoot->data);
                        subTreeRoot->left = subTreeLeftRightmost->left;
                        subTreeLeftRightmost->left = nullptr;
                        delete subTreeLeftRightmost;

                        return true;
                    }
                    else {
                        while (subTreeLeftRightmost->right != nullptr) {
                            prevSubTreeLeftRightmost = subTreeLeftRightmost;
                            subTreeLeftRightmost = subTreeLeftRightmost->right;
                        }

                        std::swap(subTreeLeftRightmost->data, subTreeRoot->data);

                        prevSubTreeLeftRightmost->right = subTreeLeftRightmost->left;
                        subTreeLeftRightmost->left = nullptr;
                        subTreeLeftRightmost->right = nullptr;
                        delete subTreeLeftRightmost;

                        return true;
                    }
                }
                // Case 2 : One child
                // GOOD
                else if (!subTreeRoot->left) {
                    if (prevSubTreeRoot->right) { prevSubTreeRoot->right = subTreeRoot->right; }
                    else { prevSubTreeRoot->left = subTreeRoot->right; }
                    subTreeRoot->left = nullptr;
                    subTreeRoot->right = nullptr;
                    delete subTreeRoot;

                    return true;
                }
                //GOOD
                else if (!subTreeRoot->right) {
                    auto leftRightmost = subTreeRoot;
                    Node<T> *prevLeftRightmost= subTreeRoot;

                    leftRightmost = leftRightmost->left;

                    if (!leftRightmost->right) {
                        prevSubTreeRoot->left = subTreeRoot->left;
                        subTreeRoot->left = nullptr;
                        delete subTreeRoot;

                        return true;
                    }
                    else {
                        while (leftRightmost->right != nullptr) {
                            prevLeftRightmost = leftRightmost;
                            leftRightmost = leftRightmost->right;
                        }

                        std::swap(leftRightmost->data, subTreeRoot->data);

                        prevLeftRightmost->right = leftRightmost->right;
                        leftRightmost->left = nullptr;
                        leftRightmost->right = nullptr;
                        delete leftRightmost;

                        return true;
                    }
                }
                // Case 0 : No child GOOD
                else {
                    if (prevSubTreeRoot->right) { prevSubTreeRoot->right = subTreeRoot->right; }
                    else { prevSubTreeRoot->left = subTreeRoot->left; }
                    subTreeRoot->left = nullptr;
                    subTreeRoot->right = nullptr;
                    delete subTreeRoot;

                    return true;
                }
            }
        }

        size_t size() { // TO DO
            return this->size(this->root);
        }

        size_t height() { // TO DO
            return findHeight(this->root);
        }

        void traversePreOrder() { // TO DO
            this->traversePreOrder(this->root);
        }

        void traverseInOrder() { // TO DO
            this->traverseInOrder(this->root);
        }

        void traversePostOrder() { // TO DO
            this->traversePostOrder(this->root);
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







//bool remove (T data, Node <T>** current)
//{
//    Node<T>** temp = current;
//    // Two children
//    if ((*temp)->right && (*temp)->left) {
//        // IF root
//        auto temp2 = *temp;
//        auto prev = *temp;
//        auto cur = temp2;
//        if (this->root->data == temp2->data){
//            temp2 = temp2->left;
//            while (temp2->right != nullptr)
//            {
//                prev = temp2;
//                temp2 = temp2->right;
//            }
//            std::swap(temp2->data, cur->data);
//            prev->right = temp2->right;
//            delete temp2;
//            return true;
//        }
//        // if no root
//        (*temp)->data = this->findMax(data, (*temp)->left);
//
//        return this->remove((*temp)->data, &((*temp)->left));
//    }
////             One children
//    else if ( (*temp)->right || (*temp)->left ) {
//        Node<T>* swapper;
//        if ((*temp)->left) {
//            swapper = (*temp)->left;
//        } else {
//            swapper = (*temp)->right;
//        }
//        delete *temp;
//        *temp = swapper;
//
//        return true;
//    }
//        // Zero children (Leaf)
//    else{
//        delete *temp;
//        *temp = nullptr;
//
//        return true;
//    }
//}