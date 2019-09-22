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
    stack<Node<T>*> descendingOrder;
    stack<Node<T>*> ascendingOrder;
    deque<Node<T>*> inOrder;
    public:
    Iterator() { this->current = nullptr; }

    void nextInOrder(Node<T> *node){
        // LIKE traverseInOrder, same idea.
        if (!node) return;
        nextInOrder(node->left);
        descendingOrder.push(node);
        nextInOrder(node->right);
    }


    explicit Iterator(Node<T> *node) {
        nextInOrder(node);
        // Using another stack to set the initial position of begin() iterator
        while ( !descendingOrder.empty() )
        {
            ascendingOrder.push(descendingOrder.top() );
            descendingOrder.pop();
        }
        descendingOrder.push(ascendingOrder.top() );
        ascendingOrder.pop();

        this->current = descendingOrder.top(); //setting the initial position of begin() iterator
    }

    Iterator<T>& operator=(const Iterator<T> &other) {
        this->current = other->current;
        return (*this);
    }

    bool operator!=(Iterator<T> other) {
        return this->current != other.current;
    }

    Iterator<T> operator++() {
        if ( ascendingOrder.empty() )
        {
            this->current = nullptr;
            return (*this);
        }

        descendingOrder.push(ascendingOrder.top() );
        ascendingOrder.pop();
        this->current = descendingOrder.top();

        return (*this);
    }

    Iterator<T> operator--() {
        if(descendingOrder.empty())
        {
            this->current = nullptr;
            return (*this);
        }
        ascendingOrder.push(descendingOrder.top());
        descendingOrder.pop();
        this->current = ascendingOrder.top();
        return (*this);
    }

    T operator*() {
        if(!this->current) throw out_of_range("Empty list!");
        return this->current->data;
    }
};

#endif
