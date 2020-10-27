/*
1066 Root of AVL Tree (25分)

Sample Input 1:
5
88 70 61 96 120

Sample Output 1:
70

Sample Input 2:
7
88 70 61 96 120 90 65

Sample Output 2:
88
*/

/*
 * 给定一个序列，构造平衡二叉树，输出该树的根节点元素
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;
const int INF = 100000000;

struct Node {
    int data;               // 数据域
    int height;             // 子树高度
    Node *lChild, *rChild;  // 左右孩子
};

int n;  // 结点数
vector<int> v;

// 新建以data为权值的AVL结点
Node *newNode(int data) {
    Node *p = new Node;
    p->data = data;
    p->height = 1;
    p->lChild = p->rChild = nullptr;
    return p;
}

// 求树高度
int getHeight(Node *r) {
    if (r == nullptr) {
        return 0;
    }
    return r->height;
}

// 更新结点r的高度
void updateHeight(Node *r) {
    r->height = max(getHeight(r->lChild), getHeight(r->rChild)) + 1;
}

// 计算平衡因子（左子树高度-右子树高度）
int getBalanceFactor(Node *r) {
    return getHeight(r->lChild) - getHeight(r->rChild);
}

// 查找以r为根，数据域为data的结点
Node *search(Node *r, int data) {
    if (r == nullptr) {
        return nullptr;
    }
    if (data == r->data) {
        return r;
    } else if (data < r->data) {
        return search(r->lChild, data);
    } else {
        return search(r->rChild, data);
    }
}

// 左旋（left rotation）
void L(Node *&r) {
    Node *temp = r->rChild;     // 得到A的右子树B
    r->rChild = temp->lChild;   // A的右子树变为B的左子树
    temp->lChild = r;           // B的左子树变为A
    updateHeight(r);
    updateHeight(temp);
    r = temp;                   // 改变r的指向，B成为根结点
}

// 右旋
void R(Node *&r) {
    Node *temp = r->lChild;     // 得到A的左子树B
    r->lChild = temp->rChild;   // A的左子树变为B的右子树
    temp->rChild = r;           // B的右子树变为A
    updateHeight(r);
    updateHeight(temp);
    r = temp;                   // 改变r的指向，B成为根结点
}


/*
 * 插入
 * 树形       判定          调整
 * LL
 * LR
 * RR
 * RL
 * */
void insert(Node *&r, int data) {
    if (r == nullptr) {
        r = newNode(data);              // 在空节点处插入
        return;
    }
    if (data < r->data) {
        insert(r->lChild, data);    // 往左子树插入
        updateHeight(r);               // 更新树高
        if (getBalanceFactor(r) == 2) {
            if (getBalanceFactor(r->lChild) == 1) {           // LL
                R(r);               // 右旋
            } else if (getBalanceFactor(r->lChild) == -1) {   // LR
                L(r->lChild);
                R(r);
            }
        }
    } else {
        insert(r->rChild, data);    // 往右子树插入
        updateHeight(r);               // 更新树高
        if (getBalanceFactor(r) == -2) {
            if (getBalanceFactor(r->rChild) == -1) {          // RR
                L(r);               // 左旋
            } else if (getBalanceFactor(r->rChild) == 1) {   // RL
                R(r->rChild);
                L(r);
            }
        }
    }
}

int main() {
    int value;
    Node *r = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(r, value);
    }
    cout << r->data << endl;
    return 0;
}