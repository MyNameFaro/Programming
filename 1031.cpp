#include <bits/stdc++.h>
using namespace std;

int visit[10002];
vector <int> g[10002];

int mx = 1;

void bfs(int k){
	queue <int> q;
	q.push(1);
	visit[1] = k;
	int i , node;
	while(!q.empty()){
		node = q.front();
		mx = max(mx , node);
		q.pop();
		if(visit[node]> 0){
			for(i = 0;i < g[node].size();i++){
				if(visit[g[node][i]] == 0){
					q.push(g[node][i]);
					visit[g[node][i]] = visit[node] - 1;
				}
			}
		}
		
	}
	

}
int main(){
	int k , n , m;
	int a , b;
	int i;
	scanf("%d %d %d",&k ,&n ,&m);
	for(i = 0;i < m;i++){
		scanf("%d %d",&a ,&b);
		g[a].push_back(b);
	}
	bfs(k);
	printf("%d",mx);
}
