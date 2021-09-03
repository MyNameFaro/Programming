#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector <int> arr(n + 1,2e9);
	arr[0] = 0;
	int ans = 0;
	int x;
	for(int i = 1;i <= n;++i){
		scanf("%d",&x);
		int l = 1;int r = ans + 1;
		while(l <= r){
			int mid = (l + r)/2;
			if(x < arr[mid] && x > arr[mid - 1]){
				if(arr[mid] == 2e9) ++ans;
				arr[mid] = x;
				break;
			}else if(x == arr[mid]){
				break;
			}
			if(x < arr[mid]) r = mid - 1;
			if(x >= arr[mid]) l = mid + 1;
		}
	}
	printf("%d",ans);
}
