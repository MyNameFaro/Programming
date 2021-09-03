#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int arr[N+1],lis[N+1];
	int ans=1;
	lis[0]=-2;
	for(int i=1;i<=N;++i){
		lis[i]=2e9;
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=N;++i){
		int l=1;int r=ans+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(lis[mid]>arr[i] and lis[mid-1]<arr[i]){
				if(mid==ans+1) ++ans;
				lis[mid]=arr[i];
				break;
			}
			if(lis[mid]>arr[i]){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	printf("%d",ans);
}
