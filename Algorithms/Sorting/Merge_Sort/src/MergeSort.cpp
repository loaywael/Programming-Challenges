#include "../include/MergeSort.hpp"



template <typename T>
int getMidPoint(std::vector<T> const& arr) {
    int arrSize = arr.size();
    int midId = arrSize % 2 == 0 ? (arrSize/2) - 1 : ((arrSize+1)/2) - 1;
    return midId;
}


template <class T>
std::vector<T> MergeSort(std::vector<T>& arr) {
    int midId = getMidPoint<T>(arr);
    std::vector<T> left(arr.begin(), arr.begin()+midId+1);
    std::vector<T> right(arr.begin()+midId+1, arr.end());
    if ((left.size()) >= 1 && (right.size()) >= 1) {
        // mergeSort
        left = MergeSort(left);
        right = MergeSort(right);
    }
    return sortHalves<T>(left, right);
}


template <class T>
std::vector<T> sortHalves(std::vector<T>& left, std::vector<T>& right){
    int sortedSize = left.size() + right.size();
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




template std::vector<int> MergeSort(std::vector<int>& arr);
template std::vector<long int> MergeSort(std::vector<long int>& arr);
template std::vector<double> MergeSort(std::vector<double>& arr);
template int getMidPoint<int>(std::vector<int> const& arr);
template int getMidPoint<long int>(std::vector<long int> const& arr);
template int getMidPoint<double>(std::vector<double> const& arr);
template  std::vector<int> sortHalves<int>(std::vector<int>&, std::vector<int>&);
template  std::vector<long int> sortHalves<long int>(std::vector<long int>&, std::vector<long int>&);
template  std::vector<double> sortHalves<double>(std::vector<double>&, std::vector<double>&);
template void printArray<int>(std::string const& name, std::vector<int> const &arr);
template void printArray<long int>(std::string const& name, std::vector<long int> const &arr);
template void printArray<double>(std::string const& name, std::vector<double> const &arr);

