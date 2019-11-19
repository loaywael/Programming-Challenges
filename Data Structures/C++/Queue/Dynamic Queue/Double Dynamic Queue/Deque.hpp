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

