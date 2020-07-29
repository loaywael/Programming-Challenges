#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include "../include/BubbleSort.hpp"


int main(int argc, char** argv) {
    std::vector<int> Vsrc1({3, 31, 6, 7, 2, 3, 42, 23, 11, 1, 5});
    std::vector<int> Vsrc2({1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9});
    std::vector<int> Vsrc3({4, 2, 3, 4, 4, 3, 5, 6, 7, 1, 9});
    std::vector<int> Vtest1(Vsrc1);
    std::vector<int> Vtest2(Vsrc2);
    std::vector<int> Vtest3(Vsrc3);
    std::sort(std::begin(Vtest1), std::end(Vtest1));
    std::sort(std::begin(Vtest2), std::end(Vtest2));
    std::sort(std::begin(Vtest3), std::end(Vtest3));

    // printArray("src: ", Vsrc1);
    // BubbleSort<int>(Vsrc1);
    // printArray("sorted: ", Vsrc1);
    // printArray("correct: ", Vtest1);
    BubbleSort<int>(Vsrc1);
    BubbleSort<int>(Vsrc2);
    BubbleSort<int>(Vsrc3);
    
    assert(Vtest1 == Vsrc1);
    assert(Vtest2 == Vsrc2);
    assert(Vtest3 == Vsrc3);
    
    return 0;
}