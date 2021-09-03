#include<bits/stdc++.h>
using namespace std;
map<vector<int> , bool> cnt;
int n;
vector <int> s,v;
int total=1;
int solve(int x){
	if(s.size()==n){
		sort(s.begin(),s.end());
		if(cnt.count(s)==0){
			printf("%d : ",total+1);
			for(auto y:s){
				cout << y << ", ";
			}
			printf("\n");
			cnt[s]=true;
			++total;
		}
		
		return 0;
	}
	if(x>11) return 0;
	s.push_back(v[x]);
	solve(x+1);
	s.pop_back();
	solve(x+1);
}
int main(){
	v.push_back(0);
	v.push_back(1);v.push_back(1);
	v.push_back(5);v.push_back(5);v.push_back(5);v.push_back(5);
	v.push_back(10);v.push_back(10);v.push_back(10);v.push_back(10);v.push_back(10);
	printf("1 : EMPTY\n");
	for(int i=1;i<=11;++i){
		n=i;
		solve(1);
	}
	cout << "TOTAL = "<< total;
}
