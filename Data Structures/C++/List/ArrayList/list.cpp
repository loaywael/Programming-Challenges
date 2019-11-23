#include "list.hpp"


template <class T> 
linkedList::List<T>::List(){
    _length = 0;
    _maxSize = MIN_SIZE;
    list = new T [_maxSize];
}

template <class T> 
linkedList::List<T>::List(int maxSize){
    _length = 0;
    _maxSize =  maxSize > 0 ? maxSize : MIN_SIZE;
    list = new T [_maxSize];
}

template <class T> 
linkedList::List<T>::~List(){
    delete[] list;
    _length = 0;
}

template <class T> 
void linkedList::List<T>::insert(T item){
    if (!_isFull()){
        
        list[_length] = item;
        _length++;
    }

    else{
        std::cerr << "list is full!\n";
    }
}

template <class T> 
void linkedList::List<T>::insert(T item, int index){
    if (!_isFull()){
        if (_isInRange(index)){
            for (int i = _maxSize; i > index; i--){
                list[i] = list[i-1];
            }
        }
        else{
            std::cerr << "index out of range!\n";
        }
        list[index] = item;
        _length++;
    }

    else{
        std::cerr << "list is full!\n";
    }
}

template <class T> 
void linkedList::List<T>::update(int index, T value){
    if (_isInRange(index)){
        list[index] = value;
    }
    else{
        std::cerr << "index out of range!\n";
    }
}

template <class T> 
T linkedList::List<T>::get(int index){
    if (_isInRange(index)){
        return list[index];
    }
    throw "index out of range!\n";
}

template <class T> 
int linkedList::List<T>::find(T item){
    if (!_isEmpty()){
        for (int i = 0; i < _maxSize; i++){
            if (list[i] == item){
                return i;
            }
            else{
                std::cerr << "item not found!\n";
            }
        }
    }
    else{
        std::cerr << "list is empty!\n";
    }
    return -1;
}
       
template <class T>  // got problem of deleting last element value not replaced
void linkedList::List<T>::pop(int index){   // but size counter is decreased
    if (!_isEmpty()){   // and last value copied to the value of the index before
        if (_isInRange(index)){
            for (int i = index; i < _maxSize; i++){
                list[i] = list[i+1];
            }
            _length--;
        }
        else{
            std::cerr << "index out of range!\n";
        }
    }
    else{
        std::cerr << "list is empty!\n";
    }
}

template <class T> 
void linkedList::List<T>::display(){
    std::cout << "[";
    for (int i = 0; i < _maxSize; i++){
        std::cout << list[i] << " ";
    }
    std::cout << "]\n";
}

template <class T> 
bool linkedList::List<T>::_isEmpty(){
    return _length == 0;
}

template <class T> 
bool linkedList::List<T>::_isFull(){
    return _length == _maxSize;
}

template <class T> 
int linkedList::List<T>::size(){
    return _length;
}

template <class T> 
bool linkedList::List<T>::_isInRange(int index){
    return index > 0 && index < _maxSize;
}

template class linkedList::List<int>;
template class linkedList::List<float>;
template class linkedList::List<double>;
template class linkedList::List<char>;
template class linkedList::List<std::string>;
