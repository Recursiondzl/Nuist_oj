/*
 * @Description: To iterate is human, to recurse divine.
 * @Autor: Recursion
 * @Date: 2022-06-04 20:24:54
 * @LastEditTime: 2022-06-04 20:45:15
 */
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
const int N = 1e6;

int pre[N];
int a[N];
int n;

int find(int x){
    if(pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}
int ans;

int pow(int n) {
	int ans=1,base=2;
	for(int i=1;i<=n;++i) {
		ans=(ans*base)%mod;
	}
	return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(a,0,sizeof(a));
    memset(pre,0,sizeof(pre));

    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        pre[i] = i;
    }
    for(int i = 1;i <= n;i++){
        int u = find(i);
        int v = find(a[i]);
        if(u != v)
            pre[u] = v;
    }

    for(int i = 1;i <= n;i ++){
        if(pre[i] == i){
            ans++;
            ans%mod;
        }
    }
    ans = ans%mod;
    cout << pow(ans) - 1 << endl;
    


    return 0;
}