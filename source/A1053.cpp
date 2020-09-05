/*
1053 Path of Equal Weight (30分)

Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19

Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
*/

/*
 * 找出根节点到叶子节点的给定权值和的路径
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 101;
struct Node {
    int weight;         // 权重
    vector<int> child;  // 子节点
};

int n, m, s;    // 节点数、非叶节点数、所需权重和
Node p[maxn];
int path[maxn];

bool cmp(int a, int b) {
    return p[a].weight > p[b].weight;
}

// i为当前节点索引，numNode为当前路径节点数量，sum为当前路径权重和
// 之所以要设置numNode，是因为递归迭代过程中path内的元素个数一直发生变化，但是由于最后无排序操作，前numNode元素显然已就位
void DFS(int i, int numNode, int sum) {
    if (sum > s) {
        return;
    }
    if (sum == s) {
        if (!p[i].child.empty()) {  // 当前结点非叶子结点
            return;
        }
        for (int j = 0; j < numNode; ++j) {
            cout << p[path[j]].weight;
            if (j < numNode - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        return;
    }
    for (int j = 0; j < p[i].child.size(); ++j) {
        // p[i].child[j]表示遍历时的子节点索引
        path[numNode] = p[i].child[j];
        DFS(p[i].child[j], numNode + 1, sum + p[p[i].child[j]].weight);
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].weight;
    }
    int id, k, child;
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;     // 输入id号和子节点数
        for (int j = 0; j < k; ++j) {
            cin >> child;
            p[id].child.push_back(child);
        }
        sort(p[id].child.begin(), p[id].child.end(), cmp);  // 按照权值由大到小排序
    }
    path[0] = 0;
    DFS(0, 1, p[0].weight);
    return 0;
}