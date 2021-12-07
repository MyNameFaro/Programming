#include <bits/stdc++.h>
using namespace std;
int table[2][200002];
int main(){
	int n , m , k;
	scanf("%d %d %d",&n ,&m ,&k);
	int r[m+2],p[k+1];
	r[0]=0;r[m+1]=n;
	for(int i=1;i<=m;++i){
		scanf("%d",&r[i]);
	} 
	for(int i=1;i<=k;++i){
		scanf("%d",&p[i]);
	}
	for(int j=1;j<=m+1;++j){
		table[1][j]=p[1]*r[j];
	}
	for(int i=2;i<=k;++i){
		int mx=table[(i-1)%2][i-1],k=i-1;
		for(int j=i;j<=m+1;++j){
			if(table[(i-1)%2][j-1]+p[i]*(r[j]-r[j-1])>mx+p[i]*(r[j]-r[k])){
				mx=table[(i-1)%2][j-1];
				k=j-1;
			}
			/*for(int k=1;k<j;++k){
				mx=max(mx , table[(i-1)%2][k]+p[i]*(r[j]-r[k]));
			}*/
			table[i%2][j]=mx+p[i]*(r[j]-r[k]);
			//printf("%d ",mx);
		}
		//printf("\n");
	}
	printf("%d",table[k%2][m+1]);
}
