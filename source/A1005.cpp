/*
1005 Spell It Right (20分)
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Sample Input:
12345
Sample Output:
one five
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const int INF = 100000000;

string str;
int sum = 0;
map<int, string> intToString = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}
};

int main() {
    getline(cin, str);
    for (auto c : str) {
        sum += (c - '0');
    }
    str = to_string(sum);
    for (int i = 0; i < str.size(); ++i) {
        cout << intToString[str[i]-'0'];
        if (i<str.size()-1) {
            cout << " ";
        }
    }
    return 0;
}





