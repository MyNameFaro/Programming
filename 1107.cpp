#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[1000010];
pii sarr[1000010];
int n,k,p;
bool check(int next){
	int i=0;
	int cnt_k=0;
	while(i<n){
		if(arr[i]>arr[next]){
				i+=p-1;
				++cnt_k;
		}
		++i;
	}
	return cnt_k<=k;
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
		sarr[i].first=arr[i];
		sarr[i].second=i;
	}
	sort(sarr,sarr+n);
	
	int l=0,r=n-1;
	int ans=2e9;
	//for(int i=0;i<n;++i){
		//printf("%d : ",arr[i].first);
		//printf("%d\n",check(i));
	//}
	while(l<=r){
		int mid=(l+r)/2;
		//cout << mid << endl;
		if(check(sarr[mid].second)){
			ans=min(ans,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d",sarr[ans].first);
}
