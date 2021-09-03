#include <bits/stdc++.h>
using namespace std;

int main(){
	int n , m , k;
	scanf("%d %d %d",&n ,&m ,&k);
	int x;
	vector <int> R , P;
	R.push_back(0);
	P.push_back(0);
	vector <int> sub_table (k + 2,0);
	int table[m + 2][k + 2];
	for(int i = 0;i <= m + 1;++i){
		for(int j = 0;j <= k + 1;++j) table[i][j] = 0;
	}
	for(int i = 1;i <= m;++i){
		scanf("%d",&x);
		R.push_back(x);
	}
	for(int i = 1;i <= k;++i){
		scanf("%d",&x);
		P.push_back(x);
	}
	R.push_back(n);
	for(int l = m;l >= 0;--l){
		for(n = k;n >= 1;--n){
			table[l][n] = 0;
			for(int x = l + 1;x < R.size() - k + n;++x){
				table[l][n] = max(table[l][n] , ((R[x] - R[l]) * P[n]) + table[x][n + 1]);
			}
		}
	}
	printf("%d",table[0][1]);
}
