/*
1009 Product of Polynomials (25分)
This time, you are supposed to find A×B where A and B are two polynomials.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 3 3.6 2 6.0 1 1.6
*/

/*
 * 注意：多项式相乘可能导致某一项系数为0，此时应舍去
 *  2 2 -1 1 1.5
    2 1 1.5 0 2.25
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const int INF = 100000000;

map<int, double, greater<> > a, b, res;
int k1, k2;
int n = 0;      // 有效项个数

int main() {
    double co;
    int exp;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> exp >> co;
        if (co != 0.0) {
            a[exp] = co;
        }

    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> exp >> co;
        if (co != 0.0) {
            b[exp] = co;
        }
    }

    for (auto &it1 : a) {
        for (auto &it2 : b) {
            exp = it1.first + it2.first;
            co = it1.second * it2.second;
            if (res.count(exp) == 0) {          // n项式初次出现
                res[exp] = co;
                n++;
            } else {                            // n项式重复出现
                res[exp] += co;
                if (res[exp] == 0.0) {
                    n--;
                }
            }
        }
    }
    cout << n;
    for (auto &re : res) {
        if (re.second != 0.0) {
            cout << " " << re.first << " " << fixed << setprecision(1) << re.second;
        }

    }
    return 0;
}
