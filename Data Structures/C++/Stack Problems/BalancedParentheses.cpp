#include <iostream>
#include <string>
#include <stack>

bool isBalanced(const std::string& exp); 

int main(void){

    std::string sF = "[{]djjf";
    std::string sT = "[{djjf}]";
    std::cout << isBalanced(sF) << std::endl;
    std::cout << isBalanced(sT) << std::endl;
    return 0;
}


bool isBalanced(const std::string& exp){
    std::stack<char> buffer;
    for(char ch : exp){
        if(ch == '[' || ch =='{'){
            buffer.push(ch);
        }
        else if(ch == ']' || ch == '}'){
            buffer.pop();
        }
    }
    return buffer.empty(); // true means no error
}