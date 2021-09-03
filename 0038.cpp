#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	priority_queue <string> q;
	string s;
	int i;
	for(i = 0;i < n;i++){
		cin >> s;
		q.push(s);
	}
	stack <string> m;
	while(!q.empty()){
		if(q.top() != s){
			m.push(q.top());
		}
		s = q.top();
		q.pop();
	}
	while(!m.empty()){
		cout << m.top();
		printf("\n");
		m.pop();
	}
	
}
