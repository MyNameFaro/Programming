#include <bits/stdc++.h>
using namespace std;
int main(){
	// UP RIGHT DOWN LEFT
	int x , y ,z;
	int n;
	scanf("%d",&n);
	string s;
	int i , j;
	int r , l , o , f , b , u , tmp;
	vector <int> ans;
	for(i = 0;i < n;++i){
		r = 4;
		l = 3; 
		o = 1;
		f = 2;
		u = 6;
		b = 5;
		
		cin >> s;
		for(j = 0;j < s.size();++j){
			switch(s[j]){
				case 'F':
					tmp = f;
					f = o;
					o = b;
					b = u;
					u = tmp;
					break;
				case 'B':
					tmp = f;
					f = u;
					u = b;
					b = o;
					o = tmp;
					break;
				case 'C':
					tmp = f;
					f = r;
					r = b;
					b = l;
					l = tmp;
					break;
				case 'D':
					tmp = f;
					f = l;
					l = b;
					b = r;
					r = tmp;
					break;
				case 'L':
					tmp = o;
					o = r;
					r = u;
					u = l;
					l = tmp;
					break;
				case 'R':
					tmp = o;
					o = l;
					l = u;
					u = r;
					r = tmp;
					break;
			}
		}
		ans.push_back(f);
	}
	for(i = 0;i < ans.size();++i){
		printf("%d ",ans[i]);
	}	
}
