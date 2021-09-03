#include <bits/stdc++.h>
using namespace std;
int main(){
	int l , i , r , n;
	scanf("%d",&l);
	scanf("%d",&n);
	bool lack = false;
	int ll;
	string a , b;
	cin >> a;
	b = a;
	for(r = 2;r <= n;r++){
		cin >> a;
		if(!lack){
			ll = 0;
			for(i = 0;i < a.size();i++){
				if(a[i] != b[i]){
					ll++;
				}
				
			}
			if(ll > 2){
				lack = true;
			}else{
				b = a;
			}
			
		}
	}
	cout << b;
}
