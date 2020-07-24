#include "isBalanced.hpp"

bool isPair(const char& ch1, const char& ch2){
    if (ch1 == '{' && ch2 == '}'){
        return 1;
    }
    else if (ch1 == '[' && ch2 == ']'){
        return 1;
    }

    if (ch1 == '(' && ch2 == ')'){
        return 1;
    }

    return 0;
}


bool isBalanced(const std::string& exp){
    std::stack<char> buffer;
    for(char ch : exp){
        if (ch == '[' || ch =='{' || ch == '('){
            buffer.push(ch);
        }
        else if (ch == ']' || ch == '}' || ch == ')'){
            if (buffer.empty() || !isPair(buffer.top(), ch)){
                return 0;
            }
            buffer.pop();
        }
    }
    return buffer.empty(); // true means no error
}


// int main(void){

//     std::string s;
//     while (1){
//         std::cout << "Enter string: ";
//         getline(std::cin, s);
//         if (s == "q"){break;}
//         std::string state = isBalanced(s)? "Balanced" : "Not Balanced";
//         std::cout <<  state << std::endl; 
        
//     }   
//     return 0;
// }