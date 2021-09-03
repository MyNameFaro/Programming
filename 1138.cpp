#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

vector <lli> X;
vector <lli> A;
vector <vector <int>> G;

lli sum;

void bfs(int s){
	queue <int> q;
	q.push(s);
	sum += X[s];X[s] = 0;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v:G[u]){
			if(X[v] > 0){
				sum += X[v];
				X[v] = 0;
				q.push(v);
			}
		}
	}
}


int main(){
	int N;
	lli K , S;
	scanf("%d %lld %lld",&N ,&K ,&S);
	G.assign(N , vector <int>());
	lli x , a;
	for(int i = 0;i < N;++i){
		scanf("%lld %lld",&x ,&a);
		X.push_back(a);
		A.push_back(x);
	}
	
	//INIT GRAPH
	for(int i = 0;i < N;++i){
		for(int j = 0;j < i;++j){
			if(abs(A[i] - A[j]) <= K){
				//G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	for(int i = 0;i < N;++i){
		if(X[i] > 0 && abs(S - A[i]) <= K){
			bfs(i);
		}
	}
	printf("%lld",sum);
}
