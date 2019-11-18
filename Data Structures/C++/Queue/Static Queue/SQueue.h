#pragma once
#include <iostream>

namespace SQueue{
    template <class T>
    class Queue{
        private:
            T* buffer;
            int head, tail, cnt;
            const int MAX_SIZE;
        public:
            Queue(const int& maxSize);
            ~Queue();
            void insert(T item);
            void display();
            bool isFull();
            bool isEmpty();
            int getSize();
            T getHead();
            T getTail();
            T pop();
    };
}


template <class T>
SQueue::Queue<T>::Queue(const int& maxSize):MAX_SIZE(maxSize){
    cnt = 0;
    head = 0;
    tail = MAX_SIZE - 1;
    buffer = new T [MAX_SIZE];
}

template <class T>
SQueue::Queue<T>::~Queue(){
    delete[] buffer;
}

template <class T>
void SQueue::Queue<T>::insert(T item){
    if (isEmpty()){
        buffer[head] = item;
    }

    if (isFull()){
        std::cerr << "Queue is Full can't insert anymore!\n\n";
    }
    else{
        tail= (tail + 1) % MAX_SIZE;
        buffer[tail] = item; 
        cnt++;
    }
    
}

template <class T>
void SQueue::Queue<T>::display(){
    std::cout << "[";
    if (!isEmpty()){
        for (int i = head; i <= tail; i++){
            std::cout << buffer[i] << " ";
        }
    }
    std::cout << "]" << std::endl;
    
}

template <class T>
bool SQueue::Queue<T>::isFull(){
    return cnt == MAX_SIZE;
}

template <class T>
bool SQueue::Queue<T>::isEmpty(){
    return getSize() == 0;
}

template <class T>
int SQueue::Queue<T>::getSize(){
    return cnt;
}

template <class T>
T SQueue::Queue<T>::getHead(){
   return head; 
}

template <class T>
T SQueue::Queue<T>::getTail(){
  return tail;   
}

template <class T>
T SQueue::Queue<T>::pop(){
    T item;
    if (isEmpty()){
        std::cerr << "Queue is empty can't pop anymore!\n\n";
    }
    else{
        item = buffer[head];
        head = (head + 1) % MAX_SIZE; 
        cnt--;
    }
    
    return item;
}