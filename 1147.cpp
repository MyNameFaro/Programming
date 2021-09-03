#include<bits/stdc++.h>
using namespace std;
int N;
int st[600000];
int query(int a,int b){
	a+=N;
	b+=N;
	int ans=-2e9;
	while(a<=b){
		if(a%2==1) ans=max(ans,st[a++]);
		if(b%2==0) ans=max(ans,st[b--]);
		a/=2;
		b/=2;
	}
	return ans;
}
void update(int a,int x){
	a+=N;
	st[a]=x;
	a/=2;
	while(a>=1){
		int pre=st[a];
		st[a]=max(st[2*a],st[2*a+1]);
		if(st[a]==pre) break;
		a/=2;
	}
}
int main(){
	int Q;
	int x,a,b;
	scanf("%d%d",&N,&Q);
	char c;
	while(Q--){
		scanf(" %c %d %d",&c,&a,&b);
		//cin >> c >> a >> b;
		if(c=='U'){
			update(a,b);
		}else{
			printf("%d\n",query(a,b));
		}
	}
	
}
