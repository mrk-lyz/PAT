/*
1032 Sharing (25分)
To store English words, one method is to use linked lists and store a word letter by letter.
To save some space, we may let the words share the same sublist if they share the same suffix.
For example, loading and being are stored as showed in Figure 1.

Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890

Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    int next;
    bool flag;
} p[100000];

int main() {
    int addr1, addr2, n;
    cin >> addr1 >> addr2 >> n;
    for (int i = 0; i < n; ++i) {
        int addr, next;
        char data;
        cin >> addr >> data >> next;
        p[addr].data = data;
        p[addr].next = next;
        p[addr].flag = false;
    }
    int start = addr1;
    while (start != -1) {
        p[start].flag = true;
        start = p[start].next;
    }
    start = addr2;
    while (start != -1) {
        if (p[start].flag) {
            cout << setw(5) << setfill('0') << start;
            return 0;
        }
        start = p[start].next;
    }
    cout << -1;
    return 0;
}