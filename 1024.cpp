#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , x;
	int a , b;
	int i , j;
	int mn = 2e9;
	vector <int> num , qs;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&x);
		num.push_back(x);
		if(qs.empty()){
			qs.push_back(x);
		}else{
			qs.push_back(x + qs[i - 1]);
		}
	}
	//max(qs[i - 1] , max(qs[j - 1] - qs[i - 1] ,qs[n - 1] - qs[j - 1]))
	for(i = 1;i < n - 2;i++){
		for(j = i + 1;j <n - 1;j++){
			if(mn > max(qs[i - 1] , max(qs[j - 1] - qs[i - 1] ,qs[n - 1] - qs[j - 1])) - min(qs[i - 1] , min(qs[j - 1] - qs[i - 1] ,qs[n - 1] - qs[j - 1]))){
				mn = max(qs[i - 1] , max(qs[j - 1] - qs[i - 1] ,qs[n - 1] - qs[j - 1])) - min(qs[i - 1] , min(qs[j - 1] - qs[i - 1] ,qs[n - 1] - qs[j - 1]));
				a = i + 1;
				b = j + 1;
			}
		}
	}
	printf("%d %d",a , b);
}
