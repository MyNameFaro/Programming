#include <iostream>
using namespace std;
int main(){
	int n, k ;
	int r = 1 ;
	int p = 1 ;
	int i;
	cin >> n >> k;
	int num[n + 1];
	for(i=1;i<=n;i++){
		num[i] = 1;
	}
	i = 1;
	while(r <= n){
		if(num[p] != 0){
			if(i == n){
				cout << p << "\n";
				num[p] = 0;
				i = 0;
			}
			if(p == k){
				p = 0;
				r++;
			}
			p++;
			i++;
		}
	}
	
}
