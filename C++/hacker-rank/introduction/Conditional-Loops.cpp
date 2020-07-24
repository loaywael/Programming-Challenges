/*

You will be given two positive integers, a and b (a <= b), separated by a newline.
For each integer n in the interval [a, b] :

If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for , "two" for , and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".

*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string nums[] = {
    "zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"
    };

int main() {
    // Complete the code.

    int a = 0, b = 0;

    cin >> a >> b;

    for (int i = a; i < b + 1; i++){
        // solves the problem but fails the testcases!
        if (i >= 1 && i <= 9){
            cout << nums[i] << endl;
        }
        else if (i % 2 == 0){
            cout << "even" << endl;
        }
        else if (i > 0){
            cout << "odd" << endl;
        }