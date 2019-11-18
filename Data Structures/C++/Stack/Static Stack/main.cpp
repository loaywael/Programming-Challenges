#include <iostream>
#include "Stack/Stack.h"
#include "Stack/Stack.cpp"  // fixes linking problem of templates @ compilation

int main(void){

    Stack<std::string> ST(3);

    ST.pop();
    ST.display();
    std::cout << "top on stack: " << ST.getTop() << std::endl;
    std::cout << "-----------------------\n";

    std::cout << ST.getTop() << std::endl;
    ST.push("Alex");
    ST.display();

    ST.push("John");
    ST.display();

    ST.push("Zain");
    ST.display();
    std::cout << "stack size: " << ST.getSize() << std::endl;
    std::cout << "top on stack: " << ST.getTop() << std::endl;
    std::cout << "-----------------------\n";

    std::string item = ST.pop();
    std::cout << "poped item: " << item << std::endl;
    ST.display();
    std::cout << "top on stack: " << ST.getTop() << std::endl;
    std::cout << "-----------------------\n";

    ST.push("Altair");
    ST.display();
    std::cout << "top on stack: " << ST.getTop() << std::endl;
    std::cout << "-----------------------\n";

    ST.push("NotValid");
    return 0;
}