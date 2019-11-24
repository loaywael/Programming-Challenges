/*
 * LinkedList.cpp
 *
 *  Created on: Nov 24, 2019
 *      Author: ezio
 */

#include "LinkedList.hpp"
#include <iostream>

template<class T>
inline LinkedList::List<T>::List() {
	head = tail = temp = nullptr;
	length = 0;
}

template<class T>
inline LinkedList::List<T>::~List() {
	clean();
	std::cout << "memory cleaned!\n";
}

template<class T>
inline void LinkedList::List<T>::insert(T item, int index) {
	Node* node = new Node;
	if (!node){
		std::cerr << "can't allocate memory for that item!\n";
	}
	else if (!_isInRange(index)) {
		std::cerr << "index out of range!\n";
	}
	else{
		node->info = item;
		node->next = nullptr;
		if (_isEmpty() || index == 0) {
			node->next = head;
			head = node;
			length++;
		}

		else{
			int i = 1;
			for (Node* ptr = head; ptr!=nullptr; ptr= ptr->next) {
				if (i == index) {
					node->next = ptr->next;
					ptr->next = node;
					length++;
					break;
				}
				i++;
			}
		}
	}
}

template<class T>
inline void LinkedList::List<T>::insert(T item) {
	Node* node = new Node;
	if (!node){
		std::cerr << "can't allocate memory for that item!\n";
	}
	else{
		node->info = item;
		node->next = nullptr;
		if (_isEmpty()) {
			head = node;
			length++;
		}
		else{
			int i = 0;
			for (Node* ptr = head; ptr!=nullptr; ptr= ptr->next) {
				if (ptr->next == nullptr) {
					ptr->next = node;
					length++;
					break;
				}
				i++;
			}
		}
	}
}

template<class T>
inline void LinkedList::List<T>::update(int index, T value) {
}

template<class T>
inline void LinkedList::List<T>::pop(int index) {
}

template<class T>
inline void LinkedList::List<T>::display() {
	std::cout << "[";
	for (Node* ptr = head; ptr!=nullptr; ptr= ptr->next) {
		std::cout << ptr->info << " ";
	}
	std::cout << "]" << std::endl;
}

template<class T>
inline bool LinkedList::List<T>::_isEmpty() {
	return length == 0;
}

template<class T>
inline void LinkedList::List<T>::clean() {
}

template<class T>
inline int LinkedList::List<T>::size() {
	return length;
}

template<class T>
inline int LinkedList::List<T>::find(T item) {
	return 0;
}

template<class T>
inline bool LinkedList::List<T>::_isInRange(int idx) {
	return idx >= 0 && idx <= length;
}

template<class T>
inline T LinkedList::List<T>::get(int index) {
	return 0;
}

template class LinkedList::List<int>;
template class LinkedList::List<float>;
template class LinkedList::List<double>;
template class LinkedList::List<char>;
template class LinkedList::List<std::string>;

