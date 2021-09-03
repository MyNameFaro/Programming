#include <bits/stdc++.h>
using namespace std;
int arr[20][20];
int main(){
	int N;cin >> N;
	int ans = 0;
	for(int i = 1;i <= N;++i){
		for(int j = 1;j <= N;++j) cin >> arr[i][j];
	}
	for(int i = 1;i < N;++i){
		for(int j = 1;j < N;++j){
			int a = arr[i][j];int c = arr[i + 1][j];
			int b = arr[i][j + 1];int d = arr[i + 1][j + 1];
			int e = arr[i - 1][j];int f = arr[i - 1][j + 1];
			int g = arr[i][j - 1];int h = arr[i][j + 2];
			int m = arr[i + 1][j - 1];int n = arr[i + 1][j + 2];
			int k = arr[i + 2][j];int l = arr[i + 2][j + 1];
			
			if(a == b && b == c && a != d && (a != g) && a != e && c != m && c!= k && b != f && b != h){
				++ans;
			}else if(a == b && b == d && a != c && (a != g) && a != e && b != f && b != h && d != n && d != l){
				++ans;
			}else if(a == c && c == d && a != b && (a != g) && a != e && c != m && c!= k && d != n && d != l){
				++ans;
			}else if(b == c && c == d && b != a && b != f && b != h && c != m && c!= k && d != n && d != l){
				++ans;
			}
		}
	}
	cout << ans;
}
