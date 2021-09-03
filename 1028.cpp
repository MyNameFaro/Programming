#include <bits/stdc++.h>

#define W second
#define V first
#define PRE 0
#define NEX 1



int N , M ,Q;
using namespace std;

vector <vector <pair <int ,int>>> g;
vector <pair <int ,int>> node , free_node;

vector <int> ans;

void gs(){
	int x,i;
	int cnt = 0;
	ans.push_back(0);
	for(x = 1;x <= N;++x){
		node = g[x];
		//cout << node[NEX].W << " ";
		if(node[NEX].W == 0){
			++cnt;
			//cout << cnt << " ";
		}else{
			++cnt;
			
			for(i = 0;i < cnt;i++){
				ans.push_back(cnt);
			}
			//cout << cnt << " ";
			cnt = 0;
		}
		
	}
}

int main(){
	
	int a , k , x;
	int n , m ,q , i;
	scanf("%d %d %d",&N ,&M ,&Q);
	
	g.assign(N + 1,free_node);
	
	g[1].push_back({-1 , 5});
	g[1].push_back({2, 0});
	for(n = 2;n < N;++n){
		g[n].push_back({n - 1 ,0});
		g[n].push_back({n + 1 ,0});
	}
	
	g[N].push_back({N - 1, 0});
	g[N].push_back({-1 , 5});
	for(m = 1;m <= M;++m){
		scanf("%d %d",&a ,&k);
		//START
		if(a != 1){
			g[a - 1][NEX].W = (g[a - 1][NEX].W + 1) % 2;
			g[a][PRE].W = g[a - 1][NEX].W;
		}
		//FINISH
		if(a + k - 1 != N){
			g[a + k - 1][NEX].W = (g[a + k - 1][NEX].W + 1) % 2;
			g[a + k][PRE].W = g[a + k - 1][NEX].W;
		}
		
		
	}
	gs();

	for(q = 1;q <= Q;++q){
		scanf("%d",&x);
		
		printf("%d\n",ans[x]);
	}
	
}
