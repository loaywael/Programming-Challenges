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
                Node* last;
            };

            // Node* head;
            Node* head;
            Node* tail;
            Node* temp;
            int length;

        public:
            Queue();
            ~Queue();
            void insertHead(T item);
            void insertTail(T item);
            void display();
            void clean();
            int getSize();
            bool isEmpty();
            T popHead();
            T popTail();
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
    this->clean();
    std::cout << "Queue memory cleaned!: ";
    this->display();    
}

template <class T>
void DQueue::Queue<T>::insertTail(T item){
    Node* node = new Node;

    if (!node){
        std::cerr << "memory not available!\n";
    }

    else{
        if (isEmpty()){
        // special case when it is empty
            head = node;
            tail = head;
            node->next = nullptr;
            node->info = item;
            node->last = nullptr;
            length++;
        }
        
        else{
            tail->next = node;
            node->info = item;
            node->last = tail;
            node->next = nullptr;
            tail = node;
            length++;
        }
    }
}

template <class T>
void DQueue::Queue<T>::insertHead(T item){
    
    Node* node = new Node;
    if (!node){
        std::cerr << "memory not available!\n";
    }

    else{
        if (isEmpty()){
        // special case when it is empty
            head = node;
            tail = head;
            node->next = nullptr;
            node->info = item;
            node->last = nullptr;
            length++;
        }
        
        else{
            head->last = node;
            node->info = item;
            node->next = head;
            node->last = nullptr;
            head = node;
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
T DQueue::Queue<T>::popHead(){
    T item;

    if (isEmpty()){
        throw "Queue is empty!\n\n";
    }

    else{
        temp = head;  // save the feed backward link
        item = head->info;
        // move the tail to point to the following node after the first node
        head = head->next;
        head->last = nullptr;
        delete temp;   // delete the first node
        temp = nullptr; // prevent dangling pointer
        length--;
    }
    return item;
}

template <class T>
T DQueue::Queue<T>::popTail(){
    T item;

    if (isEmpty()){
        throw "Queue is empty!\n\n";
    }

    else{
        temp = tail;  // save the feed backward link
        item = tail->info;
        // move the tail to point to the following node after the first node
        tail = tail->last;
        tail->next = nullptr;
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
    if (!isEmpty()){
        while (head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }  
    }
    
    length = 0;
    temp = nullptr;
    tail = nullptr;
}
