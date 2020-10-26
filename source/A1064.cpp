/*
1064 Complete Binary Search Tree (30分)

Sample Input:
10
1 2 3 4 5 6 7 8 9 0

Sample Output:
6 3 8 1 5 7 9 0 2 4

*/

/*
 * 给定一个序列，将其构造成一个完全二叉排序树
 * 思路：用层序遍历数组来存放结点序列，对BST进行中序遍历（2n为左孩子，2n+1为右孩子）
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int INF = 100000000;

struct Node {
    int data;
    int lChild;
    int rChild;
} Tree[maxn];

int n;                  // 定点数量
vector<int> items;      // 给定元素数组
int num = 0;            // 记录排序队列的索引

// 先序遍历，插入结点
void inOrder(int r) {
    if (r > n) {
        return;
    }
    inOrder(2 * r);
    Tree[r].data = items[num++];
    inOrder(2 * r + 1);
}


int main() {
    cin >> n;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        items.emplace_back(value);
    }
    sort(items.begin(), items.end()); // 将序列自小到大排序
    inOrder(1);
    for (int i = 1; i <= n; i++) {
        cout << Tree[i].data;
        if (i < n) {
            cout << " ";
        }
    }
    return 0;
}