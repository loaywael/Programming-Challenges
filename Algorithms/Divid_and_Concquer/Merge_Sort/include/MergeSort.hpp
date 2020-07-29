#include <iostream>
#include <vector>
#include <memory>


// class MergeSort {

// public:
    // MergeSort();
// template <class T>
// void spliteHalves(std::vector<T>& arr);
template <class T>
std::vector<T> sortHalves(std::vector<T>& left, std::vector<T>& right){
    int sortedSize = left.size() + right.size();
    // std::shared_ptr<std::vector<T>> sortedArr = std::make_shared<std::vector<T>>(sortedSize);
    std::vector<T> sortedArr(sortedSize);
    int lenLeft = static_cast<int>(left.size());
    int lenRight = static_cast<int>(right.size());
    int i{0}, j{0}, k{0};
    while (i < lenLeft && j < lenRight) {
        if (left[i] <= right[j]) {
            sortedArr[k] = left[i];
            i++;
        }
        else {
            sortedArr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < lenLeft) {
        sortedArr[k] = left[i];
        i++;
        k++;
    }
    while (j < lenRight) {
        sortedArr[k] = right[j];
        j++;
        k++;
    }
    return sortedArr;
}


template <typename T>
void printArray(std::string const& name, std::vector<T> const &arr) {
    std::cout << name << "\t";
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}