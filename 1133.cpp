#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	int dis[M+1][M+1];
	vector <int> sta[N+1];
	for(int i=0;i<=M;++i){
		for(int j=0;j<=M;++j){
			dis[i][j]=2e9;
			if(i==j) dis[i][j]=0;
		} 
	}
	int u,v,a,b;
	for(u=1;u<=M;++u){
		int S;
		scanf("%d",&S);
		while(S--){
			scanf("%d",&b);
			for(auto v:sta[b]){
				if(u==v) continue;
				dis[u][v]=1;
				dis[v][u]=1;
			}
			sta[b].push_back(u);
		}
	}
	for(int k=1;k<=M;++k){
		for(int i=1;i<=M;++i){
			for(int j=1;j<=M;++j){
				if(dis[i][k]<2e9 and dis[k][j]<2e9 and dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&a,&b);
		int ans=2e9;
		for(int i=0;i<sta[a].size();++i){
			for(int j=0;j<sta[b].size();++j){
				u=sta[a][i];
				v=sta[b][j];
				if(u==v) ans=0;
				ans=min(ans,dis[u][v]);
			}
		}
		if(ans==2e9){
			printf("impossible\n");
			continue;
		}
		printf("%d\n",ans);
	}
}
