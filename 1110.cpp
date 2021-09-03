#include <bits/stdc++.h>
using namespace std;
using lli=long long;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	lli arr[n+1];
	lli ans=0;
	int med=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&arr[i]);
		if(arr[i]>k){
			arr[i]=1;
		}else if(arr[i]<k){
			arr[i]=-1;
		}else{
			arr[i]=0;
			med=i;
		}
	}
	unordered_map <int,lli> cntleft,cntright;
	set<int> right;
	int sum=0;
	for(int i=med-1;i>=1;--i){
		sum+=arr[i];
		++cntleft[sum];
	}
	sum=0;
	for(int i=med+1;i<=n;++i){
		sum+=arr[i];
		++cntright[sum];
		right.insert(sum);
	}
	for(auto s:right){
		if(s==0) continue;
		if(cntleft.count(-1*s)>0) ans+=(cntleft[-1*s]*cntright[s]);
	}
	ans+=((++cntleft[0])*(++cntright[0]));
	printf("%lld",ans);
}
