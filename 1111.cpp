#include <bits/stdc++.h>
#define V first
#define W second
using namespace std;

vector <vector <pair <int , int>> > g;
vector <pair <int , int>> init; 
vector<int> t;

int ans = -2e9;

void bfs(int x){
	queue <int> q;
	int node = x;
	int i;
	q.push(x);
	while(!q.empty()){
		node = q.front();
		q.pop();
		for(i = 0;i < g[node].size();++i){
			if(t[g[node][i].V] == 0){
				q.push(g[node][i].V);
				t[g[node][i].V] = t[node] + g[node][i].W;
				ans = max(ans , t[g[node][i].V]);
			}
		}
	}
}

int main(){
	int n;
	int i , j;
	int x , y ,z;
	//INIT
	scanf("%d",&n);
	for(i = 0;i <= n;++i){
		g.push_back(init);
		t.push_back(0);
	}
	for(i = 1;i <= n - 1;++i){
		scanf("%d %d %d",&x ,&y ,&z);
		g[x].push_back({y , z});
	}
	bfs(1);
	
	/*for(i = 1;i <= n;++i){
		ans = max(ans , t[i]);
	}*/
	printf("%d",ans);
}
