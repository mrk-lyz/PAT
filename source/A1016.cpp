/*
1016 Phone Bills (25分)

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

struct Node {
    string name;    // 用户名
    int month;      // 月份
    int d, h, m;    // 日期，时间，分钟
    int time;       // 总分钟数
    bool status;    // online / offline
} bill[maxn];

int n;          // 账单数
int rate[24];   // 各个月份费率
int dayFee = 0; // 一天的通话费用
map<string, vector<Node> > res; // 名字到有效通话记录的映射

double calBillFee(const Node &v) { // 月初到当前时间的通话费用
    double total = (v.d - 1) * dayFee + v.m * rate[v.h];       // 计算“日”与“分”费用
    for (int i = 0; i < v.h; i++) {     // 计算当日“时”费用
        total += rate[i] * 60;
    }
    return total / 100;     // 美分->美元
}

// 以名字为第一关键字升序，时间先后为第二关键字升序
bool cmp(const Node &a, const Node &b) {
    if (a.name != b.name) {
        return a.name < b.name;
    } else {
        return a.time < b.time;
    }
}

int main() {
    for (int &i : rate) {      // 读入月份
        cin >> i;
        dayFee += 60 * i;
    }
    cin >> n;
    string flag;
    for (int i = 0; i < n; ++i) {
        cin >> bill[i].name;
        scanf("%d:%d:%d:%d", &bill[i].month, &bill[i].d, &bill[i].h, &bill[i].m);
        bill[i].time = bill[i].d * 24 * 60 + bill[i].h * 60 + bill[i].m;
        cin >> flag;
        bill[i].status = flag == "on-line";
    }
    sort(bill, bill + n, cmp);
    for (int i = 0; i < n - 1; i++) {
        if (bill[i].name == bill[i + 1].name && bill[i].status && !bill[i + 1].status) {    // 如果i条为on-line，i+1为off-line
            res[bill[i].name].push_back(bill[i]);       // 将开始通话记录加入map的对应人名中
            res[bill[i].name].push_back(bill[i + 1]);   // 将结束通话记录加入map的对应人名中
        }
    }
    // 此时map中每个人的vector<Node>已经保证依次对应
    for (auto &it :res) {
        string name = it.first;
        vector<Node> v = it.second;
        printf("%s %02d\n", name.c_str(), v[0].month);
        double total = 0;
        for (int i = 0; i < v.size() - 1; i += 2) {
            double fee = calBillFee(v[i + 1]) - calBillFee(v[i]); // 计算时间段费用
            total += fee;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", v[i].d, v[i].h, v[i].m, v[i + 1].d, v[i + 1].h,
                   v[i + 1].m, v[i + 1].time - v[i].time, fee);
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}
