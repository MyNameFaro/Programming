#include <bits/stdc++.h>
using namespace std;

int main(){
	int n , m;
	scanf("%d %d",&n ,&m);
	vector <int> M (m + 1,0);
	vector <int> P (n + 1,0);
	vector <int> W (m + 1,0);
	int total = 0;
	queue <int> Q;
	priority_queue <int , vector<int> ,greater<int>> PQ;
	for(int i = 1;i <= n;++i) scanf("%d",&P[i]);
	for(int i = 1;i <= m;++i) scanf("%d",&W[i]);
	for(int i = 1;i <= n;++i) PQ.push(i);
	int x;
	for(int i = 1;i <= 2*m;++i){
		scanf("%d",&x);
		if(x > 0){
			Q.push(x);
			if(!PQ.empty() && !Q.empty()){
				M[Q.front()] = PQ.top();
				total += (P[M[Q.front()]] * W[Q.front()]);
				PQ.pop();Q.pop();
			}
		}else{
			PQ.push(M[abs(x)]);
			M[abs(x)] = 0;
			if(!PQ.empty() && !Q.empty()){
				M[Q.front()] = PQ.top();
				total += (P[M[Q.front()]] * W[Q.front()]);
				PQ.pop();Q.pop();
			}
		}
	}
	printf("%d",total);
}
