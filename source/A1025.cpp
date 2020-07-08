/*
1025 PAT Ranking (25分)
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/

#include <bits/stdc++.h>

using namespace std;
struct testee {
    char reg_num[15];
    int score;
    int final_rank;
    int lo_num;
    int lo_rank;
} t[30010];

bool cmp(testee a, testee b) {
    if (a.score != b.score)
        return a.score > b.score;
    return strcmp(a.reg_num, b.reg_num) < 0;
}

int main() {
    int n, m = 0;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t[m].reg_num >> t[m].score;
            t[m].lo_num = i + 1;
            m++;
        }
        sort(t + m - k, t + m, cmp);
        for (int j = m - k; j < m; j++) {
            if (j == m - k)
                t[j].lo_rank = 1;
            else
                t[j].lo_rank = (t[j].score == t[j - 1].score) ? t[j - 1].lo_rank : (j - m + k + 1);
        }
    }
    sort(t, t + m, cmp);
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        if (i == 0)
            t[i].final_rank = 1;
        else
            t[i].final_rank = (t[i].score == t[i - 1].score) ? t[i - 1].final_rank : (i + 1);
        cout << t[i].reg_num << " " << t[i].final_rank << " " << t[i].lo_num << " " << t[i].lo_rank << endl;
    }
    return 0;
}
