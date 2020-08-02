#pragma once
#include <iostream>
#include <vector>
#include <chrono>


template <typename T>
int LinearSearch(std::vector<T> const& arr, T key) {
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i{0}; i < arr.size(); i++) {
        if (arr[i] == key) {
            auto t2 = (std::chrono::high_resolution_clock::now());
            auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
            std::cout << "Took (" << i << ") steps" << "\t"
                      << "runtime: (" << runtime.count() << ")ns" << std::endl;
            return i;
        }
    }
    return -1;
}