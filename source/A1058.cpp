/*
1058 A+B in Hogwarts (20 分)

Sample Input 1:
3.2.1 10.16.27
Sample Output :
14.1.28
*/

/*
 * 结构体加法
 * */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
const int INF = 100000000;

struct Currency {
    int galleon;
    int sickle;
    int knut;

    Currency() {
        galleon = 0;
        sickle = 0;
        knut = 0;
    }
    void show() const {
        cout << galleon << "." << sickle << "." << knut;
    }
};

void change(Currency &c, string &s) {
    int lDot = s.find('.');
    c.galleon = stoi(s.substr(0, lDot));
    int rDot = s.rfind('.');
    c.sickle = stoi(s.substr(lDot + 1, rDot));
    c.knut = stoi(s.substr(rDot + 1));
}

Currency add(const Currency &a, const Currency &b) {
    Currency res;
    int carry = 0;
    res.knut = a.knut + b.knut;
    if (res.knut >= 29) {
        carry++;
        res.knut = res.knut % 29;
    }
    res.sickle = a.sickle + b.sickle + carry;
    carry = 0;
    if (res.sickle >= 17) {
        carry++;
        res.sickle = res.sickle % 17;
    }
    res.galleon = a.galleon + b.galleon + carry;
    return res;
}

string a, b;
Currency x, y;

int main() {
    cin >> a >> b;
    change(x, a);
    change(y, b);
    Currency res = add(x, y);
    res.show();
    return 0;
}

