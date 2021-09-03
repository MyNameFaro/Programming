#include <bits/stdc++.h>
using namespace std;
set <int> K[33];
void func(){
		int A;cin >> A;
		for(int k = 32;k >= 2;--k){
			if(K[k].find(A) != K[k].end()){
				printf("%d\n",k);
				return;
			}
		}
		printf("NO\n");
}
int main(){
	int N;
	int x , A;
	cin >> N;
	for(int y = 2;y <= 10000;++y){
		int x = y * y;
		for(int k = 2;k <= (double) (8.0 / log10(y));++k){
			K[k].insert(x);
			x *= y;
		}
	}
	for(int i = 1;i <= N;++i) func();
}

