#include <bits/stdc++.h>
using namespace std;
long long int table[100005];
int n , k;

int main(){
	int i ;
	scanf(" %d %d",&n ,&k);
	table[0] = 1;
	for(int x = 1;x <= n;++x){
		table[x] = table[x - 1] + 2009;
		if(x - k - 1 >= 0){
			table[x] -= table[x - k - 1] % 2009;
		} 
		if(x == n) break;
		table[x] = (table[x] + table[x - 1]) % 2009;
	}
	printf("%lld",table[n] % 2009);
}
