#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;
const int N = 1e6;
int dp[N];
int pos[N];
int len[N];
int ans;
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp,0,sizeof(dp));
    memset(pos,0,sizeof(pos));
    memset(len,0,sizeof(len));
    cin >> n >> m;
    ans = 0;
    for(int i = 0 ;i < n;i ++)
        cin >> pos[i] >> len[i];
    if(pos[0]!=0)
        ans += pos[0];
    dp[0] = pos[0] + len[0];

    for(int i = 0;i < n;i ++){
        if(dp[i] < pos[i + 1]){
            ans += pos[i + 1] - dp[i];
            dp[i + 1] = pos[i + 1] + len[i + 1];
        }
        else{
            if(dp[i] < pos[i + 1] + len[i + 1])
                dp[i + 1] = pos[i + 1] + len[i + 1];
            else
                dp[i + 1] = dp[i];
        }
    }
    if(dp[n - 1] < m)
        ans += m - dp[n - 1];
    cout << ans << endl;


    return 0;
}