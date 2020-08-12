/*
1007 Maximum Subsequence Sum (25分)
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21

Sample Output:
10 1 4
 */

/*
 * 一维dp：
 * c[j]表示p[1]-p[j]中包含j的最大子段和
 * 递推方程：c[j] = max{c[j-1]+p[j], p[j]}
 * */
#include <bits/stdc++.h>

using namespace std;

struct Record{
    int sum;
    int start;
    int end;
};
int main() {
    int n;
    cin >> n;
    int *p = new int[n+1];
    auto * c = new Record [n+1];

    bool isNegative =true;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        if (p[i]>=0) {
            isNegative = false;
        }
    }
    if (isNegative) {
        cout << "0 " << p[1] << " " << p[n];
        return 0;
    }
    c[1].sum = p[1];
    c[1].start = 1;
    c[1].end = 1;
    for (int j=2; j<=n; j++) {
        Record tmp = c[j-1];
        tmp.sum+=p[j];
        tmp.end = j;
        if (p[j]>tmp.sum) {
            tmp.sum = p[j];
            tmp.start = j;
        }
        c[j] = tmp;
    }

    Record res = c[1];
    for (int j = 1; j <= n; ++j) {
        if (c[j].sum>res.sum) {
            res = c[j];
        }
    }
    cout << res.sum << " " << p[res.start] << " " << p[res.end];
    delete[] p;
    delete []c;
    return 0;
}

/*
 * 二维dp：较为笨重，求解数目多
 * c[i][j]表示p[i]-p[j]中包含j的最大子段和
 * 递推方程：c[i][j] = max{c[i][j-1]+p[j], c[i+1][j]}
 * */
//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct Record{
//    int sum;
//    int start;
//    int end;
//};
//int main() {
//    int n;
//    cin >> n;
//    int *p = new int[n+1];
//    auto ** c = new Record *[n+1];
//    for (int i=0; i<=n; i++) {
//        c[i] = new Record[n+1];
//    }
//    bool isNegative =true;
//    for (int i=1; i<=n; i++) {
//        cin >> p[i];
//        if (p[i]>=0) {
//            isNegative = false;
//        }
//    }
//    if (isNegative) {
//        cout << "0 " << p[1] << " " << p[n];
//        return 0;
//    }
//    for (int j=1; j<=n; j++) {
//        for (int i=j; i>=1; i--) {
//            if (j==i) {
//                c[i][j].sum = p[i];
//                c[i][j].start = i;
//                c[i][j].end = i;
//            } else {
//                Record tmp = c[i][j-1];
////                for(int k=i; k<j; k++) {
////                    if (c[k][j-1].sum>tmp.sum) {
////                        tmp = c[k][j-1];
////                    }
////                }
//                tmp.sum += p[j];
//                tmp.end = j;
//                if (c[i+1][j].sum>tmp.sum) {
//                    tmp = c[i+1][j];
//                }
//                c[i][j] = tmp;
//
//            }
//        }
//    }
////    for (int i=1; i<=n; i++) {
////        for (int j=i; j<=n; j++) {
////            cout << '(' << c[i][j].sum << ", " << c[i][j].start << ", " << c[i][j].end << ") ";
////        }
////        cout << endl;
////    }
//    Record res = c[1][1];
//    for (int j = 1; j <= n; ++j) {
//        if (c[1][j].sum>res.sum) {
//            res = c[1][j];
//        }
//    }
//    cout << res.sum << " " << p[res.start] << " " << p[res.end];
//    delete[] p;
//    for (int i = 0; i <= n; ++i) {
//        delete[] c[i];
//    }
//    delete []c;
//    return 0;
//}

