/*
1063 Set Similarity (25 分)

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
*/

/*
 * 计算相似度时，用set的交集可节约时间
 * */

#include <bits/stdc++.h>
#include <utility>

using namespace std;

const int maxn = 55;
const int INF = 100000000;


int n;                  // the total number of sets
int k;                  // the total number of queries
set<int> v[maxn];       // items of sets

void compare(int i, int j) {
    set<int> s;
    set_intersection(v[i].begin(), v[i].end(), v[j].begin(), v[j].end(), inserter(s, s.begin()));   // 取交集
    int sameNum = s.size(), totalNum = v[i].size() + v[j].size() - sameNum;
    cout << fixed << setprecision(1) << sameNum * 100.0 / totalNum << "%" << endl;
    // 使用如下方法测试点4会超时
    //    for (auto &item:v[i]) {
    //        s.insert(item);
    //    }
    //    int common = 0;
    //    for (auto &item:v[j]) {
    //        if (s.find(item) != s.end()) {
    //            common++;
    //        } else {
    //            s.insert(item);
    //        }
    //
    //    }
    //    cout << fixed << setprecision(1) << common * 100.0 / s.size() << "%" << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, r;
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> r;
            v[i + 1].insert(r);
        }
    }
    cin >> k;
    int p, q;
    for (int i = 0; i < k; i++) {
        cin >> p >> q;
        compare(p, q);
    }
}

