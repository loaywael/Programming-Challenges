/*
* LinkedList.hpp
*
* Created on: Nov 23, 2019
*
* Author: ezio
*/

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>

namespace LinkedList {
template<class T>
class List {
private:
	struct Node {
		T info;
		Node *next;
	};
	int length;
	Node* head;
public:
	List();
	~List();
	void insert(T item, int index);
	void insert(T item);
	void update(int index, T value);
	void remove(T item);
	void removeIndex(int index);
	void display();
	void reverse();
	bool _isEmpty();
	bool _isInRange(int idx);
	void clean();
	int size();
	int find(T item);
	T get(int index);

};

} /* namespace LinkedList */


#endif /* LINKEDLIST_HPP_ */
