#include <bits/stdc++.h>
using namespace std;

int n;
int qt , wt , st , q , w , s;
//int sm[25] , qm[25] , wm[25];

void f(){
	s = 0;q = 1;w = 1;
	int i;
	for(i = 1;i <= n;i++){
		wt = w;
		st = s;
		w += q;
		w += st;
		s += wt;
		s -= st;
	}
}

int main(){
	int a , b;
	while(n != - 1){
		scanf("%d",&n);
		if(n == -1){
			break;
		}
		f();
		printf("%d %d\n",w , w + q + s);
	}
}
