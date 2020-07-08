/*
1008 Elevator (20分)
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Sample Input:
3 2 3 1
Sample Output:
41
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    int time = 0;       // 总耗时
    int n;              // 请求个数
    cin >> n;
    int *p = new int[n + 1];
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] > p[i - 1]) {
            time += 6 * (p[i] - p[i - 1]);
        } else {
            time += 4 * (p[i - 1] - p[i]);
        }
    }
    time += 5 * n;
    cout << time;
    delete[] p;
    return 0;
}
