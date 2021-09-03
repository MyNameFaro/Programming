#include <bits/stdc++.h>
using namespace std;
int num[12][12];
int main(){
	int n , i , j , x;
	int cross_a = 0;
	int cross_b = 0;
	int sum = 0;
	bool check = true;
	vector <int> a;
	scanf("%d",&n);
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			scanf("%d",&num[i][j]);
			num[i][0] += num[i][j];
			num[0][j] += num[i][j];
			sum += num[i][j];
			if(!a.empty() && find(a.begin() , a.end() , num[i][j]) != a.end()){
				check = false;
			}
			a.push_back(num[i][j]);
			if(i == j){
				cross_a += num[i][j];
			}
			if(j == n + 1 - i){
				cross_b += num[i][j];
			}
		}
	}
	//cout << cross_a << cross_b;
	if(!check){
		cout << "No";
		return 0;
	}
	for(i = 1;i <= n;i++){
		if(num[i][0] != cross_a || num[i][0] != cross_b){
			cout << "No";
			return 0;
		}
		if(num[0][i] != cross_a || num[0][i] != cross_b){
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";
	
}
