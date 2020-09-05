/*
1004 Counting Leaves (30分)
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Sample Input:
2 1
01 1 02
Sample Output:
0 1
*/

/*
 * 给定一棵二叉树，从中2找出每一层次中的叶子节点数量
 * 核心：分层
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const int INF = 100000000;

struct Node {
    int data;
    vector<int> children;

    Node() : data(0), children(0) {}
} p[maxn];

int n;          // 节点数量
int m;          // 非叶子节点数量
int level = 0;  // 记录总层数
int res[maxn];  // 结果保存在res[0]~res[level-1]

void levelOrder() {
    queue<Node> q;              // 初始化队列
    q.push(p[1]);
    int numNode = 1;            // 当前层级的节点数
    int numNextNode = 0;        // 下一层总节点数
    res[0] = 0;                 // 第一层有1个节点
    int numLeaf = 0;            // 当前层次的叶子节点
    while (!q.empty()) {
        Node t = q.front();     // 取出队首元素
        q.pop();
        for (int i : t.children) {
            q.push(p[i]);
            numNextNode++;      // 下一层次的叶子节点数量加一
        }
        if (t.children.empty()) {   // 如果取出的是叶子节点
            numLeaf++;
        }
        numNode--;                  // 当前层级节点数减一
        if (numNode == 0) {         // 当前层已遍历完成，下一层的总节点数也已经确定
            res[level] = numLeaf;   // 保存结果
            level++;                // 总层数加1
            // 进入下一层次
            numNode = numNextNode;
            numNextNode = 0;
            numLeaf = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    int id, k, temp;
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        p[id].data = id;
        for (int j = 0; j < k; ++j) {
            cin >> temp;
            p[temp].data = temp;
            p[id].children.push_back(temp);
        }
    }
    levelOrder();
    for (int i = 0; i < level; ++i) {
        cout << res[i];
        if (i < level - 1) {
            cout << " ";
        }
    }
    return 0;
}



