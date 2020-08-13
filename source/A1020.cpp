/*
1020 Tree Traversals (25分)
Suppose that all the keys in a binary tree are distinct positive integers.
Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

Sample Output:
4 1 6 3 5 7 2
*/

/*
 * 根据后序遍历和中序遍历序列，输出层序遍历该二叉树的结果。
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
struct Node {
    int data;
    Node *lChild;
    Node *rChild;
};

int in[maxn], post[maxn];   // 中序遍历与后序遍历序列
int n;                      // 节点个数

Node *create(int postL, int postR, int inL, int inR) {
    if (postL > postR) {
        return nullptr;
    }
    Node *root = new Node;      // new一个Node，存放根结点
    root->data = post[postR];   // 后序区间的尾元素为根结点
    int k = postL;      // 记录中序遍历中根结点的索引
    for (int i = inL; i <= inR; ++i) {
        if (in[i] == post[postR]) {
            k = i;
            break;
        }
    }
    // k-inL为左子树个数
    root->lChild = create(postL, postL + (k - inL) - 1, inL, k - 1);
    root->rChild = create(postL + (k - inL), postR-1, k+1, inR);
    return root;
}

void levelOrder(Node *root) {
    queue<Node*> q;
    q.push(root);
    int cnt = 0;    // 记录当前已输出节点个数
    while(!q.empty()) {
        Node *t = q.front();
        q.pop();
        cout << t->data;
        cnt++;
        if (cnt<n) {
            cout << " ";
        }
        if (t->lChild!= nullptr)
            q.push(t->lChild);
        if (t->rChild!= nullptr)
            q.push(t->rChild);
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    Node *p = create(0, n - 1, 0, n - 1);
    levelOrder(p);
    return 0;
}