/*
1060 Are They Equal (25分)
Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5

Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/

#include <bits/stdc++.h>

using namespace std;

string strFormat(string s, int n) {
    int ex = 0;         // 指数
    int dot_pos = s.find('.', 0);   // 查找小数点索引
    if (dot_pos != -1) {  // 存在小数点
        // 清除整数部分重复前导0，如0000.128->0.128
        int pre_zero = 0;
        for (int i = 0; i < dot_pos - 1; ++i) {
            if (s[i] != '0') {
                break;
            }
            pre_zero++;
        }
        s = s.substr(pre_zero);

        if (s[0] == '0') {        // 整数部分为0，如0.0000128
            bool isZero = true;
            for (int i = 2; i < s.length(); i++) {    // 清除小数部分前导零，并记录指数
                if (s[i] != '0') {
                    s = s.substr(i);
                    isZero = false;
                    break;
                }
                ex--;
            }
            if (isZero) { // 小数部分全为0
                ex = 0;
                s = "0";
            }
        } else {                // 整数部分不为0，如3.0000128
            ex = s.find('.');      // 指数为小数点所在索引
            s.erase(ex, 1);        // 清除小数点
        }

    } else {        // 只包含整型
        // 清除无用前导0
        int pre_zero = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != '0') {
                break;
            }
            pre_zero++;
        }
        s = s.substr(pre_zero);     // 此时的s已经不带小数点
        if (s!="0") {
            ex = s.length();    // 计算指数
        }   // 如果s=='0'，则ex为初始值0
    }
    while (s.length() < n) {    // 此时s应当为整型，用以生成系数，ex用以生成指数
        s += '0';
    }
    if (s.length() > n) {
        s = s.substr(0, n);
    }
    s = "0." + s + "*10^" + to_string(ex);
    return s;
}

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    string x = strFormat(a, n), y = strFormat(b, n);
    if (x == y) {
        cout << "YES " << x;
    } else {
        cout << "NO " << x << " " << y;
    }
    return 0;
}

/*
 * test case:
 * 4    00100.00000012  100.00000013    YES 0.1000*10^3
 * 4    00123.5678      0001235         No 0.1235*10^3 0.1235*10^4
 * 4    0000            0000.00         YES 0.0000*10^0
 * 4    123.0678        123             YES 0.1230*10^3
 * 3    0.000           0               YES 0.000*10^0
 * 12   123456789012345 123456789012300 YES 0.123456789012*10^15
 * 12   123456789012345 123456789010000 No 0.123456789012*10^15 0.123456789010*10^15
 * 1    0.0             0.1             NO 0.0*10^0 0.1*10^0    !!!
 * */
