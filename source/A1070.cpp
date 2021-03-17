/*
1070 Mooncake (25 分)

Sample Input:
3 200
180 150 100
7.5 7.2 4.5
Sample Output:
9.45
*/

/*
 * 在不超过d的重量下找出利润最大和
 * 直接进行一个序的排
 * */
#include <bits/stdc++.h>

using namespace std;

#define maxn 1010
#define INF 100000000
struct MoonCake{
    double inventory;
    double price;
    double flag;
};
int n;
double d;
MoonCake cake[maxn];
double totalProfit = 0;

bool cmp(const MoonCake &a, const MoonCake &b) {
    return a.flag>b.flag;
}
int main() {
    cin >> n >> d;
    for (int i=0; i<n; i++) {
        cin >> cake[i].inventory;
    }
    for (int i=0; i<n; i++) {
        cin >> cake[i].price;
        cake[i].flag = cake[i].price / cake[i].inventory;
    }
    sort(cake, cake+n, cmp);
    for (int i=0; i<n; i++) {
        if (d>cake[i].inventory) {
            totalProfit += cake[i].price;
            d -= cake[i].inventory;
        } else {
            totalProfit += cake[i].flag*d;
            d = 0;
            break;
        }
    }
    printf("%.2f", totalProfit);
    return 0;
}
