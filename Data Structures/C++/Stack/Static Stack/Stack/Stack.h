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
        T pop(void);
        bool isEmpty(void);
        bool isFull(void);
        T getTop(void);
        int getSize(void);
        void display(void);
};

#endif
