#include <iostream>
using namespace std;

// can overload functions that have differnet params, and return types
int func(const int&x, const int &y){
    return x + y;
}

void func(const string& msg){
    cout << msg << endl;
}

int main(void){

    func("hello, world!");
    cout << func(3, 1) << endl;
    return 0;
}