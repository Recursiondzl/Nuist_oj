
#include <stdio.h>
#include <string.h>
#define max(x,y)	((x) > (y) ? (x) : (y))

int n,m;
int from[1004],to[1004];
int first[1004],edge[1004];
int maxlen[1004];

int dfs(int n){
	if(first[n] == -1)	return 1;
	if(maxlen[n] != -1)	return maxlen[n];
	int ans = 1,e1 = first[n];
	while(e1 != -1){
		ans = max(ans,dfs(to[e1])+1);
		e1 = edge[e1];
	}
	return maxlen[n] = ans;
}


int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		int a,b, res = -1;
		memset(first,-1,sizeof(first));
		memset(maxlen,-1,sizeof(maxlen));
		for(int i = 1; i <= m; ++i){
			scanf("%d%d",&a,&b);
			from[i] = a, to[i] = b;
			edge[i] = first[a];
			first[a] = i;
		}
		for(int i = 1; i <= n; ++i)
			res = max(res,dfs(i));
		printf("%d\n",res);
	}
	return 0;
}