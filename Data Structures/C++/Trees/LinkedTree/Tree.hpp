/*
 * Tree.hpp
 *
 *  Created on: Dec 8, 2019
 *      Author: ezio
 */

#ifndef TREE_HPP_
#define TREE_HPP_

template <class T>
struct Node {
	Node* nxtLeft;
	T item;
	Node* nxtRight;
};

template <class T>
Node<T>* getNode(T item);

template <class T>
int treeHeight(Node<T>* n);

template <class T>
void levelOrder(Node<T>* n);

template <class T>
void postOrder(Node<T>* n);

template <class T>
void inOrder(Node<T>* n);

template <class T>
void preOrder(Node<T>* n);

template <class T>
void buildTree(T item);

template <class T>
void buildTree(T item);

template <class T>
Node<T>* binarySearch(T item, Node<T>* root);

template <class T>
Node<T>* getMax(Node<T>* root);

template <class T>
Node<T>* getMin(Node<T>* root);

template <class T>
void insert(T item, Node<T>* root);

template <class T>
Node<T>* insert(T item, Node<T>* root);

#endif /* TREE_HPP_ */

