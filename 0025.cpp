#include <bits/stdc++.h>
using namespace std;

int main(){
	string a , b , c;
	char o;
	cin >> a;
	scanf(" %c",&o);
	cin >> b;
	if(b.size() > a.size()){
		c = b;
		b = a;
		a = c;
	}
	if(o == '+'){
		if(a.size() == b.size()){
			a[0] = '2';
		}else{
			a[a.size() - b.size()] = '1';
		}
		
		cout << a;
	}else{
		int i;
		printf("1");
		for(i = 1;i <= a.size() + b.size() - 2;i++){
			printf("0");
		}
	}
}
