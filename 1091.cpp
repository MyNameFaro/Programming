#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector <int> g[n + 1]
	int u , v;
	int i , j;
	for(i = 0;i <= n;i++){
		for(j = 0;j <=n ;j++){
			g[i][j] = 0;
		}
	}
	for(i = 0;i < n-1 ;i++){
		scanf("%d%d",&u,&v);
		g[u].push(v);
		g[v].push(u);
	}
	printf("%d",g[1][n]);
}
