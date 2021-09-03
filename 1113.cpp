#include <bits/stdc++.h>
using namespace std;
using lli = long long;
map <lli , int> memo;

int main(){
	lli N , K;
	int ans = 0;
	scanf("%lld %lld",&N,&K);
	vector <lli> table (N + 1,0);
	string s;
	cin >> s;
	memo[0] = 0;
	for(int i = 1;i <= s.size();++i){
		if(s[i - 1] == 'R'){
			table[i] = -K;
		}else{
			table[i] = 1;
		}
		table[i] += table[i - 1];
		if(memo.count(table[i]) == 0){
			memo[table[i]] = i;
		}else{
			ans = max(ans , i - memo[table[i]]);
		}
	}
	printf("%d",ans);	
}
