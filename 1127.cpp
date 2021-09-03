#include <bits/stdc++.h>
using namespace std;

vector <int> p(10 , 0);
int N;

bool compare(int &a , int &b){
	int l_a = N / p[a];
	int l_b = N / p[b];
	if(l_a != l_b) return l_a > l_b;
	return a > b;
}

int main(){
	scanf("%d",&N);
	vector <int> num;
	vector <int> slot(102 , 0);
	for(int i = 1;i <= 9;++i) num.push_back(i);
	for(int i = 1;i <= 9;++i) scanf("%d",&p[i]);
	sort(num.begin() , num.end() , compare);
	int price = 0;
	int L = 0;
	//INIT LONGGGGG
	for(auto n:num){
		for(int i = 0;i <= 101;++i){
			int newprice = price - p[slot[i]] + p[n];
			if(n < slot[i] || newprice > N) break;
			price = newprice;
			slot[i] = n;
			++L;
		}
		break;
	}
	int i = 0;	
	for(int n = 9;n >= 1;--n){
		while(true){
			int newprice = price - p[slot[i]] + p[n]; 
			if(n <= slot[i]) break;
			if(newprice > N){
				bool have_new = false;
				for(int j = L - 1;j > i;--j){
					for(auto x:num){
						newprice = price - p[slot[i]] + p[n] + p[slot[j]] - p[x];
						if(newprice <= N){
							slot[j] = x;
							slot[i] = n;
							price = newprice;
							have_new = true;
							break;
						} 
					}
					if(have_new) break;
				}
				if(!have_new) break;
			}else{
				price = newprice;
				slot[i] = n;
			}
			++i;
		}
	}
	for(int i = 0;i <= 101;++i){
		if(slot[i] == 0) break;
		printf("%d",slot[i]);
	}
}
