#pragma once
#include <iostream>
#include <boost/optional.hpp>

namespace DStack{
    template <class T>
    class Stack{

        private:
            struct Node{
                T info;
                Node* next;
            };

            Node* top;
            Node* temp;

        public:
            Stack();
            ~Stack();
            T getTop(void);
            void push(T item);
            T pop(void);
            void display(void);
            bool isEmpty(void);
            void clear(void);
            int getSize(void);
    };
}


template <class T>
DStack::Stack<T>::Stack(){
    
    top = nullptr;
    temp = top;
}

template <class T>
DStack::Stack<T>::~Stack(){
    clear();
}

template <class T>
void DStack::Stack<T>::clear(){

}

template <class T>
void DStack::Stack<T>::push(T item){
    Node* newNode = new Node;
    if (!newNode){
        std::cerr << "can't create new node!" << std::endl;
    }

    else{
        newNode->next = top;
        top = newNode;   
        top->info = item; 
    } 
}

template <class T>
T DStack::Stack<T>::pop(){
    T item;
    if(isEmpty()){
        std::cerr << "stack is empty!" << std::endl;
    }

    else{
        temp = top;
        top = temp->next;
        item = temp->info;
        delete temp;   
    }
    return item;
}

template <class T>
bool DStack::Stack<T>::isEmpty(){
    return top == nullptr ? 1 : 0;
}

template <class T>
void DStack::Stack<T>::display(){
    if(!isEmpty()){
        std::cout << "[";
        for(Node* ptr = top; ptr != nullptr; ptr = ptr->next){
            std::cout << ptr->info << " ";
        }
        std::cout << "]" << std::endl;
    }
}


template <class T>
T DStack::Stack<T>::getTop(void){
    if(isEmpty()){
        T state;
        std::cout << "[None]" << std::endl;
        return state;
    }
    return top->info;
}

template <class T>
int DStack::Stack<T>::getSize(void){
    int size = 0;
    for(Node* ptr = top; ptr != nullptr; ptr = ptr->next){
        size++;
    }
    return size;
}