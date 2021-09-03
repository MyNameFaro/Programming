#include<bits/stdc++.h>
using namespace std;
int cnt_g['z'+3];
int cnt_s['z'+3];
int main(){
	int g,s;
	string G,S;
	scanf("%d%d",&g,&s);
	cin>>G;
	cin>>S;
	int ans=0;
	
	for(auto c:G){
		++cnt_g[c];
	}
	for(int i=0;i<g;++i){
		++cnt_s[S[i]];
	}
	for(int i=0;i<=s-g;++i){
		if(i>0){
			--cnt_s[S[i-1]];
			++cnt_s[S[i+g-1]];
		}
		bool check=true;
		for(auto c:G){
			if(cnt_s[c]!=cnt_g[c]) check=false;
			if(!check) break;
		}
		if(check) ++ans;
	}
	cout << ans;
}
