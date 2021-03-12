/*
1067 Sort with Swap(0, i) (25 分)

Sample Input:
10
3 5 7 2 6 4 9 0 8 1

Sample Output:
9
*/

/*
 * 给定一个序列，构造平衡二叉树，输出该树的根节点元素
 * */
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define INF 100000000

int n;
vector<int> v;
int step = 0;
int correct_num = 0;        // 已按序的数量
int init_pos = 1;           // 记录未就位首址

void Swap(int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    cin >> n;
    int num;
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        v.emplace_back(num);
        if (num==v.size()-1) {
            correct_num++;
        }
    }
    while(correct_num<n) {
        if(v[0]!=0) {       // 首位不为0
            Swap(0, v[0]);
            if (v[0]==0) {
                correct_num+=2;
            } else {
                correct_num++;
            }

        } else {            // 首位为0
            int flag = 0;
            for (int i=init_pos; i<n; i++) {
                if (v[i]!=i){
                    flag = i;
                    init_pos = i;
                    break;
                }
            }
            Swap(0, flag);
            correct_num--;
        }
        step++;
    }
    cout << step;
    return 0;
}
