#include <bits/stdc++.h>
using namespace std;
int main(){
	int p , a;
	int f_o , f_e , p_e , p_o;
	int i , j;
	scanf("%d",&p);
	f_o = f_e = 0;
	p_e = p;
	p_o = p;
	int n[2*p];
	for(i = 0;i < 2*p;++i){
		scanf("%d",&n[i]);
	}
	for(i = 0;i < 2*p;++i){
		if(n[i] % 2 == 0){
			++f_o;
			f_e = 0;
			if(f_o >= 3){
				//f_o = 0;
				p_e -= 3;
			}else{
				--p_e;
			}
		}else{
			++f_e;
			f_o = 0;
			if(f_e >= 3){
				//f_e = 0;
				p_o -= 3;
			}else{
				--p_o;
			} 
		}
		
		
		if(p_e <= 0 || p_o <= 0){
			printf("%d\n",(n[i]) % 2);
			printf("%d",n[i]);
			break;
		}
	}
}
