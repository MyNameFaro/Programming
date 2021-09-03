#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int arr[n];
	int ans=0;
	int min_k=2e9,max_k=-1;
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
		if(arr[i]==k){
			min_k=min(min_k,i);
			max_k=max(max_k,i);
		}
	} 
	for(int i=0;i<=max_k;++i){
		for(int j=min(i,min_k);j<n;j+=2){
			int arrv[n];
			for(int k=i;k<=j;++k) arrv[k]=arr[k];
			sort(arrv+i,arrv+j+1);
			int med=(i+j)/2;
			if(arrv[med]==k){
				for(int l=i;l<=j;++l){
					printf("%d ",arr[l]);
				}
				printf("\n");
				++ans;
			} 
		}
	}
	printf("%d",ans);
}
