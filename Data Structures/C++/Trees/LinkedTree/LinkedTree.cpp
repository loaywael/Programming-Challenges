#include <iostream>
#include "Tree.hpp"

int main(int argc, char **argv) {

	/*Tree Definition*/
	Node<int>* root = getNode<int>(1);
	root->nxtLeft = getNode<int>(2);
	root->nxtRight = getNode<int>(3);
	root->nxtLeft->nxtLeft = getNode<int>(4);
	root->nxtLeft->nxtRight = getNode<int>(5);
	root->nxtRight->nxtLeft = getNode<int>(6);
	root->nxtRight->nxtRight = getNode<int>(7);

	/*Display Methods*/
	std::cout << "prefix-mode: ";
	preOrder<int>(root);
	std::cout<< std::endl;

	std::cout << "inorder-mode: ";
	inOrder<int>(root);
	std::cout<< std::endl;

	std::cout << "postfix-mode: ";
	postOrder<int>(root);
	std::cout<< std::endl;

	std::cout << "level-order-mode: ";
	levelOrder<int>(root);
	std::cout<< std::endl;

	std::cout << "tree-height: " << treeHeight<int>(root);
	std::cout<< std::endl;

	return 0;
}
