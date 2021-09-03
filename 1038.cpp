#include<bits/stdc++.h>
using namespace std;
double arr[22][22];
double memo[1<<20];
int n;
double solve(int x){
	if(memo[x]==0.0){
		int r=0;
		for(int i=0;i<n;++i){
			if((x&(1<<i)) != 0) ++r;
		}
		//cout << r << endl;
		if(r>=n) return 1.0;
		for(int c=0;c<n;++c){
			if((x&(1<<c)) != 0) continue;
			memo[x]=max(memo[x] , arr[r][c]*solve((1<<c)|x));
		}
	}
	return memo[x];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			int x;
			scanf("%d",&x);
			arr[i][j]= (double)((double)x/100.0);
		}
	}
	
	printf("%.6lf",solve(0)*100.00);
}
