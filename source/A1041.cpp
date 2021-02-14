/*
1041 Be Unique (20 分)
Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1,10^4].
 first one who bets on a unique number wins. For example, if there are 7 people betting on { 5 31 5 88 67 88 17 }, then the second one who bets on 31 wins.

Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31

Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * 利用散列表
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
const int INF = 100000000;

int n;
int p[maxn];
vector<int> v;

int main() {
    cin >> n;
    int k;
    fill(p, p + maxn, 0);
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.emplace_back(k);
        p[k]++;
    }
    bool unique = false;
    for (auto item:v) {
        if (p[item] == 1) {
            unique = true;
            cout << item;
            break;
        }
    }
    if (!unique) {
        cout << "None";
    }
    return 0;

}

