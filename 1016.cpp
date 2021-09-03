#include <bits/stdc++.h>
using namespace std;

double x = 0.0;
double y = 0.0;

int main(){
	string s;
	char c;
	double n;
	while(s != "*"){
		n = 0.0;
		cin >> s;
		if(s == "*"){
			break;
		}
		c = s[0];
		while(c <= '9' && c >= '0'){
			n = (n * 10.0) + (c - '0')*1.0;
			s.erase(0 , 1);
			c = s[0];
		}
		//cout << n << " \n";
		//switch(s){
			if(s == "N"){
				y = y + n;
		
			}else if(s == "S"){
				y = y - n;
			}else if(s == "W"){
				x = x - n;
			}else if(s == "E"){
				x = x + n;
			}else if(s == "NE"){
				x = x + (n * sqrt(2)/2);
				y = y + (n * sqrt(2)/2);
			}else if(s == "SE"){
				x = x + (n * sqrt(2)/2);
				y = y - (n * sqrt(2)/2);
			}else if(s == "NW"){
				x = x - (n * sqrt(2)/2);
				y = y + (n * sqrt(2)/2);
			}else if(s == "SW"){
				x = x - (n * sqrt(2)/2);
				y = y - (n * sqrt(2)/2);
			}
				
				
		//}
	}
	printf("%.3lf %.3lf\n",x , y);
	printf("%.3lf" ,sqrt( x*x + y*y));
	
}
