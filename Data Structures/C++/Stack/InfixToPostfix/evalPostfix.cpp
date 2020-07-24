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

#include "isBalanced.hpp"
#include "evalPostfix.hpp"


std::string getPostFix(const std::string& equation, std::stack<char>& stack){
    /*
    @param equation: string enquation to be converted to postfix statement.
    @param stack: reference object to char stack template to be modified inplace.
    */
    std::string postfix = "";   // postfix to be returned used to append operations
    if (isBalanced(equation)){
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
    throw("Equation has imbalance parenthesis\n");
}


void displayStack(const std::stack<char>& stack){
    /*
        Displays the given stack reference for debugging targets
        @param stack: stack reference to be cloned to visually inspect its items
    */
    std::cout << "[";
    for(std::stack<char> dump = stack; !dump.empty(); dump.pop()){
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
        case '%':
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

// template <class T>
int evalPostFix(const std::string& postfix){
    std::stack<int> buffer;
    int value, num1, num2;

    for (const char ch : postfix){
        if (isdigit(ch)){
            buffer.push(ch - '0');
        }
        
        else if (getPriority(ch) > 0 && buffer.size() >= 2){
            num1 = buffer.top();
            buffer.pop();
            num2 = buffer.top();
            buffer.pop();
            value = getOperation(ch, num2, num1);
            buffer.push(value);
        }
    } 
    value = buffer.top();
    buffer.pop();
    return value;
}

// template <class T>
int getOperation(const char& ch, const int x, const int y){
    /*
        Returns result of a given operation
        @param ch: reference of a given char to be evaluated
        @param x: first number to operate
        @param y:  second number to operate
    */
    int result;
    switch (ch){
        case '^':
            result = pow(x, y);
            break;

        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '%':
            result = x % y;
            break;

        case '-':
            result = x - y;
            break;
        case '+':
            result = x + y;
            break;

        default:
            result = 0;
            break;
    }
    return result;
}

// template int evalPostFix<int>(const std::string& postfix);
// template int getOperation<int>(const char&, const int, const int);