#include <bits/stdc++.h>
using namespace std;
int N;
int st = 1;int direct = 1;
int mod(int a){
	if(a > 0) return (a % N == 0) ? N : a % N;
	return N + a;
}
int find(int q){
	int ans;
	ans = mod(direct * (q - st) + 1);
	if(ans == 0) ans = N;
	return ans; 
}
int main(){
	int M;char c;
	int a , b , k;
	scanf("%d %d",&N ,&M);
	int arr[N + 1];
	for(int i = 1;i <= N;++i) scanf("%d",&arr[i]);
	while(M--){
		cin >> c;
		if(c == 'a'){
			cin >> a >> b;
			swap(arr[find(a)] , arr[find(b)]);
		}else if(c == 'c'){
			cin >> a;
			st = ((2*N) - st + 1 + a) % N; // find_new_st
			if(st == 0) st = N;
			direct *= -1;
		}else{
			cin >> a;
			int index = find(a);
			if(c == 'b'){
				cin >> k;
				arr[index] = k;
			}else{
				printf("%d\n",arr[index]);
			}
		}
	}
}
