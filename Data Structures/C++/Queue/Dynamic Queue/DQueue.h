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

            Node* head;
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
    head = nullptr;
    tail = nullptr;
    temp = nullptr;
    length = 0;
}

template <class T>
DQueue::Queue<T>::~Queue(){
    std::cout << "memory cleaned!" << std::endl;
    this->clean();
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
            head = node;
            head->next = nullptr;
            tail = head;
            node->info = item;
            length++;
        }
        
        else{
            tail->next = node; // previouse node linked to the newest
            tail = node;    // update tail address of the newest node
            node->info = item;
            node->next = nullptr;   // make it the last node in queue
            length++;
        } 
    }
}

template <class T>
void DQueue::Queue<T>::display(){
    if (!isEmpty()){
        std::cout << "[";
        for (Node* ptr = head; ptr != nullptr; ptr = ptr->next){
            std::cout << ptr->info << " ";
        }
        std::cout << "]" << std::endl;
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
        item = head->info;
        temp = head;
        head = head->next;
        delete temp;
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
        return head->info;
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
    while (head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }  
    length = 0;
    temp = nullptr;
    head = nullptr;
    tail = nullptr;
}
