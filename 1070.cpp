#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;int x;
	int mn1 = 2e9;int mx = -2e9;int mn2 = 2e9;
	cin >> N;
	if(N < 3){
		printf("no");return 0;
	}
	for(int i = 1;i <= N;++i){
		cin >> x;
		if(x < mn1){
			mn1 = x;
		}else{
			mn2 = min(mn2 , x);
		} 
		mx = max(mx , x);
	}
	if(mx >= mn1 + mn2){
		printf("yes");return 0;
	}
	printf("no");
}
