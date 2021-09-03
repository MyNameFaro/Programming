#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int b[101][101];
int qa(int r1,int c1,int r2,int c2){
	return a[r2][c2]-a[r2][c1-1]-a[r1-1][c2]+a[r1-1][c1-1];
}
int qb(int r1,int c1,int r2,int c2){
	return b[r2][c2]-b[r2][c1-1]-b[r1-1][c2]+b[r1-1][c1-1];
}
int main(){
	int n,m;
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&b[i][j]);
			b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
		}
	}
	for(int r=1;r<=n;++r){
		int sum=0;
		if(r>1) sum+=qb(r-1,1,r-1,m);
		if(r<n) sum+=qb(r+1,1,r+1,m);
		if(r>1) sum+=qa(1,1,r-1,m);
		if(r<n) sum+=qa(r+1,1,n,m);
		ans=max(ans,sum);
	}
	for(int c=1;c<=m;++c){
		int sum=0;
		if(c>1) sum+=qb(1,c-1,n,c-1);
		if(c<m) sum+=qb(1,c+1,n,c+1);
		if(c>1) sum+=qa(1,1,n,c-1);
		if(c<m) sum+=qa(1,c+1,n,m);
		ans=max(ans,sum);
	}
	printf("%d",ans);
}
