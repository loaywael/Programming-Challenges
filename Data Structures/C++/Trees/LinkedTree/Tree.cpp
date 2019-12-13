/*
 * treeTraversal.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: ezio
 */


#include <iostream>
#include <queue>
#include "Tree.hpp"

template <class T>
void preOrder(Node<T>* n) {
	if (n == nullptr) {
		return;
	}
	std::cout << n->item << " ";
	preOrder(n->nxtLeft);
	preOrder(n->nxtRight);
}

template <class T>
void inOrder(Node<T>* n) {
	if (n == nullptr) {
		return;
	}
	inOrder(n->nxtLeft);
	std::cout << n->item << " ";
	inOrder(n->nxtRight);
}

template <class T>
void postOrder(Node<T>* n) {
	if (n == nullptr) {
		return;
	}
	postOrder(n->nxtLeft);
	postOrder(n->nxtRight);
	std::cout << n->item << " ";
}

template <class T>
void levelOrder(Node<T>* n) {
	if (n == nullptr) {
		std::cout << "Tree is empty!" << std::endl;
		return;
	}
	std::queue<Node<T>*> Q;
	Q.emplace(n);
	while (!Q.empty()) {	// terminates when all nodes are discovered
		// each time gets updated by the new queue head
		Node<T>* curr = Q.front();
		std::cout << curr->item << " ";
		Q.pop();
		if (curr->nxtLeft != nullptr) {
			Q.emplace(curr->nxtLeft);
		}
		if (curr->nxtRight != nullptr) {
			Q.emplace(curr->nxtRight);
		}

	}
}

template <class T>
int treeHeight(Node<T>* n) {
	int lh, rh;
	if (n == nullptr) {
		return 0;
	}
	lh = treeHeight(n->nxtLeft);
	rh = treeHeight(n->nxtRight);
	if (lh > rh) {
		return lh + 1;
	}
	else {
		return rh + 1;
	}
}

template <class T>
Node<T>* getNode(T item) {
	Node<T>* n = new Node<T>;
	n->item = item;
	n->nxtLeft = n->nxtRight = nullptr;
	return n;
}

template <class T>
Node<T>* binarySearch(T item, Node<T>* root) {
	Node<T>* n = root;
	while (n != nullptr) {
		if (n->item > item) {
			 n = n->nxtLeft;
		}
		else if (n->item < item) {
			 n = n->nxtRight;
		}
		else {
			return n;
		}
	}
	return nullptr;
}

template Node<int>* getNode(int);
template void levelOrder(Node<int>* n);
template void preOrder<int>(Node<int>*);
template void inOrder<int>(Node<int>*);
template void postOrder<int>(Node<int>*);
template int treeHeight<int>(Node<int>*);
template Node<int>* binarySearch(int, Node<int>* root);
