#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,n,x;
	long long int sum = 0, ans = -2e9;
	int i_max = 1 , j_max;
	scanf("%d",&n);
	int num[n + 1];
	int table[n + 1];
	table[0] = 0;
	for(i = 1;i <= n;i++){
		scanf("%d",&num[i]);
		table[i] = max(num[i] , table[i - 1] + num[i]);
		if(ans < table[i]){
			ans = table[i];
			i_max = i;
		}
	}
	if(ans <= 0){
		printf("Empty sequence");
		return 0;
	} 
	stack <int> ss;
	while(sum != ans){
		sum += num[i_max];
		ss.push(num[i_max]);
		i_max--;
	}
	while(!ss.empty()){
		printf("%d ",ss.top());
		ss.pop();
	}
	printf("\n%lld",ans);
	
	
	return 0;
}
