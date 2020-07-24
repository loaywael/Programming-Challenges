#include "evalPostfix.hpp"

int main(void){

    std::string s = "(2+3)*2";
    // postfixEQ(s);
    while (1){
        std::string eq, postfix;
        std::stack<char> stack;
        std::cout << "enter equation: ";
        getline(std::cin, eq);
        try{
            postfix = getPostFix(eq, stack);
            std::cout << "postfix: " << postfix << std::endl;
            int val = evalPostFix(postfix);
            std::cout << "result: " << val << std::endl;
        }
        catch (const char* msg){
            std::cout << msg;
            displayStack(stack);
        }
        
    }
    return 0;
}