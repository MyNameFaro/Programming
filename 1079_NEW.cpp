#include <bits/stdc++.h>
using namespace std;
long long int memo[100002];
long long int qs[100002];
int n , k;

long long int solve(int x){
	if(x <= 0){
		return 1;
	}
	if(memo[x] == 0){
		int i , j;
		memo[x] = qs[x - 1];
		if(x - k - 1 >= 0){
			memo[x] -= qs[x - k - 1];
		}
		memo[x] %= 2009;
		qs[x] = qs[x - 1] + memo[x];
		qs[x] %= 2009;
	}
	return memo[x];
}
int main(){
	qs[0] = 1;
	scanf(" %d %d",&n ,&k);
	printf("%lld" , solve(n));
}
