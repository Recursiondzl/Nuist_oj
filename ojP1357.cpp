/*
 * @Description: To iterate is human, to recurse divine.
 * @Autor: Recursion
 * @Date: 2022-06-14 09:08:15
 * @LastEditTime: 2022-06-14 09:48:11
 */
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int N = 1e3+10;
int cnt;
int head[N];
int ans[N];
int n,m;
struct node{
    int u;
    int v;
    int next;
}edge[N];

void add(int u,int v){
    edge[++cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int dfs(int n){
    if(head[n] == -1) return 1;
    if(ans[n] != -1) return ans[n];
    int re = 1;
    for(int i = head[n];i != -1;i = edge[i].next){
        re = max(re,dfs(edge[i].v ) + 1);
    }
    ans[n] = re;
    return re;
}

int main(){
    while(cin >> n >> m){
        cnt = 0;
        memset(head,-1,sizeof(head));
        memset(ans,-1,sizeof(ans));
        for(int i = 1;i <= m;i ++){
            int u,v;
            cin >> u >> v;
            add(u,v);
        }
        int res = 0;
        for(int i = 1;i <= n;i ++)
            res = max(dfs(i),res);
        cout << res << endl;

    //    for (int i = 1; i <= n; i++)//n个起点
    //     {
    //         cout << i << endl;
    //         for (int j = head[i]; j != -1; j = edge[j].next)//遍历以i为起点的边
    //         {
    //             cout << i << " " << edge[j].v  << endl;
    //         }
    //         cout << endl;
    //     }
    }
    return 0;
}