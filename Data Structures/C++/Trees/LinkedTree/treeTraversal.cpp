/*
 * treeTraversal.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: ezio
 */


#include <iostream>

template <class T>
struct Node {
	Node* nxtLeft;
	T item;
	Node* nxtRight;
};

void preOrder(Node<int>* n) {
	if (n == nullptr) {
		return;
	}
	std::cout << n->item << std::endl;
	preOrder(n->nxtLeft);
	preOrder(n->nxtRight);
}

void inOrder(Node<int>* n) {
	if (n == nullptr) {
		return;
	}
	inOrder(n->nxtLeft);
	std::cout << n->item << std::endl;
	inOrder(n->nxtRight);
}

void postOrder(Node<int>* n) {
	if (n == nullptr) {
		return;
	}
	postOrder(n->nxtLeft);
	postOrder(n->nxtRight);
	std::cout << n->item << std::endl;
}
