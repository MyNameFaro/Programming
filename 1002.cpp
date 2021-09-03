#include <bits/stdc++.h>
using namespace std;

int i_t = 0,v_t = 0,x_t = 0,l_t = 0,c_t = 0;

void roman(int d){
		int i = 0,v = 0,x = 0,l = 0,c = 0;
		
		c += d / 100;
		d -= (c * 100);
		if(d / 10 == 4){
			++x;
			++l;
		}else if(d / 10 == 9){
			++c;
			++x;
		}else if(d / 10 < 4 && d / 10 != 0){
			x += (d/10);
		}else if(d / 10 >= 5 && d / 10 != 0){
			x += (d/10) - 5;
			++l;
		}
		if(d % 10 == 4){
			++i;
			++v;
		}else if(d % 10 == 9){
			++x;
			++i;
		}else if(d % 10 < 4 && d % 10 != 0){
			i += (d%10);
		}else if(d % 10 >= 5 && d % 10 != 0){
			i += (d%10) - 5;
			++v;
		}
		i_t += i;
		v_t += v;
		x_t += x;
		l_t += l;
		c_t += c;
}
int main(){
	
	int d , r , n;
	cin >> d;
	for(r = 1;r <= d;r++){
		roman(r);
	}
	printf("%d %d %d %d %d",i_t , v_t , x_t , l_t , c_t);
}
