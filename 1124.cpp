#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<lli , int>;

lli N , sum , cnt;
vector <int> W (1 , 1);
vector <pii> powerset;
int solve(int n){
	if(n == 20){
		powerset.push_back({sum , cnt});
	}else{
		++cnt;
		sum += W[n];
		solve(n + 1);
		--cnt;
		sum -= W[n];
		solve(n + 1);
	}
}

int bs(lli x , int i){
	int l = i;int r = powerset.size() - 1;
	while(l <= r){
		int mid = (l + r)/2;
		if(powerset[mid].first == x) return powerset[mid].second;
		if(x < powerset[mid].first){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return 0;
}

int main(){
	int s = 3;
	for(int i = 1;i <= 19;++i){
		W.push_back(s);
		s *= 3;
	}
	solve(0);
	cin >> N;
	sort(powerset.begin() , powerset.end());
	int find = bs(N , 0);
	if(find > 0){
		printf("%d ",find);
		printf("%lld",N);
		return 0;
	}
	for(int i = 0;i < powerset.size();++i){
		//cout << powerset[i] << endl;
		find = bs(N + powerset[i].first , i);
		if(find > 0){
			printf("%d ",find + powerset[i].second);
			printf("%lld",N + powerset[i].first);
			
			return 0;
		}
	}
}
