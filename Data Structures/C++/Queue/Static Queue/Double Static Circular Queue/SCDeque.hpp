#pragma once
#include <iostream>

namespace SCDeque{
    template <class T>
    class Queue{

        private:
            int head, tail, length;
            const int MAX_SIZE;
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

