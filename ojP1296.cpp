/*
 * @Description: To iterate is human, to recurse divine.
 * @Autor: Recursion
 * @Date: 2022-06-13 20:22:12
 * @LastEditTime: 2022-06-13 20:35:30
 */
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;
const int N = 1e6;
char a[3001][3001];
int n;

void dfs(int n,int x,int y){
    if(n == 1){
        a[x][y] = 'X';
        return;
    }
    int size = pow(3,n-2);
    dfs(n - 1,x,y);
    dfs(n - 1,x + 2*size,y + 2*size);
    dfs(n - 1,x + size,y + size);
    dfs(n - 1,x + 2*size,y);
    dfs(n - 1,x ,y + 2*size);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n){
        int size = pow(3,n-1);
         for(int i=0;i<=size;i++)
            for(int j=0;j<=size;j++)
            {
                a[i][j]=' ';
            }
        dfs(n,1,1);
        for(int i = 1;i <= size;i ++){
            for(int j = 1;j <= size;j ++){
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << '-' << endl;

    }


    return 0;
}