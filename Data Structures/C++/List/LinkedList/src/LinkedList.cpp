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
	head = temp1 = temp2 = nullptr;
	length = 0;
}

template<class T>
inline LinkedList::List<T>::~List() {
	clean();
	std::cout << "\nmemory cleaned!\n";
}

template<class T>
inline void LinkedList::List<T>::insert(T item, int index) {
	Node* node = new Node;	// create the new node
	if (!node){		// make sure it is created
		std::cerr << "can't allocate memory for that item!\n";
	}
	else if (!_isInRange(index)) {	// check for a correct index
		std::cerr << "\nindex out of range!\n";
	}
	else{
		node->info = item; // store the value of the new node
		node->next = nullptr;	// make it initially point to nothing
		if (_isEmpty() || index == 0) {	// in-case of first node, or insertion @index(0)
			node->next = head; 	// let it point to the old-head if exists, null if it's the first
			head = node;	//	let the new added node be the new head
			length++;
		}

		else{
			Node* ptr = head;	// when a new node added to existing node and not the first index
			for (int i = 1; i < index; i++) {
				ptr = ptr->next;
			}
			node->next = ptr->next;
			ptr->next = node;
			length++;
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
			for (Node* ptr = head; ptr != nullptr; ptr= ptr->next) {
				if (ptr->next == nullptr){
					ptr->next = node;
					length++;
					break;
				}
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
		Node* ptr = head;
		for (int i = 1;i < index; i++) {
			ptr = ptr->next;
		}
		ptr->info = value;
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
	else if (index == 0) {	// when deleting the head
		temp1 = head;	// save the pointer to the head to be deleted
		head = head->next;	// move/update the head forward by one
		delete temp1;	// delete the older head
		length--;
	}
	else {
		Node* ptr = head;
		for (int i = 1; i < index; i++) {
			ptr = ptr->next;
		}
		temp1 = ptr->next;	// saving the pointer to the node to be deleted
		// pointing the node before to the node after the node to be deleted
		ptr->next = ptr->next->next;
		delete temp1;	// delete the node requested
		length--;
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
inline void LinkedList::List<T>::reverse() {
	/* strategy of pushing the first item to be the last */
	Node* curr = head;	// let current pointer point to the first node
	// break when current point to the last node
	while (curr->next->next != nullptr) {
		temp1 = curr->next;	// save the next node to the current pointer
		temp2 = curr->next->next;	// save the following node of the next node
		// move the next node of the current to be the first before the head
		curr->next->next =  head;
		// let head point to the saved following node of the next node of the current
		head->next = temp2;
		head = temp1;	// update the head to be the saved next node to the current
	}
	// -------------- special case when current point to last node -------------//
	temp1 = curr->next;	// save the last node
	curr->next->next =  head;	// move the last node to be the first
	head = temp1;	// update the head to be the last node moved to be the first
	curr->next = nullptr;	// make the current node which should be the last node point to null
}

template<class T>
inline bool LinkedList::List<T>::_isEmpty() {
	return length == 0;
}

template<class T>
inline void LinkedList::List<T>::clean() {
	while (head != nullptr) {
		temp1 = head;
		head = head->next;
		delete temp1;
	}
	temp1 = head = nullptr;
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

