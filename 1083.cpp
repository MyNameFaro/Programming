#include <bits/stdc++.h>
using namespace std;

int main(){
	int n , q , a , b;
	scanf("%d",&n);
	int p[n + 1];
	for(int i = 1;i <= n;++i) scanf("%d",&p[i]);
	long long int table[n + 2][2];
	table[n + 1][0] = 0;table[n + 1][1] = 0;
	
	for(int i = n;i >= 1;--i){
		for(int x = 0;x <= 1;++x){
			table[i][x] = table[i + 1][x];
			if(x == 0) table[i][x] = max(table[i][x] , p[i] + table[i + 1][1]);
			if(x == 1) table[i][x] = max(table[i][x] , table[i + 1][0] - p[i]);
		}
		//printf("%d\n",p[i]);
		//printf("%d : %lld %lld\n",i , table[i][0] , table[i][1]);
	}
	scanf("%d",&q);
	for(int i = 1;i <= q;++i){
		scanf("%d %d",&a ,&b);
		printf("%lld\n",table[a][1] - table[b][1]);
	}
}
