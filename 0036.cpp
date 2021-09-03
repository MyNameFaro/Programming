#include <bits/stdc++.h>
using namespace std;


long long int fac(int n,int m){
	long long int total = 1;
	int i;
	if(m == 0){
		m = 1;
	}
	for(i = m + 1;i <= n;i++){
		total *= i;
	}
	return total;
	
}
int main(){
	int i;
	int n;
	scanf("%d",&n);
	long long int ans = fac(n , n / 2) / fac(n - (n / 2) , 1);
	if(n % 2 == 1){
		ans *= 2;
	}
	printf("%lld" , ans);
}
