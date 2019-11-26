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
	head = temp = nullptr;
	length = 0;
}

template<class T>
inline LinkedList::List<T>::~List() {
	clean();
	std::cout << "\nmemory cleaned!\n";
}

template<class T>
inline void LinkedList::List<T>::insert(T item, int index) {
	Node* node = new Node;
	if (!node){
		std::cerr << "can't allocate memory for that item!\n";
	}
	else if (!_isInRange(index)) {
		std::cerr << "\nindex out of range!\n";
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
		std::cerr << "\ncan't allocate memory for that item!\n";
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
	if (_isEmpty()) {
		std::cerr << "\nlist is empty!\n";
	}
	else if (!_isInRange(index)){
		std::cerr << "\nindex out of range!\n";
	}
	else {
		int i = 0;
		for (Node* ptr = head; ptr!=nullptr; ptr = ptr->next) {
			if (index == i) {
				ptr->info = value;
				break;
			}
			i++;
		}
	}
}

template<class T>
inline void LinkedList::List<T>::pop(int index) {
	if (_isEmpty()) {
		std::cerr << "\nlist is empty!\n";
	}
	else if (!_isInRange(index)){
		std::cerr << "\nindex out of range!\n";
	}
	else if (index == 0) {
		temp = head;
		head = head->next;
		delete temp;
		length--;
	}
	else {
		int i = 1;
		for (Node* ptr = head; ptr!=nullptr; ptr = ptr->next) {
			if (index == i) {
				temp = ptr->next;
				ptr->next = ptr->next->next;
				delete temp;
				length--;
				break;
			}
			i++;
		}
	}
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
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
	temp = head = nullptr;
	length = 0;
}

template<class T>
inline int LinkedList::List<T>::size() {
	return length;
}

template<class T>
inline int LinkedList::List<T>::find(T item) {
	std::string msg;
	if (_isEmpty()) {
		msg = "\nlist is empty!\n";
	}
	else {
		int i = 0;
		for (Node* ptr = head; ptr!=nullptr; ptr = ptr->next) {
			if (ptr->info == item) {
				return i;
				break;
			}
			i++;
		}
		msg = "\nitem isn't found!\n";
	}
	throw msg;
}

template<class T>
inline bool LinkedList::List<T>::_isInRange(int idx) {
	return idx >= 0 && idx < length;
}

template<class T>
inline T LinkedList::List<T>::get(int index) {
	std::string msg;
	if (_isEmpty()) {
		msg = "\nlist is empty!\n";
	}
	else if (!_isInRange(index)){
		msg = "\nindex out of range!\n";
	}
	else {
		int i = 0;
		for (Node* ptr = head; ptr!=nullptr; ptr = ptr->next) {
			if (index == i) {
				return ptr->info;
				break;
			}
			i++;
		}
	}
	throw(msg);
}

template class LinkedList::List<int>;
template class LinkedList::List<float>;
template class LinkedList::List<double>;
template class LinkedList::List<char>;
template class LinkedList::List<std::string>;

