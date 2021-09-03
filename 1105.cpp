#include <bits/stdc++.h>
using namespace std;
int main(){
	vector <int> car;
	int n , k , x;
	scanf(" %d %d",&n,&k);
	int i;
	for(i = 1;i <= n;i++){
		scanf("%d",&x);
		car.push_back(x);
	}
	sort(car.begin() , car.end());
	printf("%d",car[n - k]);
	
}
