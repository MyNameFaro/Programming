#include <bits/stdc++.h>
using namespace std;
using lli=long long;
int N;
int x[500010],y[500010],p[500010];
lli compute(int X,int Y){
	lli total=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=p[i];++j){
			total+=abs(X-x[i]);
			total+=abs(Y-y[i]);
		}
	}
	return total;
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d%d%d",&x[i],&y[i],&p[i]);
	int X=2e9;int Y=2e9;
	int l=0,r=1e9;
	while(l<=r){
		int mid=(l+r)/2;
		if(compute(mid,0)<compute(mid+1,0)){
			X=min(X,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	l=0;r=1e9;
	while(l<=r){
		int mid=(l+r)/2;
		if(compute(0,mid)<compute(0,mid+1)){
			Y=min(Y,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%lld",compute(X,Y));
}
