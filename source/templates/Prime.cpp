#include <bits/stdc++.h>

using namespace std;

//#define maxn 100000000
//#define INF 100000000
//
//bool isPrime[maxn + 10];
//int prime_num = 0;
//void getPrime() {
//    for (int i = 2; i <= maxn; ++i) {
//        isPrime[i] = true;
//    }
//    for (int i = 2; i <= maxn; i++) {
//        if (isPrime[i])
//            for (int j = 2 * i; j <= maxn; j += i)
//                isPrime[j] = false;
//    }
//
//    for(int i = 2; i <= maxn; i++){
//        if(isPrime[i])
//            prime_num++;
////            cout << i << endl;
//    }
//    cout << prime_num;
//}
//
//int main() {
//    getPrime();
//    return 0;
//}


#define maxn 100000010
bool visit[maxn];
vector<int> prime;  // 存放素数
int n;              // 寻找的素数范围

void getPrime() {
    fill(visit, visit + maxn, false);
    for (int i = 2; i <= n; ++i) {
        if (!visit[i])          // i号未访问，是素数
            prime.emplace_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            visit[i * prime[j]] = true;     // 访问过表示该位置为合数
            if (i % prime[j] == 0)
                break;
        }
    }
    cout << prime.size() <<  endl;
}

int main() {
    cin >> n;
    getPrime();
    for (auto &item:prime) {
        cout << item << " ";
    }
    return 0;
}
