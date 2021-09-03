#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n , k;
	char c;
	priority_queue <long long int> q;
	scanf("%lld",&n);
	int i;
	for(i = 0;i < n*2;i++){
		scanf("%c",&c);
		switch(c){
			case 'P':
			scanf("%lld",&k);
			q.push(k);
			break;
			case 'Q':
			if(q.empty()){
				printf("-1\n");
			}else{
				printf("%lld\n",q.top());
				q.pop();
			}
		}
	}
}
