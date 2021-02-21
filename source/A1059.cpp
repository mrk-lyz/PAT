/*
1059 Prime Factors (25分)

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/

/*
 * 分解质因数
 * 思路：从小到大寻找不等于原值的质因数，迭代相除后继续寻找，直到除得的数为质数
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;
const int INF = 100000000;

long int n;
vector<long int> v;
map<int, int> cnt;

bool isPrime(long int num) {
    bool flag = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            flag = false;
        }
    }
    return flag;
}

void divide(long int num) {
    while (!isPrime(num)) {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0 && isPrime(i)) {
                v.emplace_back(i);
                num = num / i;
                break;
            }
        }
    }
    v.emplace_back(num);
}

int main() {
    cin >> n;
    cout << n << "=";
    if (n == 1) {
        cout << "1";
        return 0;
    }
    divide(n);
    for (auto item:v) {
        auto it(cnt.find(item));
        if (it != cnt.end()) {
            it->second++;
        } else {
            cnt[item] = 1;
        }
    }

    for (auto it(cnt.begin()); it!=cnt.end(); it++) {
        if (it != cnt.begin()) {
            cout << "*";
        }
        cout << it->first;
        if (it->second>1) {
            cout << "^" << it->second;
        }
    }
    return 0;
}


