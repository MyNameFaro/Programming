#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	float k = int(n / 2) * 2;
	if(n % 2 == 1){
		k = k + 1.464102;
	}
	if(n == 1){
		k = 2.0;
	}
	if(n == 3){
		k = 2 + (sqrt(3));
	}
	printf("%.6f\n",k);
	
}
