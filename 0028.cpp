#include<bits/stdc++.h>
using namespace std;
struct Node{
	int id=0;
	int point=0;
	int goal=0;
	int ungoal=0;
};
Node node[5];
bool Compare(Node &a,Node &b){
	if(a.point!=b.point) return a.point>b.point;
	if((a.goal-a.ungoal)!=(b.goal-b.ungoal)) return (a.goal-a.ungoal)>(b.goal-b.ungoal);
	return a.goal>b.goal;
}
int main(){
	string s[5];
	for(int i=1;i<=4;++i) cin>>s[i];
	int arr[5][5];
	for(int i=1;i<=4;++i){
		node[i].id=i;
		for(int j=1;j<=4;++j) scanf("%d",&arr[i][j]);
	}
	for(int i=1;i<=4;++i){
		for(int j=1;j<=4;++j){
			if(i==j) continue;
			if(arr[i][j]>arr[j][i]){
				node[i].point+=3;
			}else if(arr[i][j]==arr[j][i]){
				node[i].point+=1;
			}
			node[i].goal+=arr[i][j];
			node[j].ungoal+=arr[i][j];
		}
	}
	sort(node+1,node+5,Compare);
	for(int i=1;i<=4;++i){
		cout << s[node[i].id] << " " << node[i].point << endl;
	}
}
