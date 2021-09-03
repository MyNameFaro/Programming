#include<bits/stdc++.h>
using namespace std;
double compute(int x1,int x2,int x3,int y1,int y2,int y3){
	return (double) abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1)/2.0;
}
int main(){
	int N;
	scanf("%d",&N);
	int p[N][2];
	for(int i=0;i<N;++i){
		scanf("%d%d",&p[i][0],&p[i][1]);
	}
	double ans=0;
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			for(int k=j+1;k<N;++k){
				ans=max(ans,compute(p[i][0],p[j][0],p[k][0],p[i][1],p[j][1],p[k][1]));
			}
		}
	}
	printf("%.3lf",ans);
}
