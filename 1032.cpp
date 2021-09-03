#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int i , j , x , r;
	vector <int> ans;
	bool check;
	int s[10][10] , t[10][10];
	for(i = 1;i <= 9;i++){
		for(j = 1;j <= 9;j++){
			scanf("%d",&s[i][j]);
		}
	}
	for(r = 1;r <= n;r++){
		check = true;
		for(i = 0;i <= 9;i++){
			for(j = 0;j <= 9;j++){
				t[i][j] = 0;
			}
			//printf("\n");
		}
		for(i = 1;i <= 9;i++){
			for(j = 1;j <= 9;j++){
				scanf("%d",&x);
				if(s[i][j] != 0 && x != s[i][j]){
					check = false;
				}
				t[i][j] = x + t[i][j - 1] + t[i - 1][j];
				if(i > 1 && j > 1){
					t[i][j] -= t[i - 1][j - 1];
				}
				t[i][0] += x;
				t[0][j] += x;
			
			}
		}
		for(i = 1;i <= 9;i++){
			if(t[i][0] != 45){
				check = false;
			}
			if(t[0][i] != 45){
				check = false;
			}
		}
		if(t[3][3] != 45){
			check = false;
		}
		else if(t[3][6] - t[3][3] != 45){
			check = false;
		}
		else if(t[3][9] - t[3][6] != 45){
			check = false;
		}
		else if(t[6][3] - t[3][3] != 45){
			check = false;
		}
		else if(t[6][6] - t[3][6] - t[6][3] + t[3][3] != 45){
			check = false;
		}
		else if(t[6][9] - t[6][6] - t[3][9] + t[3][6] != 45){
			check = false;
		}
		else if(t[9][3] - t[6][3] != 45){
			check = false;
		}
		else if(t[9][6] - t[6][6] - t[9][3] + t[6][3] != 45){
			check = false;
		}
		else if(t[9][9] - t[6][9] - t[9][6] + t[6][6] != 45){
			check = false;
		}
		if(check){
			ans.push_back(r);
		}
		/*for(i = 0;i <= 9;i++){
			for(j = 0;j <= 9;j++){
				printf("%d ",t[i][j]);
			}
			printf("\n");
		}*/
	}
	for(i = 0;i < ans.size();++i){
		printf("%d\n",ans[i]);
	}	
	printf("END");
}
