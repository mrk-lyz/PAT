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
int minCost = INF;
vector<int> pre[maxn];      // 前驱点集数组
vector<int> tempPath, path; // path存放最后结果

// 求出所有最短路径，u是起点
void Dijkstra(int u) {
    fill(visited, visited + n, false);
    fill(dis, dis + n, INF);
    dis[u] = 0;

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
                    pre[j].clear();
                    pre[j].push_back(v);
                } else if (dis[v] + g[v][j] == dis[j]) {    // 找到相同距离的路径
                    pre[j].push_back(v);
                }
            }
        }
    }
}

void DFS(int u) {
    if (u == s) {
        tempPath.push_back(u);
        int tempCost = 0;
        for (int i = tempPath.size() - 1; i > 0; i--) {
            tempCost += c[tempPath[i]][tempPath[i - 1]];
        }
        if (tempCost < minCost) {
            path = tempPath;
            minCost = tempCost;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(u);
    for (int i : pre[u]) {
        DFS(i);
    }
    tempPath.pop_back();
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
    DFS(d);
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    return 0;
}

