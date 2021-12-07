#include<bits/stdc++.h>
using namespace std;
int func(){
    int n,m;
    int ans=-2e9;
    scanf("%d%d",&n,&m);
    set <int> rr[n],cc[m];
    for(int i=0;i<n;++i){
        rr[i].insert(-1);
        rr[i].insert(m);
    }
    for(int j=0;j<m;++j){
        cc[j].insert(-1);
        cc[j].insert(n);
    }
    for(int i=0;i<n;++i){
        char s[m+1];
        scanf("%s",s);
        for(int j=0;j<m;++j){
            if(s[j]=='0'){
                rr[i].insert(j);
                cc[j].insert(i);
            }
        }
    }
    
   
            int rmax=*lower_bound(rr[0].begin(),rr[0].end(),4);
            int rmin=*upper_bound(rr[0].begin(),rr[0].end(),3);
            int cmax=*lower_bound(cc[4].begin(),cc[4].end(),0);
            int cmin=*upper_bound(cc[4].begin(),cc[4].end(),-1);

		cout << rmin << " " << rmax << endl;
		cout << cmin << " " << cmax << endl;

        printf("\n");

    return ans;
}
int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        printf("%d\n",func());
    }
}