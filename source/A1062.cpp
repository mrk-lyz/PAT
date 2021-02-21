/*
1062 Talent and Virtue (25 分)
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue.
According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）";
being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）";
being good in neither is a "fool man（愚人）";
yet a fool man is better than a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

/*
 * 用四个独立的vector
 * */

#include <bits/stdc++.h>
#include <utility>

using namespace std;

const int maxn = 100010;
const int INF = 100000000;

struct People {
    string id;
    int virtue;
    int talent;

    People(string &s, int v, int t) {
        id = s;
        virtue = v;
        talent = t;
    }
};

int n;          // total number of people
int num = 0;    // total number of people being ranked
int l;          // the lower bound of the qualified grades
int h;          // the higher line of qualification
vector<People> sage;
vector<People> nobleman;
vector<People> foolman;
vector<People> rest;

bool cmp(const People &a, const People &b) {
    if (a.virtue + a.talent != b.virtue + b.talent)
        return a.virtue + a.talent > b.virtue + b.talent;
    else if (a.virtue!=b.virtue)
        return a.virtue > b.virtue;
    else
        return a.id < b.id;
}

int main() {
    cin >> n >> l >> h;
    string id;
    int v, t;
    for (int i = 0; i < n; i++) {
        cin >> id >> v >> t;
        People people = People(id, v, t);
        if (v>=l && t>= l) {
            if (v >= h && t >= h) {
                sage.emplace_back(people);
            } else if (t < h && v >= h) {
                nobleman.emplace_back(people);
            } else if (t<h && v<h && v>=t) {
                foolman.emplace_back(people);
            } else {
                rest.emplace_back(people);
            }
            num++;
        }

    }
    sort(sage.begin(), sage.end(), cmp);
    sort(nobleman.begin(), nobleman.end(), cmp);
    sort(foolman.begin(), foolman.end(), cmp);
    sort(rest.begin(), rest.end(), cmp);
    cout << num << endl;
    for (auto &item:sage) {
        cout << item.id << " " << item.virtue << " " << item.talent << endl;
    }
    for (auto &item:nobleman) {
        cout << item.id << " " << item.virtue << " " << item.talent << endl;
    }
    for (auto &item:foolman) {
        cout << item.id << " " << item.virtue << " " << item.talent << endl;
    }
    for (auto &item:rest) {
        cout << item.id << " " << item.virtue << " " << item.talent << endl;
    }
}
