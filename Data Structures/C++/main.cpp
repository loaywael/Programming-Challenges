#include <iostream>
#include "Stack/Stack.h"
#include "Stack/Stack.cpp"  // fixes linking problem of templates @ compilation

int main(void){

    Stack<std::string> ST(3);
    std::cout << ST.getTop() << std::endl;
    ST.push("Alex");
    ST.printStack();

    ST.push("John");
    ST.printStack();

    ST.push("Zain");
    ST.printStack();
    std::cout << "top on stack: " << ST.getTop() << std::endl;
    std::cout << "-----------------------\n";

    ST.pop();
    ST.printStack();
    std::cout << "top on stack: " << ST.getTop() << std::endl;
    std::cout << "-----------------------\n";

    ST.push("Altair");
    ST.printStack();
    std::cout << "top on stack: " << ST.getTop() << std::endl;
    std::cout << "-----------------------\n";
    
    ST.push("NotValid");
    return 0;
}