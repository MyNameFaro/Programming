#include <bits/stdc++.h>
using namespace std;
int main(){
	string n;
	cin >> n;
	int i;
	int mod_3 = 0;
	int mod_11 = n[0] - '0';
	for(i = 0;i < n.size();++i){
		mod_3 = (mod_3 * 10) + (n[i] - '0');
		mod_3 %= 3; 
	}
	for(i = 1;i < n.size();++i){
		mod_11 = (mod_11 * 10) + (n[i] - '0');
		mod_11 %= 11; 
	}
	printf("%d %d",mod_3,mod_11);
}
