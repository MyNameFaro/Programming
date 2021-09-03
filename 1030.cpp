#include <bits/stdc++.h>
using namespace std;
using pii = pair<double , int>;
int main(){
	int K;
	scanf("%d",&K);
	vector <int> P (K + 1,0) , Q (K + 1,0);
	priority_queue <pii , vector<pii> , greater<pii>> PQ;
	for(int i = 1;i <= K;++i){
		scanf("%d %d",&P[i] ,&Q[i]);
		PQ.push({(double)( (double)P[i] / (double) Q[i] ) , i});
	}
	int M;scanf("%d",&M);
	int x;
	for(int r = 1;r <= M;++r){
		scanf("%d",&x);
		double p = 0.0;int q = 0;
		while(q < x){
			int i = PQ.top().second;
			if(q + Q[i] > x){
				p = p + (double)((double)(x - q) * PQ.top().first);
				Q[i] -= x - q;
				q = x;
			}else{
				p = p + (double)((double)Q[i] * PQ.top().first);
				q += Q[i];
				Q[i] = 0;
				PQ.pop();
			}
		}
		printf("%.3f\n",p);
	}
}
