#include<bits/stdc++.h>
using namespace std;

int DP[2004][2004];

int main(){
	int n;
	scanf("%d",&n);
	int arr[n+2];
	for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
	for(int i=1;i<=n-2;++i) DP[i][i+2]=(arr[i]+arr[i+1]-arr[i+2]);
	
	for(int l=n-2;l>=1;--l){
		for(int r=l+3;r<=n;++r){
			int mx=0;
			mx=max({DP[l][l+2]+DP[l+3][r],DP[l][r-3]+DP[r-2][r],mx});
			
			if(r-l>=5){
				for(int k=l;k<=r-5;++k){
					mx=max({
						mx,
						(DP[l][k-1] * (int)(l<k-1))+(DP[k+6][r] * (int)(k+6<=r))+arr[k]+DP[k+1][k+3]+arr[k+4]-arr[k+5],
						(DP[l][k-1] * (int)(l<k-1))+(DP[k+6][r] * (int)(k+6<=r))+arr[k]+arr[k+1]+DP[k+2][k+4]-arr[k+5]	
					});
				}
			}
			
			for(int k=l;k<=r-2;++k){
				mx=max(mx,(DP[l][k-1] * (int)(l<=k-1))+DP[k][k+2]+(DP[k+3][r] * (int)(k+3<=r)));
			}
			DP[l][r]=mx;
		}
	}
	
	printf("%d",DP[1][n]);
}

