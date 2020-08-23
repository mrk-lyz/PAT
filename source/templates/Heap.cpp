#include <bits/stdc++.h>

using namespace std;
const int maxn = 100;

int n;              // 当前堆的个数
int heap[maxn];     // 下标从1开始有意义

// 向下调整，范围为[low, high]，low为欲调整节点，high一般为尾元素下标
void filterDown(int low, int high) {
    int i = low, j = 2 * low;   // i是预调整节点，j是左孩子
    while (j <= high) {         // 存在孩子节点
        // 如果右孩子存在，且右孩子的值大于左孩子
        if (j + 1 < high && heap[j + 1] > heap[j]) {
            j++;    // j为右孩子下标
        }
        // 如果孩子中的最大值比欲调整节点权值大
        if (heap[j] > heap[i]) {
            int temp = heap[j];
            heap[j] = heap[i];
            heap[i] = temp;
            i = j;          // 更新i为下一个待调整节点，j为左孩子
            j = i * 2;
        } else {
            break;
        }
    }
}
void filterUp(int n, int data) {

}
// 添加元素，先在末尾添加，再进行一次向上调整
void insert(int data) {
    heap[++n] = data;
    filterUp(1, n);
}

int main() {
    cin >> n;
    int m;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        insert(m);
    }

    return 0;
}