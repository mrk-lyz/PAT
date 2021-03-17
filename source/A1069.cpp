/*
1069 The Black Hole of Numbers

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/

/*
 * 简单循环
 * 注意1：需要用do-while结构，测试点5输入为6174
 * 注意2：int转vector需要保证size为4，否则要加0
 * */
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define INF 100000000

string str;
vector<int> v;
int res;

int vec2int(const vector<int> &vec) {
    int exp = 0;
    int result = 0;
    for (int i = vec.size() - 1; i >= 0; i--) {
        result += vec[i] * pow(10, exp);
        exp++;
    }
    return result;
}

int main() {
    cin >> str;
    res = stoi(str);
    do {
        if (res % 1111 == 0) {
            cout << res << " - " << res << " = 0000";
            break;
        }
        v.clear();
        int r = res;
        while (r != 0) {
            v.emplace_back(r % 10);
            r = r / 10;
        }
        while (v.size()<4) {
            v.emplace_back(0);
        }
        sort(v.begin(), v.end(), less<>());         // 升序排列
        int a = vec2int(v);
        sort(v.begin(), v.end(), greater<>());      // 降序排列
        int b = vec2int(v);
        printf("%04d - %04d = %04d\n", b, a, b - a);
        res = b - a;
    } while (res != 6174);
    return 0;
}
