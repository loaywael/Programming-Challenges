#include <iostream>
#include "../include/SelectionSort.hpp"
#include <vector>


int main(int argc, char** argv) {
    std::vector<int> arr({4, 31, 5, 21, 8, 3, 1, 11});
    printArray(arr);

    SelectionSort<int>(arr);
    printArray(arr);
    return 0;
}