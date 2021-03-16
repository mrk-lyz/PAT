/*
1068 Find More Coins (30 分)

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
*/

/*
 * 01背包问题，序列取数凑合，用DFS解决
 * 测试点6是序列和小于给定数的情况，需要特判
 * */
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define INF 100000000

int n;
int m;
vector<int> v;  // 货币队列
vector<int> res;
bool flag = false;
int sum = 0;

void DFS(int r, int cw) {   // 考虑r位置的货币，cw是当前价值总和
    if (r > n || flag) {
        return;
    }
    if (cw == m) {     // 满足货币金额
        for (auto i = 0; i < res.size() - 1; i++) {
            cout << res[i] << " ";
        }
        cout << res[res.size() - 1];
        flag = true;
        return;
    }
    if (cw + v[r] <= m) {        // 可以加入r号货币
        res.emplace_back(v[r]);
        DFS(r + 1, cw + v[r]);
        res.pop_back();
    }
    DFS(r + 1, cw);           // 不加入r号货币
}

int main() {
    cin >> n >> m;
    int coin;
    for (auto i = 0; i < n; i++) {
        cin >> coin;
        v.emplace_back(coin);
        sum += coin;
    }
    sort(v.begin(), v.end(), less<>());
    if (sum >= m) {     // 应对测试点6，不然会超时
        DFS(0, 0);
    }

    if (!flag) {
        cout << "No Solution";
    }
    return 0;
}

