//邻接表建立无向图【没写，书上太复杂】//有待进一步学习//水+1
#include<cstdio>
const int MAX = 1000;
const int INF = 10000000;

#include <vector>
using namespace std;
vector<int> Adj[MAX];

struct Node{
    int v;  //边的终点编号
    int w;  //边权
    Node(int _v, int _w) : v(_v),w(_w) {}   //构造函数
};
