/*
1050 String Subtraction (20分)

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/

/*
 * 输入两行字符串s1和s2，删去s1中的s2字符并打印。
 * */
#include <bits/stdc++.h>

using namespace std;

int main() {
    bool flag[128];
    fill(flag, flag+128, true);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (char i : s2) {
        flag[i] = false;
    }
    for (char i : s1) {
        if(flag[i]) {
            cout << i;
        }
    }
    return 0;
}