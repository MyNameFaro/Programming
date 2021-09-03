#include<bits/stdc++.h>
using namespace std;
int table[3][4][4][4][4];
bool cnt[2][4];
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;++i){
        char c;
        scanf(" %c",&c);
        if(c=='M'){
            arr[i]=1;
        }else if(c=='F'){
            arr[i]=2;
        }else if(c=='B'){
            arr[i]=3;
        }
    }
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<=3;++j){
            for(int k=0;k<=3;++k){
                for(int l=0;l<=3;++l){
                    for(int m=0;m<=3;++m){
                        cnt[0][j]=true;
                        cnt[0][k]=true;
                        cnt[0][arr[i]]=true;
                        cnt[1][l]=true;
                        cnt[1][m]=true;
                        cnt[1][arr[i]]=true;
                        table[1][j][k][l][m]=max(
                            (int)cnt[0][1]+(int)cnt[0][2]+(int)cnt[0][3] + table[2][k][arr[i]][l][m],
                            (int)cnt[1][1]+(int)cnt[1][2]+(int)cnt[1][3] + table[2][j][k][m][arr[i]]
                        );
                        cnt[0][0]=cnt[0][1]=cnt[0][2]=cnt[0][3]=false;
                        cnt[1][0]=cnt[1][1]=cnt[1][2]=cnt[1][3]=false;
                    }
                }
            }
        }
        for(int j=0;j<=3;++j){
            for(int k=0;k<=3;++k){
                for(int l=0;l<=3;++l){
                    for(int m=0;m<=3;++m){
                        table[2][j][k][l][m]=table[1][j][k][l][m];
                    }
                }
            }
        }
    }
    printf("%d",table[1][0][0][0][0]);
}