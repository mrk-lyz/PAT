#include <bits/stdc++.h>

using namespace std;
const int maxn = 100;

int n;              // 当前堆的个数
int heap[maxn];     // 下标从1开始有意义

// 向下调整，范围为[low, high]，low为欲调整节点，high一般为尾元素下标
void filterDown(int low, int high) {
    int i = low, j = 2 * low;   // i是预调整节点，j是其左孩子
    while (j <= high) {         // 存在孩子节点
        // 如果右孩子存在，且右孩子的值大于左孩子
        if (j + 1 <= high && heap[j + 1] > heap[j]) {
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

// 初始化堆
void createHeap() {
    for (int i = n / 2; i >= 1; --i) {
        filterDown(i, n);
    }
}

// 删除堆顶元素
void deleteHeap() {
    heap[1] = heap[n--];        // 用尾元素代替堆顶元素
    filterDown(1, n);       // 向下调整
}

void filterUp(int low, int high) {
    int i = high, j = high / 2;   // i是预调整节点，j是其父亲
    while (j >= low) {         // 存在父亲
        // 如果父节点权值小于欲调整节点权值
        if (heap[j] < heap[i]) {
            int temp = heap[j];
            heap[j] = heap[i];
            heap[i] = temp;
            i = j;          // 更新i为下一个待调整节点
            j = i / 2;      // j为对应子节点
        } else {
            break;
        }
    }
}

// 添加元素，先在末尾添加，再进行一次向上调整
void insertHeap(int data) {
    heap[++n] = data;
    filterUp(1, n);
}

// 堆排序
void heapSort() {
    createHeap();
    for (int i = n; i > 1; --i) {
        int temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;
        filterDown(1, i-1);
    }

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> heap[i];
    }
    createHeap();
    for (int i = 1; i <= n; ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
    int m;
    cin >> m;
    insertHeap(m);
    for (int i = 1; i <= n; ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
    heapSort();
    for (int i = 1; i <= n; ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
    return 0;
}