/*
1099 Build A Binary Search Tree (30分)

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42

Sample Output:
58 25 82 11 38 67 45 73 42

*/

/*
 * 给定一个BST结构，将一串序列插入至该结构中，输出层序遍历序列。
 * 思路：将给定序列自小到大排序，赋值给先序遍历序列的结点中。
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const int INF = 100000000;

struct Node {
    int data;
    int lChild;
    int rChild;
} BST[maxn];

int n;              // 定点数量
vector<int> data;   // 给定元素数组
int num = 0;      // 记录排序队列的索引

// 先序遍历，插入结点
void preOrder(int u) {
    if (u == -1) {
        return;
    }
    preOrder(BST[u].lChild);
    BST[u].data = data[num++];
    preOrder(BST[u].rChild);
}

// 层序遍历
void levelOrder() {
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        Node node = BST[q.front()];
        q.pop();
        cout << node.data;
        num--;
        if (num>0) {
            cout << " ";
        }
        if (node.lChild!=-1) {
            q.push(node.lChild);
        }
        if (node.rChild!=-1) {
            q.push(node.rChild);
        }
    }
}

int main() {
    cin >> n;
    int left, right, value;
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        BST[i].lChild = left;
        BST[i].rChild = right;
        BST[i].data = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> value;
        data.emplace_back(value);
    }
    sort(data.begin(), data.end()); // 将序列自小到大排序
    preOrder(0);
    levelOrder();
    return 0;
}