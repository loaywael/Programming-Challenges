#include <iostream>
#include <vector>
#include <assert.h>
#include "../include/LinearSearch.hpp"


int main(int argc, char** argv) {
    std::vector<int> Vi(100);
    for (int i{0}; i < Vi.size(); i++) {
        Vi[i] = i;
    }
    for (auto val : Vi) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    int key = 21;
    int id = LinearSearch<int>(Vi, key);
    std::cout << "found key: " << key << " at index: " << id << std::endl; 
    return 0;
}