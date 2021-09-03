#include <bits/stdc++.h>
using namespace std;
int main(){
	char ch;
	stack <char> s;
	int n;
	scanf("%d",&n);
	int i;
	for(i = 1;i <= n ;++i){
		cin >> ch;
		if(!s.empty()){
			if(s.top() == ch){
				s.pop();
			}else{
				s.push(ch);
			}
		}else{
			s.push(ch);
		}
	}
	if(s.empty()){
		printf("0\n");
		printf("empty");
	}else{
		printf("%d\n",s.size());
		while(!s.empty()){
			printf("%c",s.top());
			s.pop();
		}
	}
}
