#include <iostream>
#include <vector>


template <typename T>
void BubbleSort(std::vector<T>& arr) {
    int maxDepth = arr.size() - 1;
    bool isSorted = true;
    T temp;
    for (int i{0}; i < maxDepth; i++) {
        for (int j{0}; j < maxDepth - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = false;
            }
        }
        if (isSorted) {
            std::cout << "src array is already sorted" << std::endl;
            break;
        }
    }
}


template <typename T>
void printArray(std::string const& name, std::vector<T> const& arr) {
    std::cout << name << "\t";
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}