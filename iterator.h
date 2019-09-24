#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>
#include <queue>
#include <deque>
template <typename T>
class Iterator {
    private:
    Node<T> *current;

    /* My code begins */
    stack<Node<T>*> descendingOrderStack;
    stack<Node<T>*> ascendingOrderStack;
    /* My code ends */

    public:
    Iterator() { this->current = nullptr; }

    void insertInOrderToStack(Node<T> *node){
        // LIKE privateTraverseInOrder(), same idea.
        if (!node) return;
        insertInOrderToStack(node->left);
        descendingOrderStack.push(node);
        insertInOrderToStack(node->right);
    }


    explicit Iterator(Node<T> *node) {
        insertInOrderToStack(node);
        // Using another stack to set the initial position of begin() iterator
        while ( !descendingOrderStack.empty() )
        {
            ascendingOrderStack.push(descendingOrderStack.top() );
            descendingOrderStack.pop();
        }
        descendingOrderStack.push(ascendingOrderStack.top() );
        ascendingOrderStack.pop();

        this->current = descendingOrderStack.top(); //setting the initial position of begin() iterator
    }

    Iterator<T>& operator=(const Iterator<T> &other) {
        this->current = other->current;
        return (*this);
    }

    bool operator!=(Iterator<T> other) {
        return this->current != other.current;
    }

    Iterator<T> operator++() {
        if ( ascendingOrderStack.empty() )
        {
            this->current = nullptr;
            return (*this);
        }

        descendingOrderStack.push(ascendingOrderStack.top() );
        ascendingOrderStack.pop();
        this->current = descendingOrderStack.top();

        return (*this);
    }

    Iterator<T> operator--() {
        if(descendingOrderStack.empty())
        {
            this->current = nullptr;
            return (*this);
        }
        ascendingOrderStack.push(descendingOrderStack.top());
        descendingOrderStack.pop();
        this->current = ascendingOrderStack.top();
        return (*this);
    }

    T operator*() {
        if(!this->current) throw out_of_range("Empty list!");
        return this->current->data;
    }
};

#endif
