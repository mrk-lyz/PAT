/*
1011 World Cup Betting (20分)

Sample Input:
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1
Sample Output:
T T W 39.31

*/

#include <bits/stdc++.h>

const int maxn = 3;
struct Game {
    double w;
    double t;
    double l;
} game[maxn];

using namespace std;

double maxWeight[maxn];
char status[maxn];
double maxProfile = 0.65;

int main() {
    for (int i = 0; i < maxn; ++i) {
        cin >> game[i].w >> game[i].t >> game[i].l;
        maxWeight[i] = max(game[i].w, max(game[i].t, game[i].l));
        if (maxWeight[i] == game[i].w) {
            status[i] = 'W';
        } else if (maxWeight[i] == game[i].t) {
            status[i] = 'T';
        } else {
            status[i] = 'L';
        }
        maxProfile *= maxWeight[i];
    }
    maxProfile = (maxProfile - 1) * 2;
    for (auto i : status) {
        cout << i << " ";
    }
    cout << fixed << setprecision(2) << maxProfile;
    return 0;
}