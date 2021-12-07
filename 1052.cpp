#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int bs(int arr[][2],int n,int x,int mode=0){
	int ans=2e9;
	if(mode) ans=-2e9;
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(!mode){
			if(arr[mid][0]>x){
				ans=min(ans,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}else{
			if(arr[mid][0]<x){
				ans=max(ans,mid);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		
	}
	return ans;
}
int add(int seg[],int a,int n,int x){
	a+=n;
	while(a>0){
		seg[a]=max(seg[a],x);
		a/=2;
	}
}
int query(int seg[],int a,int b,int n){
	a=max(a,0)+n;
	b=min(b,n-1)+n;
	int ans=-2e9;
	while(a<=b){
		if(a%2==1) ans=max(ans,seg[a++]);
		if(b%2==0) ans=max(ans,seg[b--]);
		a/=2;
		b/=2;
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	int p[n][2];
	int DP[2][n];
	for(int i=0;i<n;++i){
		scanf("%d%d",&p[i][0],&p[i][1]);
	}
	int ans_left1=0,ans_right1=n-1;
	int ans_left2=0,ans_right2=0;
	//LEFT;
	int l=1;
	while(l--){
		int seg[2*n+1];
		for(int i=0;i<=2*n;++i) seg[i]=-2e9;
		for(int i=0;i<n;++i){
			int cnt=i-bs(p,n,p[i][0]-p[i][1]);
			DP[0][i]=cnt;
			if(cnt==0) continue;
			DP[0][i]=max(DP[0][i],i+query(seg,i-cnt,i-1,n));
			add(seg,i,n,DP[0][i]-i);
			if(DP[0][i]>ans_left2){
				ans_left2=DP[0][i];
				ans_left1=i;
			}
		}
	}
	//RIGHT
	int r=1;
	while(r--){
		int seg[2*n+1];
		for(int i=0;i<=2*n;++i) seg[i]=-2e9;
		for(int i=n-1;i>=0;--i){
			int cnt=bs(p,n,p[i][0]+p[i][1],1)-i;
			DP[1][i]=cnt;
			//cout << cnt << endl;
			if(cnt==0) continue;
			DP[1][i]=max(DP[1][i],-i+query(seg,i+1,i+cnt,n));
			add(seg,i,n,DP[1][i]+i);
			if(DP[1][i]>=ans_right2){
				ans_right2=DP[1][i];
				ans_right1=i;
			}
		}
	}
	/*for(int i=0;i<n;++i) printf("%d ",DP[0][i]);
	printf("\n");
	for(int i=0;i<n;++i) printf("%d ",DP[1][i]);
	printf("\n");*/
	if(ans_left2>ans_right2){
		printf("%d L",ans_left1+1);
	}else if(ans_left2<ans_right2){
		printf("%d R",ans_right1+1);
	}else{
		if(ans_left1<=ans_right1){
			printf("%d L",ans_left1+1);
		}else{
			printf("%d R",ans_right1+1);
		}
	}
}
