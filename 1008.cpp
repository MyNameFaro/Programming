#include <bits/stdc++.h>
using namespace std;

int L[3002];

int main(){
	
	int n , m;
	
	
	int l , h , r;
	
	int i , j;
	scanf("%d",&n);
	for(j = 1;j <=n;++j){
		scanf("%d %d %d",&l ,&h ,&r);
		for(i = l;i < r;++i){
			L[i] = max(L[i] , h);
		}
	}
	for(i = 1;i <= 3000;++i){
		if(L[i] != L[i-1]){
			printf("%d %d£×",i , L[i]);
		}
	}
}
