#include <bits/stdc++.h>
using namespace std;

int layer[4];
priority_queue <pair<int , int> ,vector <pair<int , int>> , greater<pair<int , int>>> l;
int cnt , mx;

void swp(){
	pair<int , int> top;
	while(!l.empty()){
		top = l.top();
		layer[cnt % 3] += top.first - mx;
		mx += top.first - mx;
		if(top.second == 0){
			++cnt;
		}else{
			--cnt;
		}
		l.pop();
	}
}
int main(){
	int n , m , i;
	int a , b;
	char c;
	scanf("%d %d",&n ,&m);
	for(i = 0;i < m;++i){
		scanf("%d %d",&a ,&b);
		l.push({a - 1, 0});
		l.push({b, 1});
	}
	cin >> c;
	l.push({n , 1});
	swp();
	if(c == 'G'){
		printf("%d" , 2*layer[2] + layer[0]);
	}else if(c == 'B'){
		printf("%d" , 2*layer[0] + layer[1]);
	}else if(c == 'R'){
		printf("%d" , 2*layer[1] + layer[2]);
	}
}
