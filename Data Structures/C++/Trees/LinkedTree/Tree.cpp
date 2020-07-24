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


template <class T>
Node<T>* getMax(Node<T>* root) {
	if (root == nullptr) {
			return nullptr;
	}
	Node<T>* n = root;
	while (n->nxtRight != nullptr) {
		 n = n->nxtRight;
		}
	return n;
}

//template <class T>
//Node<T>* getMax(Node<T>* root) {
//	if (root == nullptr) {
//		return nullptr;
//	}
//	if (root->nxtRight == nullptr) {
//			return root;
//	}
//	return getMax(root->nxtRight);
//}

template <class T>
Node<T>* getMin(Node<T>* root) {
	if (root == nullptr) {
				return nullptr;
		}
	Node<T>* n = root;
	while (n->nxtLeft != nullptr) {
		 n = n->nxtLeft;
		}
	return n;
}

//template <class T>
//Node<T>* getMin(Node<T>* root) {
//	if (root == nullptr) {
//		return nullptr;
//	}
//	if (root->nxtLeft == nullptr) {
//			return root;
//	}
//	return getMin(root->nxtLeft);
//}

//template <class T>
//Node<T>* binarySearch(T item, Node<T>* n) {
//	if (n == nullptr) {
//		return nullptr;
//	}
//	if (n->item > item) {
//		return binarySearch(item, n->nxtLeft);
//	}
//	if (n->item < item) {
//		return binarySearch(item, n->nxtRight);
//	}
//	return n;
//}


template <class T>
void insert(T item, Node<T>* root) {
	Node<T>* current = root;
	Node<T>* parrent = current;

	while(current != nullptr) {
		parrent = current;
		if (current->item > item) {
			current = current->nxtLeft;
		}
		else if (current->item < item) {
			current = current->nxtRight;
		}
		else {
			std::cout << "item already exists!\n";
			return;
		}
	}
	Node<T>* n = getNode(item);
	n->item = item;
	if (root == nullptr) {
		root = n;
	}
	else if (parrent->item > item) {
		parrent->nxtLeft = n;
	}
	else {
		parrent->nxtRight = n;
	}
}


template <class T>
Node<T>* insert(T item, Node<T>* root) {
	static Node<T>* parrent = root;
	if (root == nullptr) {
		root = getNode(item);
	}
	else if (root->item > item) {
		root->nxtLeft = insert(item, root->nxtLeft);
	}
	else if (root->item < item) {
		root->nxtRight = insert(item, root->nxtRight);
	}
	else {
		std::cout << "item already exists!\n";
	}
	return root;
}



/*Resolving the compiler linking for template methods*/
template Node<int>* getNode(int);
template void levelOrder(Node<int>* n);
template void preOrder<int>(Node<int>*);
template void inOrder<int>(Node<int>*);
template void postOrder<int>(Node<int>*);
template int treeHeight<int>(Node<int>*);
template Node<int>* binarySearch(int, Node<int>* root);
template Node<int>* getMax(Node<int>* root);
template Node<int>* getMin(Node<int>* root);
template void insert(int item, Node<int>* root);
template Node<int>* insert(int item, Node<int>* root);

