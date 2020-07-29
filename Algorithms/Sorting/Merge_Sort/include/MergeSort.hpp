#pragma once
#include <iostream>
#include <vector>
#include <memory>


template <class T>
class MergeSort {

private:
    static std::vector<T> merge(std::vector<T>& left, std::vector<T>& right);
    static int getMidPoint(std::vector<T> const& arr);
public:
    static std::vector<T> sort(std::vector<T>& arr);
};


template <typename T>
void printArray(std::string const& name, std::vector<T> const &arr) {
    std::cout << name << "\t";
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
