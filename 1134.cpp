#include <bits/stdc++.h>
using namespace std;

int main(){
	int mod = 2553;
	vector <int> hash[mod];
	int memo[100003];
	int A , B , C , D , E, F , G , H;
	scanf("%d %d %d %d %d %d %d %d",&A ,&B ,&C ,&D ,&E ,&F ,&G ,&H);
	memo[1] = A;
	memo[2] = B;
	memo[3] = C;
	memo[4] = D;
	for(int i = 5;i <= 10000;++i){
		memo[i] = ((memo[i - 1] * E) % mod) + ((memo[i - 2] * F) % mod) + ((memo[i - 3] * G) % mod) + ((memo[i - 4] * H) % mod);
		memo[i] %= mod;
		hash[memo[i]].push_back(i);
	}
	for(int i=0;i<2553;++i){
		printf("i ::: \n");
		for(auto v:hash[i]) cout << v << " ";
		cout << "\n\n";
	}
}
