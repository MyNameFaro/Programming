#include <bits/stdc++.h>
using namespace std;
int arr[1002][1002];
int main(){
	int N , M;
	int x , y , r;
	scanf("%d %d",&N ,&M);
	for(int i = 1;i <= N;++i){
		scanf("%d %d",&x ,&y);
		++arr[x][y];
	}
	for(int i = 0;i <= 1000;++i){
		for(int j = 0;j <= 1000;++j){
			if(i >= 1) arr[i][j] += arr[i - 1][j];
			if(j >= 1) arr[i][j] += arr[i][j - 1];
			if(i >= 1 && j >= 1) arr[i][j] -= arr[i - 1][j - 1];
		}
	}
	for(int i = 1;i <= M;++i){
		scanf("%d %d %d",&x ,&y ,&r);
		int a = min(x + r,1000);int b = min(y + r , 1000);
		int c = max(x - r - 1,-1);int d = max(y - r - 1, -1);
		int ans = arr[a][b];
		if(d >= 0) ans -= arr[a][d];
		if(c >= 0) ans -= arr[c][b];
		if(d >= 0 && c >= 0) ans += arr[c][d];
		printf("%d\n",ans);
	}
}
