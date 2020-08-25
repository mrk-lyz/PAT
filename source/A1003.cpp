/*
1003 Emergency (25分)
Sample Input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:
2 4
*/


/*
 * 解法一：DFS
 * 找出C1->C2的所有最短路径，比较路径节点上的权值总和
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int INF = 100000000;

int n;              // 城市数量
int m;              // 道路数量
int c1, c2;         // 当前所在城市与待救援城市
int teams[maxn];    // 城市救援人数
int g[maxn][maxn];  // 邻接矩阵
int path = 0;       // 最短路径数
int maxWeight = 0;  // 最大救援队数量
int minLength = INF;// 最短路径长度

void DFS(int u, vector<int> v, int length, int weight) {
//    cout << u << " " << v.size() << " " << length << " " << weight << endl;
    if (u == c2) {
        if(length<minLength) {          // 找到一条更短路径
            minLength = length;
            path = 1;
            maxWeight = weight;
        } else {                        // 找到一条相同长度的路径
            path++;
            if(weight > maxWeight) {
                maxWeight = weight;
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (g[u][i] > 0) {
            if (length + g[u][i] <= minLength && find(v.begin(), v.end(), i) == v.end()) {
                v.push_back(i);
                DFS(i, v, length + g[u][i], weight+teams[i]);
                v.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) {
        cin >> teams[i];
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    vector<int> p;
    p.push_back(c1);
    DFS(c1, p, 0, teams[c1]);
    cout << path << " " << maxWeight << endl;
    return 0;
}

/*
 * 解法二：Dijkstra算法
 * */

//#include <bits/stdc++.h>

//
//using namespace std;
//
//int main() {
//    int n, m, C1, C2;
//    cin>>n>>m>>C1>>C2;
//    vector<int> weight(n, 0);
//    for (int i = 0; i < n; i++) {
//        cin>>weight[i];
//    }
//
//    vector<vector<int> > edge(n, vector<int>(n, INT_MAX));
//    vector<int> dis(n, INT_MAX);
//    vector<int> roads(n, 0);
//    vector<int> teams(n, 0);
//    vector<bool> visit(n, false);
//
//    //初始化边权值表
//    int c1, c2, L;
//    for (int i = 0; i < m; i++) {
//        cin>>c1>>c2>>L;
//        edge[c1][c2] = edge[c2][c1] = L;
//    }
//    dis[C1] = 0;
//    teams[C1] = weight[C1];
//    roads[C1] = 1;
//
//    for (int i = 0; i < n; ++i) {
//        int u = -1, minn = INT_MAX;
//        for (int j = 0; j < n; j++) {
//            if (visit[j] == false && dis[j] < minn) {
//                u = j;
//                minn = dis[j];
//            }
//        }
//        cout << u << endl;
//        if (u == -1) break;
//        visit[u] = true;
//        for (int v = 0; v < n; v++) {
//            if (visit[v] == false && edge[u][v] != INT_MAX) {
//                if (dis[u] + edge[u][v] < dis[v]) {
//                    dis[v] = dis[u] + edge[u][v];
//                    roads[v] = roads[u];
//                    teams[v] = teams[u] + weight[v];
//                } else if (dis[u] + edge[u][v] == dis[v]) {
//                    roads[v] = roads[v] + roads[u];
//                    if (teams[u] + weight[v] > teams[v]) {
//                        teams[v] = teams[u] + weight[v];
//                    }
//                }
//            }
//        }
//    }
//    cout<<roads[C2]<<" "<<teams[C2]<<endl;
//    return 0;
//}
