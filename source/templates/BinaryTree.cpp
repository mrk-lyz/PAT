#include <bits/stdc++.h>

using namespace std;
const int maxn = 100;

struct Node{
    int data;               // 数据域
    int height;             // 子树高度
    Node *lChild, *rChild;  // 左右孩子
};

// 求树高度
int getHeight(Node *r) {
    if (r == nullptr) {
        return 0;
    }
    int h1 = getHeight(r->lChild) + 1;
    int h2 = getHeight(r->rChild) + 1;
    return h1 > h2 ? h1 : h2;
}

int main() {

    return 0;
}