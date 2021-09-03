#include<bits/stdc++.h>
using namespace std;
int dis[602][602];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;++i){
		for(int j=1;j<=2*n;++j){
			scanf("%d",&dis[i][j]);
		} 
	}
	for(int i=4;i<=n+n;++i){
		for(int j=i-1;j>=3;--j){
			dis[i][2]=min(dis[i][2] , dis[i][j]+dis[j][2]);
		}
	}
	printf("%d",dis[n+n][2]);
}
