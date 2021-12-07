#include <bits/stdc++.h>
using namespace std;
using lli=long long;
lli sA,sB,sC,sAB,sBC,sCA,sABC ,ans; //n(A),n(B),...
lli o[10][3],t[100][3],tt[1000];
lli c(lli x){
	return max((lli)0,(x*(x-1))/(lli)2);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		string s;
		cin >> s;
		int a=s[0]-'0';
		int b=s[1]-'0';
		int c=s[2]-'0';
		o[a][0]++;
		o[b][1]++;
		o[c][2]++;
		t[10*a+b][0]++;
		t[10*b+c][1]++;
		t[10*a+c][2]++;
		tt[(a*100+b*10+c)]++;
	}
	for(int i=0;i<10;++i){
		sA+=c(o[i][0]);
		sB+=c(o[i][1]);
		sC+=c(o[i][2]);
	}
	for(int i=0;i<100;++i){
	
		sAB+=c(t[i][0]);
		sBC+=c(t[i][1]);
		sCA+=c(t[i][2]);
	}
	for(int i=0;i<1000;++i){
		sABC+=c(tt[i]);
	}
	ans=sA+sB+sC-sAB-sBC-sCA+sABC;
	printf("%lld",ans);
}
