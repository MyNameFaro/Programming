#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int p[n+1],c[n+1];
    int aim=0;
    for(int i=0;i<k;++i){
        aim = (aim<<1);
        aim=aim|1;
    }
    int table[n+1][aim + 1];
    
    for(int i=1;i<=n;++i){
        scanf("%d",&p[i]);
        c[i]=0;
        for(int j=0;j<k;++j){
            int x;
            scanf("%d",&x);
            c[i]=c[i]|(x<<j);
        } 
    }
    //for(int i=1;i<=n;++i) printf("%d ",c[i]);
    for(int j=aim;j>=0;--j){
        for(int i=0;i<=n;++i){
            if(j==aim and i==0){
                table[i][j]=0;
                continue;
            }
            if(i==0){
                table[i][j]=2e9;
                continue;
            }
            table[i][j]=min(p[i]+table[i-1][(j|c[i])] , table[i-1][j]);
        }
    }
    printf("%d",table[n][0]);
}