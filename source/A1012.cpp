/*
1012 The Best Rank (25分)
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.
Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
 */

/*
 * 方案：多次结构体排序
 * 在最后一次排序时，建立学号到结构体数组序列号的索引
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;
const int INF = 100000000;

struct Student {
    int id;
    int c;
    int m;
    int e;
    double a;
    int rank_c;
    int rank_m;
    int rank_e;
    int rank_a;
} stu[maxn];

int n, m;
int id;
map<int, int> addr2index;       // 根据最后一次排序，建立学生id到地址序列的索引

bool cmp_c(const Student &s1, const Student &s2) {
    return s1.c > s2.c;
}

bool cmp_m(const Student &s1, const Student &s2) {
    return s1.m > s2.m;
}

bool cmp_e(const Student &s1, const Student &s2) {
    return s1.e > s2.e;
}

bool cmp_a(const Student &s1, const Student &s2) {
    return s1.a > s2.a;
}

// 获取索引号为i的同学的最好排名，优先级为A->C->M>E
void getBestRank(int i, int &r, char &c) {
    r = n + 1;
    if (stu[i].rank_e <= r) {
        r = stu[i].rank_e;
        c = 'E';
    }
    if (stu[i].rank_m <= r) {
        r = stu[i].rank_m;
        c = 'M';
    }
    if (stu[i].rank_c <= r) {
        r = stu[i].rank_c;
        c = 'C';
    }
    if (stu[i].rank_a <= r) {
        r = stu[i].rank_a;
        c = 'A';
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
        stu[i].a = (stu[i].c + stu[i].e + stu[i].m) / 3.0;
    }

    // 获取C课的排名
    sort(stu, stu + n, cmp_c);
    stu[0].rank_c = 1;
    for (int i = 1; i < n; i++) {
        if (stu[i].c < stu[i - 1].c) {
            stu[i].rank_c = i + 1;
        } else {
            stu[i].rank_c = stu[i - 1].rank_c;
        }
    }

    // 获取M课的排名
    sort(stu, stu + n, cmp_m);
    stu[0].rank_m = 1;
    for (int i = 1; i < n; i++) {
        if (stu[i].m < stu[i - 1].m) {
            stu[i].rank_m = i + 1;
        } else {
            stu[i].rank_m = stu[i - 1].rank_m;
        }
    }

    // 获取E课的排名
    sort(stu, stu + n, cmp_e);
    stu[0].rank_e = 1;
    for (int i = 1; i < n; i++) {
        if (stu[i].e < stu[i - 1].e) {
            stu[i].rank_e = i + 1;
        } else {
            stu[i].rank_e = stu[i - 1].rank_e;
        }
    }

    // 获取A课的排名
    sort(stu, stu + n, cmp_a);
    stu[0].rank_a = 1;
    addr2index[stu[0].id] = 0;
    for (int i = 1; i < n; i++) {
        if (stu[i].a < stu[i - 1].a) {
            stu[i].rank_a = i + 1;
        } else {
            stu[i].rank_a = stu[i - 1].rank_a;
        }
        addr2index[stu[i].id] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> id;
        auto iter = addr2index.find(id);
        if (iter != addr2index.end()) {
            int r;
            char c;
            getBestRank(iter->second, r, c);
            cout << r << " " << c << endl;
        } else {
            cout << "N/A" << endl;
        }
    }
    return 0;
}
