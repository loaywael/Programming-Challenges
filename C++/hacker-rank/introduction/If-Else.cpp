/*
Task:
########
Given a positive integer denoting n, do the following:

If 1 <= n <= 9, then print the lowercase English word corresponding to the number (e.g., one for , two for , etc.).

If n > 9, print Greater than 9.

*/

#include <bits/stdc++.h>

using namespace std;

string nums[] = {
    "zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"
    };

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Write Your Code Here
    if (n >= 1 && n <= 9){
        cout << nums[n] << endl;
    }
    else{
        cout << "Greater than 9" << endl;
    }

    return 0;
}
