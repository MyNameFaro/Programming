#include <bits/stdc++.h>
using namespace std;

int main(){
	int K , N;
	cin >> K >> N;
	int ans = 0;
	for(int i = 0;i < N;++i){
		int a = i;int b = i + 1;
		int c = a^b ;int d = 1;
		//cout << c << endl;
		for(int r = 1;r <= K;++r){
			if((c & d) > 0) ++ans;
			d *= 2;
		}
	}
	cout << ans;
}
