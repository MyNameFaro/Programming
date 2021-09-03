#include<bits/stdc++.h>
using namespace std;
int mod=10001;
int main(){
    int n;
    scanf("%d",&n);
    int table[n+1];
    table[0]=table[1]=1;
    for(int i=2;i<=n;++i){
        table[i]=0;
        for(int j=0;j<i/2;++j){
            table[i]+=(((table[j])*(table[i-j-1]))%mod)*2;
            table[i]%=mod;
        }
        if(i%2==1) table[i]+=(table[i/2]*table[i/2])%mod;
        table[i]%=mod;
    }
    printf("%d",table[n]);
}