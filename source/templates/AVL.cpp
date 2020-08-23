/*
 * AVL树是一棵二叉平衡排序树
 * */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;               // 数据域
    int height;             // 子树高度
    Node *lChild, *rChild;  // 左右孩子
};

// 新建节点
Node *newNode(int data) {
    Node *p = new Node;
    p->data = data;
    p->height = 1;
    p->lChild = p->rChild = nullptr;
    cout << p << endl;
    return p;
}

// 求树高度
int getHeight(Node *r) {
    if (r == nullptr) {
        return 0;
    }
    return r->height;
}

// 更新节点r的height
void updateHeight(Node *r) {
    r->height = max(getHeight(r->lChild), getHeight(r->rChild)) + 1;
}

// 计算平衡因子
int getBalanceFactor(Node *r) {
    return getHeight(r->lChild) - getHeight(r->rChild);
}

// 查找操作
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
    if(data<r->data) {
        insert(r->lChild, data);    // 往左子树插入
        updateHeight(r);               // 更新树高
        if (getBalanceFactor(r)==2) {
            if (getBalanceFactor(r->lChild)==1) {           // LL
                R(r);               // 右旋
            } else if (getBalanceFactor(r->lChild)==-1) {   // LR
                L(r->lChild);
                R(r);
            }
        }
    } else {
        insert(r->rChild, data);    // 往右子树插入
        updateHeight(r);               // 更新树高
        if (getBalanceFactor(r)==-2) {
            if (getBalanceFactor(r->rChild)==-1) {          // RR
                L(r);               // 左旋
            } else if (getBalanceFactor(r->rChild)==-1) {   // RL
                R(r->rChild);
                L(r);
            }
        }
    }
}

// AVL树建立
Node* create(vector<int> &v) {
    Node* r = nullptr;
    for (int i : v) {
        insert(r, i);
    }
    return r;
}
int main() {
    Node *p = newNode(3);
    cout << p << endl;
    return 0;
}