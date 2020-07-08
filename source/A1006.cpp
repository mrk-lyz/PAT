/*
1006 Sign In and Sign Out (25分)
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
*/

#include <bits/stdc++.h>

using namespace std;

struct Record {
    string id;
    string sign_in_time;
    string sign_out_time;
};

bool cmp1(const Record &r1, const Record &r2) {
    return r1.sign_in_time<r2.sign_in_time;
}

bool cmp2(const Record &r1, const Record &r2) {
    return r1.sign_out_time>r2.sign_out_time;
}
int main() {
    int n;
    cin >> n;
    auto *r = new Record[n];
    for (int i = 0; i < n; ++i) {
        cin >> r[i].id >> r[i].sign_in_time >> r[i].sign_out_time;
    }
    sort(r, r + n, cmp1);
    cout << r[0].id << " ";
    sort(r, r + n, cmp2);
    cout << r[0].id;
    delete[] r;
    return 0;
}
