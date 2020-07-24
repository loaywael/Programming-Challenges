#pragma once
#include <iostream>
#include <vector>


template <typename T>
void SelectionSort(std::vector<T>& arr) {
    /* 
    Applies Selection sort over giver destination array
    @param arr: (std::vector) source array
    */

    T temp{0};
    int minId = 0;
    int arrSize = arr.size();
    for (int i{0}; i < arrSize; i++) {
        minId = i;
        for (int j{i}; j < arrSize; j++) {
            if (arr[j] < arr[minId]) {
                minId = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minId];
        arr[minId] = temp;
    }
}


template <typename T>
inline void printArray(T const& arr) {
    for (auto val : arr) {
        std::cout << val << "\t";
    }
    std::cout << std::endl;
}