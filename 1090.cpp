#include <bits/stdc++.h>
using namespace std;
using lli = long long;
lli cnt[100002];
int main(){
	int N;
	scanf("%d",&N);
	int x , A;
	lli ans = 0;
	vector <int> arr;
	for(int i = 1;i <= N;++i){
		scanf("%d",&x);
		if(cnt[x] == 0) arr.push_back(x);
		++cnt[x];
	}
	scanf("%d",&A);
	sort(arr.begin() , arr.end());
	for(int i = 0;i < arr.size();++i){
		if(cnt[arr[i]]==0) continue;
		int find = A - arr[i];
		if(arr[i] == find){
			ans += (cnt[arr[i]] * (cnt[arr[i]] - 1))/2;
			cnt[arr[i]] = 0;
			continue;
		}
		int l = 0;int r = arr.size()-1;
		while(l <= r){
			int mid = (l + r)/2;
			if(arr[mid] == find){
				ans += (cnt[arr[i]] * cnt[find]);
				cnt[arr[i]] = 0;
				cnt[find] = 0;
				break;
			}
			if(arr[mid] > find) r = mid - 1;
			if(arr[mid] < find) l = mid + 1;
		}
	}
	printf("%lld",ans);
}
