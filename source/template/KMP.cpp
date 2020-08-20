#include <bits/stdc++.h>

using namespace std;
const int maxn = 100;

// 求next数组，下标从0开始
void get_next(const string &pat, vector<int> &next) {
    next[0] = -1;
    int i = 0, j = -1;  // 因为i初值为1，则j初始化为next[i]
    while (i < pat.size() - 1) {
        if (j == -1 || pat[j] == pat[i]) {
            i++;
            j++;
            if (pat[i]!=pat[j])
                next[i] = j;
            else
                next[i] = next[j];
        } else {
            j = next[j];    // 核心语句！j一直跟随next[i]运动，求出更短公共前后缀
        }
    }
}

int KMP(const string &str, const string &pat, const vector<int> &next) {
    int i = 0, j = 0;
    cout << str.size() << " " << pat.size() << endl;
    while (i < str.size() && j < (int) pat.length()) {  // 此处注意unsigned int和int的比较
        if (j == -1 || str[i] == pat[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    cout << i << " " << j << endl;
    if (j >= pat.size()) {
        return i - pat.size();
    } else {
        return -1;
    }
}

int main() {
    string str, pat;         // 模式串
    cin >> str >> pat;
    vector<int> next(pat.size());
    get_next(pat, next);
    for (char c : pat) {
        cout << c << '\t';
    }
    cout << endl;
    for (int i : next) {
        cout << i << '\t';
    }
    cout << endl;
    cout << KMP(str, pat, next) << endl;

    return 0;
}