#include <bits/stdc++.h>
using namespace std;

int num[1002][1002];
int qs[1002][1002];
int main(){
	int n , m;
	scanf("%d",&n);
	scanf("%d",&m);
	int x , y , r;
	int i , j;
	for(i = 1;i <= n;++i){
		scanf("%d %d",&x ,&y);
		num[x][y] = 1;
	}
	for(i = 0;i <= 1000;++i){
		for(j = 0;j <= 1000;++j){
			qs[i][j] += num[i][j];
			if(i != 0){
				qs[i][j] += qs[i - 1][j];
			}
			if(j != 0){
				qs[i][j] += qs[i][j - 1];
			}
			if(i != 0 && j != 0){
				qs[i][j] -= qs[i - 1][j - 1];
			}
		}
	}
	for(i = 0;i <= 20;++i){
		for(j = 0;j <= 20;++j){
			printf("%d ",num[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0;i <= 20;++i){
		for(j = 0;j <= 20;++j){
			printf("%d ",qs[i][j]);
		}
		printf("\n");
	}
	
	for(i = 1;i <= m;++i){
		scanf("%d %d %d",&x ,&y ,&r);
		printf("%d\n",qs[x + r][y + r] + qs[x - r - 1][y - r - 1] - qs[x + r][y - r - 1] - qs[x - r - 1][y + r]);
	}
}
