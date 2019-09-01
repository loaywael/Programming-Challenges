/*

Task:
######

Given a string, S, of length N that is indexed from 0 to N-1, 

print its even-indexed and odd-indexed characters as 2 space-separated strings on a single line.

Input Format:

The first line contains an integer, T (the number of test cases).

Each line i of the T subsequent lines contain a String, .


Output Format

For each String Sj print 's even-indexed characters, followed by a space, followed by Sj's odd-indexed characters.

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        string st, ev, odd;
        cin >> st;
        for (int i = 0, n = st.length(); i < n; i++){
            if (i % 2 == 0){
                ev += (st[i]);     
            }
            else{
                odd += st[i];
            }
        }
        cout << ev << " " << odd << endl;
    }
    return 0;
}
