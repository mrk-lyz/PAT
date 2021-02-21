/*
1061 Dating (20 分)

Sample Input:
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
Sample Output:
THU 14:04
*/

/*
 * 注意break的使用
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;
const int INF = 100000000;

string s1, s2, s3, s4;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int date, hour, minute;

int main() {
    cin >> s1 >> s2 >> s3 >> s4;
    int m = min(s1.length(), s2.length());
    bool first = true;
    for (int i = 0; i < m; i++) {
        if (first && s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i]) {
            date = s1[i] - 'A';
            first = false;
        }
        else if (!first && ((s1[i] >= 'A' && s1[i] <= 'N') || isdigit(s1[i])) && s1[i] == s2[i]) {
            if (s1[i] >= 'A' && s1[i] <= 'N') {
                hour = s1[i] - 'A' + 10;
            } else {
                hour = s1[i] - '0';
            }
            break;  // 很重要！
        }
    }
    m = min(s3.length(), s4.length());
    for (int i = 0; i < m; i++) {
        if (((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')) && s3[i] == s4[i]) {
            minute = i;
            break;  // 很重要！
        }
    }
    printf("%s %.2d:%.2d", week[date].c_str(), hour, minute);
}

