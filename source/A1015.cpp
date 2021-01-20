/*
1015 Reversible Primes (20分)
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime.
 For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10^5) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

Sample Input:
73 10
23 2
23 10
-2

Sample Output:
Yes
Yes
No
*/

/*
 * 定义“可倒置素数”：原数n与其在d进制下的串逆置所代表的数都为素数
 * */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const int INF = 100000000;

int n, d;

bool isPrime(int num) {         // 判断是否为素数
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    while (cin >> n) {
        if (n < 0) {
            break;
        }
        cin >> d;
        int origin_number = n;
        vector<int> v;      // 存放进制转换中间串
        while (n != 0) {
            v.push_back(n % d);
            n = n / d;
        }
        int reverse_number = 0;
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            reverse_number = reverse_number + v[i] * pow(d, i);
        }
        if (origin_number == 1 || reverse_number == 1) {
            cout << "No" << endl;
        } else if (isPrime(origin_number) && isPrime(reverse_number)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

