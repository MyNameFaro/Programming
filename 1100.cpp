#include <bits/stdc++.h>
using namespace std;
int main(){
	set <pair <long long int , long long int>> s;
	for(long long int i = 0;i < 10000000;++i){
		s.insert({i , i});
	}
	printf("%lld",s.size());
}
