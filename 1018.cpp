#include <bits/stdc++.h>
using namespace std;

int dr = 0;
int x , y;

void change(int c){
	switch(c){
		case 'R':
			dr += 1;
			break;
		case 'L':
			dr -= 1;
			break;
		case 'B':
			dr += 2;
			break;
		case 'F':
			dr += 0;
			break;
	}
	if(dr == 4){
		dr = 0;
	}else if(dr == -1){
		dr = 3;
	}	
}

int main(){
	int n , k;
	cin >> n;
	bool dead = false;
	int i;
	string com;
	for(i = 0;i < n;i++){
		cin >> com >> k;
		change(com[0]);
		if(dr == 0){
			x += k;
		}else if(dr == 2){
			x -= k;
		}else if(dr == 1){
			y -= k;
		}else if(dr == 3){
			y += k;
		}
		if((x <= -50000 || x >= 50000) || (y <= -50000 || y >= 50000)){
			dead = true;
		}
	}
	if(dead){
		printf("DEAD");
		return 0;
	}
	cout << x << " " << y << "\n";
	switch(dr){
		case 0:
			printf("E");
			break;
		case 1:
			printf("S");
			break;
		case 2:
			printf("W");
			break;
		case 3:
			printf("N");
			break;
	}
}
