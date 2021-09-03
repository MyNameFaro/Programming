#include <bits/stdc++.h>
using namespace std;
int main(){
	int A , B , C;
	scanf("%d %d %d",&A ,&B ,&C);
	int a , b , c , d;
	int r = 100;
	for(a = 1;a <= r;++a){
		for(b = (-1*r);b <= r;++b){
			for(c = 1;c <= r;++c){
				for(d = (-1*r);d <= r;++d){
					if(a*c == A && (b*c)+(a*d) == B && b*d == C){
						printf("%d %d %d %d",a ,b ,c , d);
						return 0;
					}
				}
			}
		}
	}
	printf("No Solution");
}
