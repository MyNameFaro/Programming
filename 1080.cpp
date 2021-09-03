#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;cin >> N;
	if(N < 3){
		cout << N;
		return 0;
	}
	int arr[N + 1];arr[0] = 0;
	for(int i = 1;i <= N;++i) scanf("%d",&arr[i]);
	sort(arr , arr + N + 1);
	int ans = 0;
	for(int i = 2;i <= N;++i){
		int ts = arr[i] + arr[i - 1]; //sum of twoside less than
		int l = i + 1;int r = N;
		int mid = N;
		while(l <= r){
			mid = (l + r)/2;
			if(arr[mid] < ts && arr[mid + 1] >= ts) break;
			if(arr[mid] >= ts){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans , mid - i + 2);
	}
	printf("%d",ans);
}
