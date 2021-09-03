#include <bits/stdc++.h>
using namespace std;

vector <int> s , b;
int n;

long long int mn = 2e9;
long long int sum = 0;
long long int total = 1;

int f(int x){
	if(x == n){
		if(abs(sum - total) < mn && sum != 0 && total != 1){
			mn = abs(sum - total);
		}
	}else{
		sum += b[x];
		total *= s[x];
		f(x + 1);
		sum -= b[x];
		total /= s[x];
		f(x + 1);
	} 
	
	
}
int main(){
	scanf("%d",&n);
	int i , x , y;
	for(i = 1;i <= n;i++){
		scanf(" %d %d",&x,&y);
		s.push_back(x);
		b.push_back(y);
	}
	f(0);
	cout << mn;
	
}
