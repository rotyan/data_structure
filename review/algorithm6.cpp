//邻接表的DFS遍历
#include<cstdio>
const int MAX = 1000;
const int INF = 10000000;

int n;  //n为顶点数，MAX为最大顶点数
bool vis[MAX] = {false};

// DFS(){
//     vis[u] = true;  //令u设置为已经访问
//     for (枚举能从u出发到达的所有顶点v) {
//         if (vis[v] = flase) {
//             DFS(v);
//         }
//     }
// }

// DFSTrave(G) {   //遍历图G
//     for (G的所有顶点) {
//         if (vis[v] = flase) {
//             DFS(v);
//         }
//     }
// }

#include <vector>
using namespace std;
vector<int> Adj[MAX];

void DFS(int u, int depth){ //u为当前要访问的顶点标号，depth为深度
    vis[u] = true;  //令u设置为已经访问
    for (int i = 0; i < Adj[u].size(); i++) {   //对u访问所有可以到达的顶点v
        int v = Adj[u][i];
        if (vis[v] = false) {
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave() {   //遍历图G
    for (int u = 0; u < n; u++) {   //对于每个顶点u
        if (vis[u] = false) {   //如果u没有被访问过
            DFS(u, 1);  //访问u和u所在的连通块
        }
    }
}