#include <bits/stdc++.h>
using namespace std;

int num[1002][1002];

int main(){
	
	int n , m;
	
	
	int x , y , r , k;
	int ans;
	int i , j;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i = 1;i <= n;++i){
		scanf("%d %d",&x ,&y);
		num[x][y] = 1;
	}
	
	for(k = 1;k <= m;++k){
		ans = 0;
		scanf("%d %d %d",&x ,&y ,&r);
		for(i = max(x - r , 0);i <= min(1000 , x + r);++i){
			for(j = max(y - r , 0);j <= min(y + r , 1000);++j){
				if(num[i][j] == 1){
					num[i][j] = 0;
					++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
}
