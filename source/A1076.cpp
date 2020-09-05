/*
1076 Forwards on Weibo (30分)

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
*/


/*
 * 找出有向图图中距离特定节点的深度小于等于l的所有节点数
 * 由于遍历深度有限制，本题应当采用BFS
 * 采用邻接矩阵，最后一个测试点会超时
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int n, l;                       // 用户数和BFS深度
vector<vector<int> > graph;     // 邻接表
int visited[maxn];              // 访问标志数组

void BFS(int start) {
    // 初始化
    fill(visited + 1, visited + n + 1, false);
    int depth = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int numCurrentNode = 1;     // 当前层次待遍历节点数
    int numNextNode = 0;        // 下一层次节点数
    int res = 0;                // l层次内总结果节点数
    while (!q.empty()) {
        if (depth > l) {        // 层次越界
            break;
        }
        int node = q.front();
        q.pop();

        // 正式访问节点，添加操作
        res++;
        for (auto &i : graph[node]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                numNextNode++;
            }
        }

        // 判断当前层次是否完成遍历
        numCurrentNode--;
        if (numCurrentNode == 0) {
            depth++;                        // 层次深度+1
            numCurrentNode = numNextNode;
            numNextNode = 0;
        }
    }
    cout << res - 1 << endl;
}

int main() {
    scanf("%d %d", &n, &l);
    graph.resize(n + 1);
    int follows, d;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &follows);
        for (int j = 0; j < follows; ++j) {
            scanf("%d", &d);
            graph[d].push_back(i);
        }
    }

    int res, start;
    scanf("%d", &res);
    for (int i = 0; i < res; i++) {
        scanf("%d", &start);
        BFS(start);
    }

    return 0;
}

//const int maxn = 1010;
//int n, l;   // 用户数和BFS深度
//int origin;
//int graph[maxn][maxn] = {};
//int visited[maxn];
//
//void BFS(int start) {
//    fill(visited, visited + n + 1, false);
//    int depth = 0;
//    queue<int> q;
//    q.push(start);
//    visited[start] = true;
//    int numCurrentNode = 1;
//    int numNextNode = 0;
//    int res = 0;
//    while (!q.empty()) {
//        if (depth > l) {
//            break;
//        }
//        int node = q.front();
//        q.pop();
//        res++;
//        for (int i = 1; i <= n; i++) {
//            if (graph[i][node] == 1 && !visited[i]) {
//                q.push(i);
//                visited[i] = true;
//                numNextNode++;
//            }
//        }
//        numCurrentNode--;
//        if (numCurrentNode == 0) {
//            depth++;
//            numCurrentNode = numNextNode;
//            numNextNode = 0;
//        }
//    }
//    cout << res - 1 << endl;
//}
//
//int main() {
//    scanf("%d %d", &n, &l);
//
//    int follows, d;
//    for (int i = 1; i <= n; ++i) {
//        scanf("%d", &follows);
//        for (int j = 0; j < follows; ++j) {
//            scanf("%d", &d);
//            graph[i][d] = 1;
//        }
//    }
//    int res;
//    scanf("%d", &res);
//    for (int i = 0; i < res; i++) {
//        scanf("%d", &origin);
//        BFS(origin);
//    }
//
//    return 0;
//}


