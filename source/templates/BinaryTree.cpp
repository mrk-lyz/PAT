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

/*
 * DFS模板，i为当前待考察节点
 * 如果用数组存取结果，应当携带一个numNode参数，记录当前路径的点数
 * 如果使用vector等存取路径等结果，切不可用传递引用。另外，在for循环里递归前后应当相应修改vector
 * */

void DFS(int i, int numNode) {
    // 边界条件(null, >)，触发return
    // 约束条件，输出或保存结果，注意加入当前节点和删除节点，最后return
    // * 添加节点语句，写在这里可以保证DFS的封闭性，不用在该函数外加入首节点
    // for循环，遍历每个子节点
    // * 删除节点语句
}

int main() {

    return 0;
}