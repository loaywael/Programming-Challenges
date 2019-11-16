#include "Stack.h"

template <class T> 
Stack<T>::Stack(const int& maxSize):MAX_SIZE(maxSize){
    buffer = new T [MAX_SIZE];
    top = -1;
}

template <class T> 
Stack<T>::~Stack(){
    // delete buffer;
    // std::cout << "memory cleaned!\n";
}

template <class T> 
void Stack<T>::push(T item){
    
    if (top != MAX_SIZE-1){
        ++top;
        buffer[top] = item;
    }
    
    else{ 
        std::cerr << "stack maximum size reached ";
        std::cerr << "try poping some values out!\n";    
    }
}

template <class T> 
void Stack<T>::pop(){

    if (isEmpty()){
        std::cerr << "stack is empty\n";
    }
    --top;
}

template <class T> 
bool Stack<T>::isEmpty(){
    return top > -1 ? 0 : 1;
}

template <class T> 
T Stack<T>::getTop(void){
    return buffer[top];
}

template <class T> 
void Stack<T>::printStack(void){    // prints last top to bottom
    std::cout << "[";
    for(int i = top; i > -1; i--){
        std::cout << buffer[i] << " ";
    }
    std::cout << "]" << std::endl;
}