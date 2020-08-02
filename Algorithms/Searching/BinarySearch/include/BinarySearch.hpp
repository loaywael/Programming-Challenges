#pragma once 
#include <iostream>
#include <vector>
#include <chrono>


template <typename T>
int BinarySearch(std::vector<T> const& arr, T key) {
    auto t1 = std::chrono::high_resolution_clock::now();
    int arrSize = arr.size();
    int start{0}, end{arrSize-1};
    int midId, i{1};
    while (start <= end) {
        midId = (start + end) / 2;
        if (arr[midId] == key) {
            auto t2 = (std::chrono::high_resolution_clock::now());
            auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
            std::cout << "Took (" << i << ") steps" << "\t"
                      << "runtime: (" << runtime.count() << ")ns" << std::endl;
            return midId;
        }
        else if (arr[midId] < key) {
            start = midId + 1;
        }
        else if (arr[midId] > key) {
            end = midId - 1;
        }
        i++;
    }
    return -1;
}