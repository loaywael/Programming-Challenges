/*
 * recursion.cpp
 *
 *  Created on: Nov 27, 2019
 *      Author: ezio
 */

int sum(int n);

#include <iostream>

int main(int argc, char** argv) {
	sum(5);
	return 0;
}

int sum(int n){
	if (n == 0){
		return 0;
	}
	n = n + sum(n - 1);
	std::cout << "sum: " << n << std::endl;
	return n;

}
