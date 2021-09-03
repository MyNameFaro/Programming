#include <bits/stdc++.h>
using namespace std;

int a[52][52];
char b[52][52];
int memo[52][52];
int r = 5;
int c = 5;
pair <int , int> s , d;

void bfs(int x,int y,int l,int d_x,int d_y ,bool kaktus = false){
	queue <pair <int , int>> q; 
	pair <int , int> node;
	a[x][y] = l;
	q.push({x , y});
	while(!q.empty()){
		node = q.front();
		x = node.first;
		y = node.second;
		if(x == d_x && y == d_y){
			printf("%d",a[d_x][d_y]);
			kaktus = false;
			break;
		}
		l = a[x][y];
		q.pop();
			if(x - 1 > 0 && (a[x - 1][y] > l + 1 && b[x - 1][y] != 'S' && b[x - 1][y] != 'X' && (b[x - 1][y] != 'D' || kaktus))){
				a[x - 1][y] = l + 1;
				q.push({x - 1 , y});
			}
		
			if(x + 1 <= r && (a[x + 1][y] > l + 1 && b[x + 1][y] != 'S' && b[x + 1][y] != 'X'&& (b[x + 1][y] != 'D' || kaktus))){
				a[x + 1][y] = l + 1;
				q.push({x + 1 , y});
			}
	
			if(y - 1 > 0 && (a[x][y - 1] > l + 1 && b[x][y - 1] != 'S' && b[x][y - 1] != 'X' && (b[x][y - 1] != 'D' || kaktus))){
				a[x][y - 1] = l + 1;
				q.push({x, y - 1});
			}
		
			if(y + 1 <= c && (a[x][y + 1] > l + 1 && b[x][y + 1] != 'S' && b[x][y + 1] != 'X' && (b[x][y + 1] != 'D' || kaktus))){
				a[x][y + 1] = l + 1;
				q.push({x, y + 1});
			}
		
		
		
	}
	if(kaktus){
		printf("KAKTUS");
	}
}

int main(){
	int i , j;
	scanf("%d %d",&r ,&c);
	queue <pair <int,int>> w;
	pair<int , int> node;
	for(i = 1;i <= r;i++){
		for(j = 1;j <= c;j++){
			a[i][j] = 10000;
		}
		//printf("\n");
	}
	for(i = 1;i <= r;i++){
		for(j = 1;j <= c;j++){
			scanf(" %c",&b[i][j]);
			if(b[i][j] == '*'){
				w.push({i , j});
			}else if(b[i][j] == 'D'){
				d = {i , j};
			}else if(b[i][j] == 'S'){
				s = {i , j};
			}else if(b[i][j] == 'X'){
				a[i][j] = -1;
			}
			
		}
		//printf("\n");
	}
	while(!w.empty()){
		node = w.front();
		w.pop();
		bfs(node.first , node.second ,0 ,-1 ,-1 , false);
	}

	bfs(s.first , s.second ,0 ,d.first , d.second , true);
	printf("\n");
	
	
}
