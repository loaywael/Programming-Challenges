#pragma once
#include <iostream>

namespace DQueue{
    template <class T>
    class Queue{

        private:
            struct Node
            {
                T info;
                Node* next;
            };

            // Node* head;
            Node* tail;
            Node* temp;
            int length;

        public:
            Queue();
            ~Queue();
            void insert(T item);
            void display();
            void clean();
            int getSize();
            bool isEmpty();
            T pop();
            T getHead();
            T getTail();
    };
}

template <class T>
DQueue::Queue<T>::Queue(){
    // head = nullptr;
    tail = nullptr;
    temp = nullptr;
    length = 0;
}

template <class T>
DQueue::Queue<T>::~Queue(){
    this->clean();
    std::cout << "Queue memory cleaned!: ";
    this->display();    
}

template <class T>
void DQueue::Queue<T>::insert(T item){
    Node* node = new Node;

    if (!node){
        std::cerr << "memory not available!\n";
    }

    else{
        if (isEmpty()){
        // special case when it is empty
            tail = node;
            tail->next = tail;
            node->info = item;
            length++;
        }
        
        else{
            node->next = tail->next; // save the last tail feed backward in the last added node
            tail->next = node;    // point the last tail node to the newest node
            tail = node;    // update the tail with the newest node
            node->info = item;  // save the value in the new node
            length++;
        } 
    }
}

template <class T>
void DQueue::Queue<T>::display(){
    if (!isEmpty()){
        std::cout << "[";
        for (Node* ptr = tail->next; ptr != tail; ptr = ptr->next){
            std::cout << ptr->info << " ";
        }
        std::cout << tail->info << "]" << std::endl;
    }
    
    else{
        std::cout << "[ ]" << std::endl;
    }
}

template <class T>
int DQueue::Queue<T>::getSize(){
    return length;
}

template <class T>
bool DQueue::Queue<T>::isEmpty(){
    return length == 0;
}

template <class T>
T DQueue::Queue<T>::pop(){
    T item;

    if (isEmpty()){
        throw "Queue is empty!\n\n";
    }

    else{
        temp = tail->next;  // save the feed backward link
        item = temp->info;
        // move the tail to point to the following node after the first node
        tail->next = temp->next;    
        delete temp;   // delete the first node
        temp = nullptr; // prevent dangling pointer
        length--;
    }
    return item;
}

template <class T>
T DQueue::Queue<T>::getHead(){

    if (isEmpty()){
        throw "Queue is Empty!"; 
    }
    else{
        return tail->next->info;
    }
    
}

template <class T>
T DQueue::Queue<T>::getTail(){

    if (isEmpty()){
        throw "Queue is Empty!"; 
    }
    else{
        return tail->info;
    }
}

template <class T>
void DQueue::Queue<T>::clean(){
    if (!isEmpty()){
        while (tail->next != tail){
            temp = tail->next;
            tail->next = temp->next;
            delete temp;
        }  
    }
    
    length = 0;
    temp = nullptr;
    tail = nullptr;
}
