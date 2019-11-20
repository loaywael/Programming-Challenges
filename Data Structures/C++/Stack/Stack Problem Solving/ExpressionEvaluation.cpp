/*  Program Logic
===================
* if symbol is operand: add it to postfix
* if symbol is left parenthesis: push it on the stack
* if symbol is right parenthesis: pop and 
*   add to postfix all till first left parenthesis
*   discard both left and right parenthesis
* if symbol is an operator: 
*   pop and add to postfix those operators that have 
    precedence greater or equal to the precedence of 
    the scaned operator "assume left parenthesis" with least precendence
* pop and add to postfix all the remaining operands in the stack
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
// #include "BalancedParentheses.cpp"

int getPriority(const char& ch);
template <class T>
void displayStack(const std::stack<T>& stack);
std::string getPostFix(const std::string& equation, std::stack<char>& stack);

int main(void){

    std::string s = "(2+3)*2";
    // postfixEQ(s);
    while (1){
        std::string eq, postfix;
        std::stack<char> stack;
        std::cout << "enter equation: ";
        getline(std::cin, eq);
        postfix = getPostFix(eq, stack);
        std::cout << "postfix: " << postfix << std::endl;
        displayStack(stack);
    }
    return 0;
}

std::string getPostFix(const std::string& equation, std::stack<char>& stack){
    /*
    @param equation: string enquation to be converted to postfix statement.
    @param stack: reference object to char stack template to be modified inplace.
    */

    std::string postfix = "";   // postfix to be returned used to append operations
    for (char ch : equation){   // loop for each char {num, operand, spaces}
        if(isdigit(ch)){
            postfix += ch;  // append numbers in sequence
        }
        else if (getPriority(ch) >= 0){ 
            if (stack.empty()){
                stack.push(ch);     // adds operand to stack when stack is empty
            }

            else if (ch == ')'){    // special case of a closed parenthesis
                // reference stack loop for each item in stack until find begining of parenthesis
                for(std::stack<char>& stack1 = stack; stack1.top() != '('; stack1.pop()){
                    postfix += stack1.top();    //  append all operands between parenthesis in sequence
                }   // pops-out the beging of the parenthesis since closed parenthesis wasn't pushed in stack
                stack.pop();    
            }
            else{    // when current operand is more prior than top in stack
                if (getPriority(stack.top()) > getPriority(ch)){   
                    if (ch != '('){     // applied for all prior operand except '('
                        postfix += stack.top();     // append corresponding operand sorted by priority
                        stack.pop();    // pop-out used operands
                    }   // append higher priority operand to the poped-out operand place in stack
                    stack.push(ch);     
                }
                else{   // if current operand "ch" not prior than top in stack
                    stack.push(ch); // push it in stack
                }
            }
        }        
    }   // append remaining operands in stack to postfix, clean stack
    for(std::stack<char>& stack1 = stack; !stack1.empty(); stack1.pop()){
        postfix += stack.top();
    }
    return postfix;
}

template <class T> 
void displayStack(const std::stack<T>& stack){
    /*
        Displays the given stack reference for debugging targets
        @param stack: stack reference to be cloned to visually inspect its items
    */
    std::cout << "[";
    for(std::stack<T> dump = stack; !dump.empty(); dump.pop()){
        std::cout << dump.top() << " "; //<< getPriority(dump.top()) << " ";
    }
    std::cout << "]" << std::endl;
}

int getPriority(const char& ch){
    /*
        Returns the priority of a given special characters
        @param ch: char reference of a given char to be evaluated
        returns priority: integer value of the special char priority
    */
    int priority;
    switch (ch){
        case '^':
            priority = 3;
            break;

        case '*':
        case '/':
            priority = 2;
            break;

        case '-':
        case '+':
            priority = 1;
            break;

        case '(':
        case ')': 
            priority = 0;
            break;

        default:
            priority = -1;
            break;
    }
    return priority;
}
           

// used in the evaluation step of postfix
    // char* sch = (char*) ch;
    // num =  atoi(sch);
    // postfix.push_back(num);
