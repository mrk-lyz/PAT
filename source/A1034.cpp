/*
1034 Head of a Gang (30分)
One way that the police finds the head of a gang is to check people's phone calls.
 If there is a phone call between A and B, we say that A and B is related.
 The weight of a relation is defined to be the total time length of all the phone calls made between the two persons.
 A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K.
 In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3

Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * 因读入的边可能有重复(A->B and B->A)，采用邻接矩阵会比较方便
 * */

const int maxn = 2020;
const int INF = 100000000;

map<int, string> intToString;       // 编号->姓名
map<string, int> stringToInt;       // 姓名->编号
map<string, int> gang;              // head->人数


int g[maxn][maxn] = {};         // 邻接表
int weight[maxn] = {};          // 点权
int n, k;                       // 边数，阈值
int numPerson = 0;              // 人数（节点数）
bool visited[maxn] = {false};   // 访问标志

int strToInt(const string &name) {
    if (stringToInt.find(name) != stringToInt.end()) {    // name已经出现过
        return stringToInt[name];
    } else {
        stringToInt[name] = numPerson;  // 设置当前name的编号为numPerson
        intToString[numPerson] = name;
        return numPerson++;
    }
}

bool cmp(int u, int v) {
    return weight[u] > weight[v];
}

// 遍历连通分量的所有路径
void DFS(int u, vector<int> &v, int &totalWeight) {
    v.push_back(u);
    visited[u] = true;      // 设置该节点已经被访问
    for (int i = 0; i < numPerson; ++i) {
        if(g[u][i]>0) {     // 如果u->i的边存在
            totalWeight += g[u][i];     // totalWeight加上当前边权值
            g[i][u] = g[u][i] = 0;      // 重要语句，因为图中可能有环，为了避免重复累加，应清空遍历过的路径
            if(!visited[i]) {
                DFS(i, v, totalWeight);     // 如果该点没有被访问过，继续迭代访问
            }
        }
    }
}

// 深搜
void DFSTraverse() {
    for (int i = 0; i < numPerson; ++i) {
        if (!visited[i]) {   // 如果没有访问过该节点
            vector<int> member;
            int totalWeight = 0;     // 使用引用方式实现数值传递，由于head也是动态变化的
            DFS(i, member, totalWeight);
            if (member.size() > 2 && totalWeight > k) {
                sort(member.begin(), member.end(), cmp);        // 按照点权大小排序
                gang[intToString[member[0]]] = member.size();   // 将连通分量的head和人数记录到gang内
            }
        }
    }
}

int main() {
    cin >> n >> k;
    int w;
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2 >> w;       // 读入各边端点和权值
        int k1 = strToInt(s1);
        int k2 = strToInt(s2);
        weight[k1] += w;
        weight[k2] += w;
        g[k1][k2] += w;
        g[k2][k1] += w;
    }
    DFSTraverse();
    cout << gang.size() << endl;
    for (auto & it : gang) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}