#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int total = 0 , ans;
	int n , m , i , j , x;
	scanf(" %d %d",&n ,&m);
	int l , k;
	scanf(" %d %d",&l ,&k);
	int c;
	scanf(" %d",&c);
	total += (l * k * c);
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			scanf("%d" ,&x);
			total += x;
		}
	}
	ans = total / c;
	if(total % c != 0){
		ans += 1;
	}
	printf("%lld",ans);
}
