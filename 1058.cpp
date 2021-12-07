#include<bits/stdc++.h>
using namespace std;
int lower(vector <int> &arr,int x){
	int ans=-2e9;
	int l=0,r=arr.size()-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(arr[mid]<x){
			ans=max(ans,arr[mid]);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int upper(vector <int> &arr,int x){
	int ans=2e9;
	int l=0,r=arr.size()-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(arr[mid]>x){
			ans=min(ans,arr[mid]);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
int func(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> rr[n+1],cc[m+1];
    char arr[n][m];
    for(int i=0;i<n;++i){
    	rr[i].push_back(-1);
	}
	for(int j=0;j<m;++j){
		cc[j].push_back(-1);
	}
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		scanf(" %c",&arr[i][j]);
    		if(arr[i][j]=='0'){
    			rr[i].push_back(j);
    			cc[j].push_back(i);
			}
		}
	}
	for(int i=0;i<n;++i){
    	rr[i].push_back(m);
	}
	for(int j=0;j<m;++j){
		cc[j].push_back(n);
	}
	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(arr[i][j]=='0') continue;
			int a=lower(rr[i],j);a=j-a;
			int b=upper(rr[i],j);b=b-j;
			int c=lower(cc[j],i);c=i-c;
			int d=upper(cc[j],i);d=d-i;
			ans=max(ans,max({a+b,a+c,a+d,b+c,b+d,c+d})-1);
		}
		//cout << endl;
	}
	return ans;
    
}
int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        printf("%d\n",func());
    }
}
