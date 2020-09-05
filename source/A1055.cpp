/*
1155 Heap Paths (30分)

Sample Input 1:
8
98 72 86 60 65 12 23 50
Sample Output 1:
98 86 23
98 86 12
98 72 65
98 72 60 50
Max Heap

Sample Input 2:
8
8 38 25 58 52 82 70 60
Sample Output 2:
8 25 70
8 25 82
8 38 52
8 38 58 60
Min Heap
Sample Input 3:
8
10 28 15 12 34 9 8 56

Sample Output 3:
10 15 8
10 15 9
10 28 34
10 28 12 56
Not Heap
*/

/*
 * 给出完全二叉树的层序遍历，要求输出先序遍历路径的镜像，并判断是否为最大堆/最小堆
 * */

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;


struct Node {
    int data;
    int lChild;
    int rChild;
};

int n;              // 结点个数
Node p[maxn];       // 节点数组
int path[maxn];     // 路径数组
int numPath = 0;    // 当前路径长度
int minPath = 0, maxPath = 0;   // 递减路径数，递增路径数

void DFS(int i, int numNode) {
    if (p[i].lChild == -1 && p[i].rChild == -1) {
        numPath++;
        // 输出路径
        for (int j = 0; j < numNode; ++j) {
            cout << path[j];
            if (j < numNode - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        bool greater = true, less = true;
        for (int j = 0; j < numNode - 1; j++) {
            if (path[j] > path[j + 1]) {
                less = false;
                break;
            }
        }
        for (int j = 0; j < numNode - 1; j++) {
            if (path[j] < path[j + 1]) {
                greater = false;
                break;
            }
        }
        if (less) {
            minPath++;
        }
        if (greater) {
            maxPath++;
        }
        return;
    }

    // 这里应当遍历所有有意义的子节点
    if (p[i].rChild != -1) {
        path[numNode] = p[p[i].rChild].data;
        DFS(p[i].rChild, numNode + 1);
    }
    if (p[i].lChild != -1) {
        path[numNode] = p[p[i].lChild].data;
        DFS(p[i].lChild, numNode + 1);
    }

}

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].data;
        if (2 * i + 1 < n) {
            p[i].lChild = 2 * i + 1;
        } else {
            p[i].lChild = -1;   // 无目标字结点则为-1
        }
        if (2 * i + 2 < n) {
            p[i].rChild = 2 * i + 2;
        } else {
            p[i].rChild = -1;   // 无目标字结点则为-1
        }
    }
    path[0] = p[0].data;
    DFS(0, 1);
    if (minPath == numPath) {
        cout << "Min Heap";
    }
    if (maxPath == numPath) {
        cout << "Max Heap";
    }
    if (minPath != numPath && maxPath != numPath) {
        cout << "Not Heap";
    }
}