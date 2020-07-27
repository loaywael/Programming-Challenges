#include <iostream>
#include <vector>


template <typename T>
void InsertionSort(std::vector<int>& arr) {
    T temp;
    int arrSize = arr.size();
    for (int i{1}; i < arrSize; i++) {
        int j{i};   //  j{i-1};
        temp = arr[i];
        while (j > 0 && temp < arr[j-1]) {     // j >= 0 && arr[j]
            arr[j] = arr[j-1];  // arr[j+1] = arr[j];
            j--;
        }
        arr[j] = temp;  // arr[j+1] = temp;
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