#pragma once
#include <iostream>

namespace DQueue{
    template <class T>
    class Queue{

        private:
            const int MAX_SIZE;
            int head, tail, length;
            T* buffer;
 
        public:
            Queue(const int& maxSize);
            ~Queue();
            void insertHead(T item);
            void insertTail(T item);
            void display();
            void clean();
            int getSize();
            bool isEmpty();
            bool isFull();
            T popHead();
            T popTail();
            T getHead();
            T getTail();
    };
}

template <class T>
DQueue::Queue<T>::Queue(const int& maxSize): MAX_SIZE(maxSize){
    head = 0;
    tail = MAX_SIZE - 1;
    length = 0;
    buffer = new T [MAX_SIZE];
}

template <class T>
DQueue::Queue<T>::~Queue(){
    delete[] buffer;
    buffer = nullptr;
    std::cout << "Queue memory cleaned!: ";
    this->display();    
}

template <class T>
void DQueue::Queue<T>::insertTail(T item){

    if (isFull()){
    // special case when it is empty
        std::cerr << "Queue is full! can't insert anymore!\n\n"; 
    }
    
    else{
       tail = (tail + 1) % MAX_SIZE;
        buffer[tail] = item;
        length++;
    }
} 


template <class T>
void DQueue::Queue<T>::insertHead(T item){
        if (isFull()){
    // special case when it is empty
        std::cerr << "Queue is full! can't insert anymore!\n\n"; 
    }
    
    else{
       head = (head + 1) % MAX_SIZE;
        buffer[head] = item;
        length++;
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
bool DQueue::Queue<T>::isFull(){
    return length == MAX_SIZE;
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
        tail = tail->next;
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
