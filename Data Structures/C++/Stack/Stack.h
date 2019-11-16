#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>

template <class T> 
class Stack{
    private:
        int top;
        T* buffer;
    public:
        const int MAX_SIZE;
        Stack(const int& maxSize);
        ~Stack();
        void push(T item);
        void pop();
        bool isEmpty();
        T getTop(void);
        void printStack(void);
};

#endif
