/*
 * @Description: To iterate is human, to recurse divine.
 * @Autor: Recursion
 * @Date: 2022-06-03 15:38:50
 * @LastEditTime: 2022-06-03 16:03:04
 */
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;
const int N = 2e4 + 7;
int f[N];
int T,M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> M >> T){
        memset(f,0,sizeof(f));
        int w[N];
        int v[N];
        for(int i = 1;i <= M;i ++){
            cin >> v[i] >> w[i];
        }

        for(int i = 1;i <= M;i ++){
            for(int j = v[i];j <= T;j ++){
                f[j] = max(f[j],f[j - v[i]] + w[i]);
                
            }
        }
        cout << f[T] << endl;
    }


    return 0;
}