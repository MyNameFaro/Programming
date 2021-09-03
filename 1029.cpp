#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector <pii> l , magnet;
int pre = 0;
int cnt;
void linesweep(){
	for(int i = 0;i < l.size();++i){
		pii top = l[i];
		if(magnet.back().first == top.first && top.first != 1){
			magnet.pop_back();
		}else if(magnet.back().second == cnt){
			magnet.pop_back();
			magnet.push_back({top.first , cnt});
		}else{
			magnet.push_back({top.first , cnt});
		} 
		if(top.second == 1) --cnt;
		if(top.second == 0) ++cnt;
		cnt = abs(cnt) % 2;
	}
	
}
int main(){
	int N , M , Q;
	int a , k;
	int x;
	scanf("%d %d %d",&N ,&M,&Q);
	for(int i = 1;i <= M;++i){
		scanf("%d %d",&a ,&k);
		l.push_back({a , 0});
		l.push_back({a + k , 1});
	}
	sort(l.begin() , l.end());
	magnet.push_back({1 , 1});
	linesweep();
	if(magnet.back().first != N + 1) magnet.push_back({N + 1 , 1});
	//for(auto mm:magnet) cout << mm.first << " ";
	for(int i = 1;i <= Q;++i){
		scanf("%d",&x);
		int l = 0;int r = magnet.size() - 1;
		if(magnet[1].first == 1) l = 1;
		while(l <= r){
			int mid = (l + r)/2;
			if(x >= magnet[mid].first && x < magnet[mid + 1].first){
				printf("%d\n",magnet[mid+1].first - magnet[mid].first);
				break;
			}
			if(x < magnet[mid].first) r = mid - 1;
			if(x >= magnet[mid].first) l = mid + 1; 
		}
	}
}
