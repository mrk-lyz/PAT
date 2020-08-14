/*
1052 Linked List Sorting (25分)
A linked list consists of a series of structures, which are not necessarily adjacent in memory.
We assume that each structure contains an integer key and a Next pointer to the next structure.
Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100001;
struct Node {
    int addr;
    int data;
    int next;
    bool flag;
} p[maxn];

bool cmp(const Node &n1, const Node &n2) {
    return n1.data < n2.data;
}

int main() {
    int n, start;
    cin >> n >> start;
    for (int i = 0; i < n; ++i) {
        int addr, data, next;
        scanf("%d %d %d", &addr, &data, &next);     // 使用cin会超时
        p[addr].addr = addr;
        p[addr].data = data;
        p[addr].next = next;
    }
    int temp = start;
    int count = 0;
    vector<Node> v;

    while (temp!=-1) {
        count ++;
        v.push_back(p[temp]);
        temp = p[temp].next;
    }
    if (count==0) {         // start=-1时特判，题目已经保证在非空情况下，start必在之前出现过
        cout << "0 -1" << endl;
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    cout << count << " " << setfill('0') << setw(5) << v[0].addr << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << setfill('0') << setw(5) << v[i].addr << " " << v[i].data << " ";
        if (i<v.size()-1) {
            cout << setfill('0') << setw(5) << v[i+1].addr << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}