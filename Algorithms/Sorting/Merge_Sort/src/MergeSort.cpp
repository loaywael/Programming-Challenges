#include "../include/MergeSort.hpp"



template <typename T>
int MergeSort<T>::getMidPoint(std::vector<T> const& arr) {
    int arrSize = arr.size();
    int midId = arrSize % 2 == 0 ? (arrSize/2) - 1 : ((arrSize+1)/2) - 1;
    return midId;
}


template <class T>
std::vector<T> MergeSort<T>::sort(std::vector<T>& arr) {
    int midId = getMidPoint(arr);
    std::vector<T> left(arr.begin(), arr.begin()+midId+1);
    std::vector<T> right(arr.begin()+midId+1, arr.end());
    if ((left.size()) >= 1 && (right.size()) >= 1) {
        // mergeSort
        left = sort(left);
        right = sort(right);
    }
    return merge(left, right);
}


template <class T>
std::vector<T> MergeSort<T>::merge(std::vector<T>& left, std::vector<T>& right){
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



template class MergeSort<int>;
template class MergeSort<float>;
template class MergeSort<long int>;
template class MergeSort<double>;
template class MergeSort<char>;
template class MergeSort<std::string>;
