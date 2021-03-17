/*
1065 A+B and C (64bit) (20 分)

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false

*/

/*
 * C++判断溢出，python可以直接相加
 * 为什么不能cin long long？（测试点3不能通过）
 * */
#include <bits/stdc++.h>
#include <utility>

using namespace std;

const int maxn = 15;
const int INF = 100000000;


int n;
long long a, b, c, sum;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        cout << "Case #" << i + 1 << ": ";
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0) {  // 结果上界溢出
            cout << "true";
        } else if (a < 0 && b < 0 && sum >= 0) {    // 下界溢出
            cout << "false";
        } else if (sum > c) {
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl;
    }
}

