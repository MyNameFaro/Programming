#include<bits/stdc++.h>
using namespace std;
using lli = long long;
lli DP[1000000];
int main(){
	int n;
	lli k;
	scanf("%d%lld",&n,&k);
	lli qs[n+1];
	qs[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&qs[i]);
		qs[i]+=qs[i-1];
	}
	deque <int> deq;
	deq.push_back(0);
	//cout << "HEY";
	for(int i=1;i<=n;++i){
		while(!deq.empty() and -qs[deq.back()]+DP[max(deq.back()-1,0)]<-qs[i]+DP[i-1]){
			deq.pop_back();
		}
		deq.push_back(i);
		while(!deq.empty() and qs[i]-qs[deq.front()]>k){
			deq.pop_front();
		}
		//cout << "A";
		DP[i]=qs[i]-qs[deq.front()];
		//cout << "B";
		DP[i]+=DP[max(0 , deq.front()-1)];
		
		
	}
	printf("%lld",DP[n]);
}
