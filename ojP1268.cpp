#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;

int s[N][N];
int m[N][N];
int ans=0;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int R,C;
int dfs(int x,int y)
{
    if(s[x][y]) 
      return s[x][y];

    s[x][y]=1;

    for(int i=0;i<4;i++){
        
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>0&&xx<=R&&yy>0&&yy<=C&&m[xx][yy]<m[x][y])
        {
            dfs(xx,yy);
            s[x][y]=max(s[x][y],s[xx][yy]+1);
        }
    }
    return s[x][y];
 
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin>>R>>C)
    {

        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                cin>>m[i][j];

        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++){
                ans=max(ans,dfs(i,j));
            }

        cout<<ans<<endl;
    }
    return 0;
}