#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool p = false;
	bool d = false;
	int i;
	for(i = 0;i < s.size()/2;i++){
		if(toupper(s[i]) != toupper(s[s.size() - 1 - i])){
			printf("No");
			return 0;
		}
	}
	for(i = 0;i < s.size()/4;i++){
		if(toupper(s[i]) != toupper(s[s.size()/2 - 1 - i])){
			printf("Palindrome");
			return 0;
		}
	}
	printf("Double Palindrome");
}
