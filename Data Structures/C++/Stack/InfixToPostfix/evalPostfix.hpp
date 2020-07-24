#pragma once
#include <iostream> 
#include <math.h>
#include <sstream>
#include <stack>
#include <string>
#include <vector> 

int getPriority(const char& ch);
void displayStack(const std::stack<char>& stack);
// template <class T>
int getOperation(const char& ch, const int x, const int y);
std::string getPostFix(const std::string& equation, std::stack<char>& stack);
// template <class T>
int evalPostFix(const std::string& postfix);
