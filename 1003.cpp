#include <bits/stdc++.h>
using namespace std;

int memo[101];

int f(int x){
	if(x < 0){
		return 0;
	}
	if(x == 0){
		return 1;
	}
	if(memo[x] == 0){
		memo[x] = max(f(x - 6) ,max(f(x - 9),f(x - 20)));
	}
	return memo[x];
}
int main(){
	int n , i;
	scanf("%d",&n);
	if(n < 6){
		printf("no");
		return 0;
	}
	for(i = 6;i <= n;i++){
		if(f(i) >= 1){
			printf("%d \n",i);
		}
	}
}
