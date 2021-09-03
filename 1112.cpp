#include<bits/stdc++.h>
using namespace std;

int n,k;
int ans;
vector <int> slot;
bool visited[10002];
int solve(int x){
    if(x==n+1){
        int c=0;
        for(int i=0;i<slot.size();++i){
            for(int j=i+1;j<slot.size();++j){
                if(slot[i]>slot[j]){
                    ++c;
                }
            }
        }
        if(c==k){
            ++ans;
        }
    }else{
        for(int i=1;i<=n;++i){
            if(!visited[i]){
                visited[i]=true;
                slot.push_back(i);
                solve(x+1);
                visited[i]=false;
                slot.pop_back();
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    solve(1);
    printf("%d",ans);
}