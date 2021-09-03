#include <bits/stdc++.h>
using namespace std;

int layer[50];
vector<pair<int , int>> l;
int mx , cnt;
int W;

void swp(){
	pair<int , int> top;
	while(l.size() > 0){
		top = l.front();
		layer[cnt] += top.first - mx;
		mx += top.first - mx;
		if(top.second == 0){
			++cnt;	
		}else{
			--cnt;
		}
		l.erase(l.begin());
	}
}
int main(){
	int H ,n;
	int i , j;
	int x , a;
	scanf("%d %d %d",&W ,&H ,&n);
	for(i = 0;i < n;i++){
		scanf("%d %d",&x ,&a);
		l.push_back({x , 0});
		if(x + a <= W){
			l.push_back({x + a,1});
		}
	}
	l.push_back({W , 1});
	sort(l.begin() , l.end());
	swp();
	printf("%d %d",layer[0] * H,layer[1] * H);
}
