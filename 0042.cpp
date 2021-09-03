#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long double ans;
	
	int q;
	scanf("%d",&q);
	int i , j;
	for(i = 0;i < q;i++){
		ans = 1.0;
		scanf("%d",&n);
		for(j = 1;j <= n;++j){
			ans = ans * 2.0;
		}
		printf("%.0Lf\n",ans);
	}
}
