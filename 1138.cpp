#include<bits/stdc++.h>

#define forr(i , n) for(int i=1;i<=(n);++i)
#define rforr(i , n) for(int i=(n);i>=1;--i)
#define NN (int) 1e5+10

using namespace std;
using pii=pair<int,int>;

int seg[2 * NN] , DP[NN] ,A[NN] , X[NN] , n_idx[NN]; //n_idex = new index after sorting
pii line[NN];

int query(int a,int b)
{
    int ans = 0;
    if(a > b) return 0;
    if(a % 2 == 1) ans = max(ans , seg[a++]);
    if(b % 2 == 0) ans = max(ans , seg[b--]);
    ans = max(ans , query(a/2,b/2));
    return ans;
}
int upper(int x,int N)
{
    int ans = N;
    int l=1,r=N;
    while(l <= r)
    {
        int mid=(l+r)/2;
        if(line[mid].first >= x)
        {
            ans = min(ans , mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}
int lower(int x,int N)
{
    int ans = 1;
    int l=1,r=N;
    while(l <= r)
    {
        int mid=(l+r)/2;
        if(line[mid].first <= x)
        {
            ans = max(ans , mid);
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}
void add(int a,int x,int N)
{
    a += N;
    seg[a] = x;
    for(int i=a/2;i>=1;i/=2)
    {
        seg[i] = max(seg[2*i] , seg[2*i + 1]);
    }
}
int main()
{
    int N,K,S;
    scanf("%d%d%d",&N ,&K,&S);
    forr(i, N)
    {
        scanf("%d%d",&X[i] , &A[i]);
        line[i] = make_pair(X[i] , i);
    }
    sort(line + 1,line + N + 1);
    forr(i, N)
    {
        n_idx[line[i].second] = i;
    }
    rforr(i , N)
    {
        DP[i] =A[i] + query(upper(X[i] - K,N) + N, lower(X[i] + K,N) + N);
        add(n_idx[i] , DP[i] , N);
    }
    printf("%d" , query(upper(S - K,N) + N, lower(S + K,N) + N));
}
