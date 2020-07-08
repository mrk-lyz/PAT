/*
1002 A+B for Polynomials (25分)
This time, you are supposed to find A+B where A and B are two polynomials.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 2 1.5 1 2.9 0 3.2
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1001
int main()
{
    int x, y, count = 0;
    int e;
    double n;
    double exp[MAX_SIZE] ={};
    cin >> x;
    for (int i=0; i<x; i++){
        cin >> e;
        cin >> n;
        exp[e] = n;
    }
    cin >> y;
    for (int i=0; i<y; i++){
        cin >> e;
        cin >> n;
        exp[e] += n;

    }
    int temp = 0;
    for (int i=0; i<MAX_SIZE; i++){
        if (exp[i]!=0){
            count++;
        }
    }
    cout << count;
    for (int i=MAX_SIZE-1; i>=0; i--){
        if (exp[i]!=0.00){
            cout << " " << i << " " << fixed << setprecision(1) << exp[i];
            temp++;
            if (temp>=count)
                break;
        }
    }
    return 0;
}

