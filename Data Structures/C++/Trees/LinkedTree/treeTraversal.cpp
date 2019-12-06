/*
 * treeTraversal.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: ezio
 */


#include <iostream>
#include <queue>


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

void levelOrder(Node<int>* n) {
	if (n == nullptr) {
		std::cout << "Tree is empty!" << std::endl;
		return;
	}
	std::queue<Node<int>*> Q;
	Q.emplace(n);
	while (!Q.empty()) {	// terminates when all nodes are discovered
		// each time gets updated by the new queue head
		Node<int>* curr = Q.front();
		std::cout << curr->item << " ";
		int item = Q.pop();
		if (curr->nxtLeft != nullptr) {
			Q.emplace(curr->nxtLeft);
		}
		if (curr->nxtRight != nullptr) {
			Q.emplace(curr->nxtRight);
		}

	}
}

int treeHeight(Node<int>* n) {
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
