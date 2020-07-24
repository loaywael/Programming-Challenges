/*
    - problem with memory deallocation
    - segmentation fault due to cleaning the buffer in the destructor

*/

#include "SCDeque.hpp"

template <class T>
SCDeque::Queue<T>::Queue(const int& maxSize): MAX_SIZE(maxSize){
    this->buffer = new T[MAX_SIZE];
    head = 0;
    tail = MAX_SIZE - 1;
    length = 0;
    
}

template <class T>
SCDeque::Queue<T>::~Queue(){
    this->clean();
    std::cout << "Queue memory cleaned!: ";
    this->display();    
}

template <class T>
void SCDeque::Queue<T>::insertTail(T item){

    if (isFull()){
    // special case when it is empty
        std::cerr << "Queue is full! can't insert anymore!\n\n"; 
    }

    else if (isEmpty()){
        this->buffer[head] = item;
        tail = head;
        length++;
    }

    else{
        tail = (tail + 1) % MAX_SIZE;
        this->buffer[tail] = item;
        length++;
    }
} 


template <class T>
void SCDeque::Queue<T>::insertHead(T item){
    if (isFull()){
    // special case when it is empty
        std::cerr << "Queue is full! can't insert anymore!\n\n"; 
    }
    
    else if (isEmpty()){
        this->buffer[head] = item;
        tail = head;
        length++;
    }

    else{
        head = (head - 1) % MAX_SIZE;
        this->buffer[head] = item;
        length++;
    }
} 

template <class T>
void SCDeque::Queue<T>::display(){
    if (!isEmpty()){
        std::cout << "[";
        for (int i = head; i != tail+1; i = (i + 1) % MAX_SIZE){
            std::cout << this->buffer[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
    
    else{
        std::cout << "[]" << std::endl;
    }
}

template <class T>
int SCDeque::Queue<T>::getSize(){
    return length;
}

template <class T>
bool SCDeque::Queue<T>::isEmpty(){
    return length == 0;
}

template <class T>
bool SCDeque::Queue<T>::isFull(){
    return length == MAX_SIZE;
}

template <class T>
T SCDeque::Queue<T>::popHead(){
    T item;

    if (isEmpty()){
        throw "Queue is empty!\n\n";
    }

    else{
        item = this->buffer[head];
        head = (head + 1) % MAX_SIZE;
        length--;
    }
    return item;
}

template <class T>
T SCDeque::Queue<T>::popTail(){
    T item;

    if (isEmpty()){
        throw "Queue is empty!\n\n";
    }

    else{
        item = this->buffer[tail];
        tail = (tail - 1) % MAX_SIZE;
        length--;
    }
    return item;
}

template <class T>
T SCDeque::Queue<T>::getHead(){

    if (isEmpty()){
        throw "Queue is Empty!"; 
    }
    else{
        return this->buffer[head];
    }
    
}

template <class T>
T SCDeque::Queue<T>::getTail(){

    if (isEmpty()){
        throw "Queue is Empty!"; 
    }
    else{
        return this->buffer[tail];
    }
}

template <class T>
void SCDeque::Queue<T>::clean(){

    if (!isEmpty()){
        delete [] buffer;
        buffer = nullptr;
        length = 0;
    }
}

template class SCDeque::Queue<int>;
template class SCDeque::Queue<float>;
template class SCDeque::Queue<char>;
template class SCDeque::Queue<std::string>;