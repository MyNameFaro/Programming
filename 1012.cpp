#include <bits/stdc++.h>
using namespace std;

int z[5];

int main(){
	
	int n ;
	int a , b , c , d , e;
	int i;
	scanf("%d",&n);
	for(i = 0;i < n;++i){
		scanf("%d %d %d %d %d",&a ,&b ,&c ,&d ,&e);
		z[0] += a;
		z[1] += b;
		z[2] += c;
		z[3] += d;
		z[4] += e;
	}
	int ans = 0;
	ans += z[1] + z[0];
	ans += (int) ceil( (double) z[2] / 2);
	ans += (int) ceil( (double) ((z[3] + (int) ceil((double) z[4] / 2)) - z[1] - (z[2] % 2)) / 4);
	printf("%d",ans);
}
