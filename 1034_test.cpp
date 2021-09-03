#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

int arr[10][10];

int solve(int n , int m , int x , int y,int mark){
	//cout << n << " " << m << endl;
	if(n > 8 || n < 1) return 0;
	if(m > 8 || m < 1) return 0;
	if(arr[n][m] == 0) return 0;
	if(arr[n][m] == mark) return 1;
	if(solve(n + (1 * y) ,m + (1 * x) ,x , y , mark) >= 1){
		arr[n][m] = mark;
		return 2;
	}
	return 0;
}
int main(){
	//cout << solve(5 , 4 ,-1 , 1 ,-1);
	int k;cin >> k;
	int mark = 1;
	arr[4][4] = -1;arr[4][5] = 1;
	arr[5][5] = -1;arr[5][4] = 1;

	for(int i = 1;i <= k;++i){
		char c;int n;
		cin >> c >> n;
		int m = c - 'a' + 1;

		int cando = 0;
		for(int y = -1;y <= 1;++y){
			for(int x = -1;x <= 1;++x){
				if(x == 0 && y == 0) continue;
				//cout << n + (1 * y) << " " << m + (1 * x) << endl;
				cando = max(solve(n + (1 * y) ,m + (1 * x) ,x , y , mark) , cando);
			}
		}	
		if(cando == 2) arr[n][m] = mark;
		mark *= -1;
	}
	for(int ii = 1;ii <= 8;++ii){
		for(int j = 1;j <= 8;++j){
			if(arr[ii][j] == 0) printf(".");
			if(arr[ii][j] == -1) printf("O");
			if(arr[ii][j] == 1) printf("X");
		}
		printf("\n");
	}
	

}
