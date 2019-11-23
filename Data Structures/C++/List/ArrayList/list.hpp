#pragma once
#include <iostream>

namespace linkedList{
    template <class T>
    class List{
        private:
            int _length;
            const int MIN_SIZE = 10;
            int _maxSize;
            T* list;

        public:
            List();
            explicit List(int maxSize); 
            ~List();
            int size();
            bool _isFull();
            bool _isEmpty();
            bool _isInRange(int index);
            void insert(T item);
            void insert(T item, int index);
            void update(int index, T value);
            T get(int index);
            int find(T item);
            void pop(int item);
            void display();
    };
}