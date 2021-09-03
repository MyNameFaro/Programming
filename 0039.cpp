#include <bits/stdc++.h>
using namespace std;

int n = 1, m;

vector <int> a , b;



void f(){
	int  j ,i;
	for(i = 1;i <= n;i++){
		if(a.empty()){
			if(find(b.begin() , b.end() ,i) == b.end()){
				a.push_back(i);
				f();
				a.pop_back();
			}
		}else{
			if(find(a.begin() , a.end() ,i) == a.end()){
				a.push_back(i);
				if(a.size() == n){
					//sort();
					cout << n << endl;
					for(j = 0;j < n;j++){
						printf("%d ",a[j]);
					}
					printf("\n");
				}else{
					f();
				}
				
				a.pop_back();
			}
		}
	}
}

int main(){
	int i , x;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i = 0;i < m;i++){
		scanf("%d",&x);
		b.push_back(x);
	}
	f();
	
	cout << "HEY";
}
