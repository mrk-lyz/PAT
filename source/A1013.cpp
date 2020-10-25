/*
1012 The Best Rank (25分)
It is vitally important to have all the cities connected by highways in a war.
If a city is occupied by the enemy, all the highways from/toward that city are closed.
We must know immediately if we need to repair any other highways to keep the rest of the cities connected.
Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

Sample Input:
3 2 3
1 2
1 3
1 2 3

Sample Output:
1
0
0
*/

/*
 * 求删除一个结点后的连通分量个数
 * 删除节点时不改变邻接矩阵，而是在DFS时遇到目标节点就停止遍历
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int INF = 100000000;

int n, m, k;                // 城市总数，铁路数，待考察城市数
int g[maxn][maxn] = {};     // 无向图邻接矩阵
bool visit[maxn];
int city;                   // 被占领城市序号
int res = 0;

void DFS(int u) {
    if (u==city) {
        return;
    }
    visit[u] = true;
    for (int i = 1; i <= n; i++) {
        if (!visit[i] && g[u][i] > 0) {
            DFS(i);
        }
    }
}

void DFSTraverse() {
    res = 0;
    fill(visit, visit + maxn, false);
    for (int i = 1; i <= n; i++) {
        if (!visit[i] && i!=city) {
            DFS(i);
            res++;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    for (int i = 0; i < k; i++) {
        cin >> city;
        vector<int> temp;
        for (int j = 1; j <= n; j++) {
            if (g[city][j] > 0) {
                temp.emplace_back(j);
                g[city][j] = 0;
            }
        }
        for (auto item:temp) {
            g[item][city] = 0;
        }
        DFSTraverse();
        cout << res-1 << endl;
        for (auto item:temp) {
            g[city][item] = g[item][city] = 1;
        }
    }
    return 0;
}