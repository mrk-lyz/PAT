/*
1030 Travel Plan (30分)

Sample Input:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output:
0 2 3 3 40
*/

/*
 * 在无向图中，找出s->d的最短距离的，且边权最短的路径
 * Dijkstra算法
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;
const int INF = 100000000;

int n, m, s, d;             // 顶点数，条数，出发地，目的地
int g[maxn][maxn] = {};     // 邻接矩阵
int c[maxn][maxn] = {};     // 费用矩阵
int dis[maxn] = {};         // 最短路径数组
int cost[maxn] = {};        // 最少花费数组
int visited[maxn] = {};     // 访问标志数组
int pre[maxn];              // 前驱数组

void Dijkstra(int u) {
    fill(visited, visited + n, false);
    fill(dis, dis + n, INF);
    fill(cost, cost + n, 0);
    dis[u] = 0;
    cost[u] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1, minDis = INF;
        // 找出与当前访问点集距离最近的点，记录在v中
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dis[j] < minDis) {
                minDis = dis[j];
                v = j;
            }
        }
        // 如果v=-1，说明接下来图不连通
        if (v == -1) {
            return;
        }
        visited[v] = true;
        // 更新dis和cost数组
        for (int j = 0; j < n; j++) {
            if (!visited[j] && g[v][j] != INF) {            // 找到未访问过的，与当前分量连通的点
                if (dis[v] + g[v][j] < dis[j]) {            // 找到更短距离的路径
                    dis[j] = dis[v] + g[v][j];
                    cost[j] = cost[v] + c[v][j];
                    pre[j] = v;
                } else if (dis[v] + g[v][j] == dis[j]) {    // 找到相同距离的路径
                    if (cost[v] + c[v][j] < cost[j]) {      // 如果第二标尺（费用）更少，则更新费用
                        cost[j] = cost[v] + c[v][j];
                        pre[j] = v;
                    }
                }
            }
        }
    }
}

void DFS(int u) {
    if (u==s) {
        cout << u << " ";
        return;
    }
    DFS(pre[u]);
    cout << u << " ";
}

int main() {
    cin >> n >> m >> s >> d;
    fill(g[0], g[0] + maxn * maxn, INF);
    fill(c[0], c[0] + maxn * maxn, 0);
    int from, to, a, b;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> a >> b;
        g[from][to] = a;
        c[from][to] = b;
        g[to][from] = a;
        c[to][from] = b;
    }
    Dijkstra(s);
    // 打印路径
    int temp = d;
    vector<int> finalPath;
    while (temp!=s) {
        finalPath.push_back(temp);
        temp = pre[temp];

    }
    finalPath.push_back(s);
    reverse(finalPath.begin(), finalPath.end());
    for (auto i :finalPath) {
        cout << i << " ";
    }
    cout << dis[d] << " " << cost[d] << endl;
    return 0;
}




