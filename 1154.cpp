#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int n,m;
int mod=1e9+7;
char s[20000];
bool check(int l){
	//frequency 
	unordered_map<lli,int> f;
	//hash
	lli hash=0;
	lli smod=1;
	for(int i=0;i<l;++i){
		hash*=mod;
		hash+=s[i];
		if(i>0) smod*=mod;
	}
	for(int i=l-1;i<n;++i){
		if(i>l-1){
			hash-=(s[i-l]*smod);
			hash*=mod;
			hash+=s[i];
		}
		++f[hash];
		if(f[hash]>=m) return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
}
