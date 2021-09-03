#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;
int table[100002];
int main(){
	int N;
	cin >> N;
	int arr[N + 1];
	int total = 0;
	vector <pii> sort_arr;
	for(int i = 1;i <= N;++i){
		scanf("%d",&arr[i]);
		sort_arr.push_back({arr[i] , i});
		total += arr[i];
	}
	total /= 2;++total;
	sort(sort_arr.begin() , sort_arr.end());
	for(int i = 1;i <= N;++i){
		int quota = arr[i];
		int ans = 0;
		if(table[arr[i]] == 0){
			for(int j = sort_arr.size() - 1;j >= 0;--j){
				if(sort_arr[j].second == i) continue;
				quota += sort_arr[j].first;++ans;
				if(quota >= total) break;
			}
			table[arr[i]] = ans;
		}
		printf("%d\n",table[arr[i]]);
	}
	
}
