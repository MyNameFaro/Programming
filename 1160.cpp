#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int,int>;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main(){
	int n,m;
	int rs,cs,rf,cf;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&rs,&cs);
	scanf("%d%d",&rf,&cf);
	int dis[n+1][m+1][2] , G[n+1][m+1];
	bool visited[n+1][m+1];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			dis[i][j][0]=2e9;
			dis[i][j][1]=2e9;
			visited[i][j]=false;
			scanf("%d",&G[i][j]);
		} 
	}
	
	bool visiteds[n+1][m+1][2];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			visiteds[i][j][0]=false;
			visiteds[i][j][1]=false;
		}
	}
	priority_queue<tll,vector<tll>,greater<tll>> PQ;
	dis[rs][cs][1]=1;
	PQ.emplace(dis[rs][cs][1],rs,cs,1);
	while(!PQ.empty()){
		int r=get<1>(PQ.top());
		int c=get<2>(PQ.top());
		int s=get<3>(PQ.top());PQ.pop();
		if(visiteds[r][c][s]) continue;
		visiteds[r][c][s]=true;
		if(r==rf and c==cf){
			break;	
		}
		for(int i=0;i<4;++i){
			int rr=r+dx[i];
			int cc=c+dy[i];
			if((rr<=0 or cc<=0 or rr>n or cc>m)) continue;
			if(!visiteds[rr][cc][0] and G[rr][cc]==0 and s==1 and dis[rr][cc][0]>dis[r][c][s]+1){
				dis[rr][cc][0]=dis[r][c][s]+1;
				PQ.emplace(dis[rr][cc][0],rr,cc,0);
			}else if(!visiteds[rr][cc][s] and dis[rr][cc][s]>dis[r][c][s]+1 and G[rr][cc]==1){
				dis[rr][cc][s]=dis[r][c][s]+1;
				PQ.emplace(dis[rr][cc][s],rr,cc,s);
			}
		}
	}
	queue <tll> Q;
	visited[rs][cs]=true;
	visited[rf][cf]=true;
	G[rs][cs]=2;
	G[rf][cf]=3;
	Q.emplace(1,rs,cs,2);
	Q.emplace(1,rf,cf,3);
	while(!Q.empty()){
		int r=get<1>(Q.front());
		int c=get<2>(Q.front());
		int mark=get<3>(Q.front());Q.pop();
		for(int i=0;i<4;++i){
			int rr=r+dx[i];
			int cc=c+dy[i];
			if(visited[rr][cc] or (rr<=0 or cc<=0 or rr>n or cc>m)) continue;
			if(G[rr][cc]==1){
				visited[rr][cc]=true;
				G[rr][cc]=mark;
				Q.emplace(1,rr,cc,mark);
			}
		}
	}
	int ans1 = min(dis[rf][cf][0],dis[rf][cf][1]);
	int ans2 = 0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(G[i][j]!=0) continue;
			bool have2=false,have3=false;
			for(int k=0;k<4;++k){
				int rr=i+dx[k];
				int cc=j+dy[k];
				if((rr<=0 or cc<=0 or rr>n or cc>m)) continue;
				if(G[rr][cc]==2) have2=true;
				if(G[rr][cc]==3) have3=true;
			}
			if(have2 and have3) ++ans2;	
		}
	}
	printf("%d\n%d",ans2,ans1);
}
