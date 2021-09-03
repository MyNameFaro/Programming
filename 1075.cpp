#include <bits/stdc++.h>
using namespace std;
using pii = pair<double , int>;

int main(){
	int N;scanf("%d",&N);
	double D[N + 1] , C[N + 1];
	priority_queue <pii> R;
	
	for(int i = 1;i <= N;++i){
		scanf("%lf %lf",&D[i] , &C[i]);
		R.push({D[i] / C[i] , i});
	}
	double d = 0.0 , c = 0.0 , mr = 0.0;
	while(!R.empty()){
		pii r = R.top();R.pop();
		int i = r.second;
		//cout << D[i] << " " << C[i] << endl;
		double ans = (D[i] + d) / max(C[i] , c);
		if(ans > mr){
			mr = ans;
			d = d + D[i];
			c = max(C[i] , c);
		}
	}
	printf("%.0lf %.0lf",d , c);
}
