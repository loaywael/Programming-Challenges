#include <iostream>
#include "DStack.h"

int main(void){

    std::cout << std::endl;
    DStack::Stack<std::string> dstk;

    std::cout << "top item in stack: " << dstk.getTop() << std::endl;

    dstk.push("one");
    dstk.push("two");
    dstk.push("three");
    dstk.display();
    std::cout << "stack size: " << dstk.getSize() << std::endl;
    // ---------------------------
    std::string item1 = dstk.pop();
    std::cout << "poped item: " << item1 << std::endl;
    std::cout << "-----------------------\n" << std::endl;
    dstk.display();

    std::cout << "top item in stack: " << dstk.getTop() << std::endl;
    std::cout << std::endl;
    // ---------------------------
    std::string item2 = dstk.pop();
    std::string item3 = dstk.pop();
    // std::string item4 = dstk.pop();
    dstk.display();
    std::cout << "top item in stack: " << dstk.getTop() << std::endl;
    return 0;
}