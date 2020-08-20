/*
1043 Is It a Binary Search Tree (25分)

Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8

Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8

Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *lChild;
    Node *rChild;
};

int n;              // 结点个数
vector<int> p, pre, preMirror, post, postMirror;

void insert(Node *&r, int data) {
    if (r == nullptr) {
        r = new Node;
        r->data = data;
        r->lChild = nullptr;
        r->rChild = nullptr;
        return;
    }
    if (data < r->data) {
        insert(r->lChild, data);
    } else {
        insert(r->rChild, data);
    }
}

// 先序遍历原树
void preOrder(Node *r) {
    if (r == nullptr) {
        return;
    }
    pre.push_back(r->data);
    preOrder(r->lChild);
    preOrder(r->rChild);
}

// 先序遍历镜像树
void preOrderMirror(Node *r) {
    if (r == nullptr) {
        return;
    }
    preMirror.push_back(r->data);
    preOrderMirror(r->rChild);
    preOrderMirror(r->lChild);
}

// 后序遍历原树
void postOrder(Node *r) {
    if (r == nullptr) {
        return;
    }
    postOrder(r->lChild);
    postOrder(r->rChild);
    post.push_back(r->data);
}

// 后序遍历镜像树
void postOrderMirror(Node *r) {
    if (r == nullptr) {
        return;
    }
    postOrderMirror(r->rChild);
    postOrderMirror(r->lChild);
    postMirror.push_back(r->data);
}

int main() {
    int data;
    cin >> n;                   // 二叉树节点数
    Node *root = nullptr;      // 二叉树根节点
    for (int i = 0; i < n; ++i) {
        cin >> data;
        p.push_back(data);
        insert(root, data); // 生成二叉排序树
    }
    preOrder(root);             // 先序遍历原树
    preOrderMirror(root);       // 先序遍历镜像树
    if (p==pre) {
        cout << "YES" << endl;
        postOrder(root);       // 后序遍历原树
        for (int i = 0; i < post.size(); ++i) {
            cout << post[i];
            if (i<post.size()-1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    } else if (p==preMirror){
        cout << "YES" << endl;
        postOrderMirror(root);  // 后序遍历镜像树
        for (int i = 0; i < postMirror.size(); ++i) {
            cout << postMirror[i];
            if (i<postMirror.size()-1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    } else {
        cout << "NO" << endl;
    }
}
