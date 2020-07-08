/*
1001 A+B Format (20分)
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −10^6≤a,b≤10^6. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9

Sample Output:
-999,991
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    stringstream s;
    s << (m + n);
    string str = s.str();
    int length = str.length();
    for (int i = 0; i < length; i++) {
        cout << str[i];
        if ((length - i - 1) % 3 == 0 && i != length - 1 && str[i] != '-')
            cout << ',';
    }
    return 0;
}