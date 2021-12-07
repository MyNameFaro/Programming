#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int slug[2500];
pii PQ[1500000];
int main()
{
	int N,x,t;
	int ans=0;
	scanf("%d",&N);
	
	int cur=1;
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			scanf("%d",&PQ[cur].first);
			PQ[cur].second=i+j-2;
			++cur;
		}
	}
	sort(PQ + 1, PQ + 1 + (N*N));
	int cnt=0;
	for(int j=N*N;j>=1;--j)
	{
		for(int i=PQ[j].second-1;i>=0;--i)
		{
			if(PQ[j].first > slug[i])
			{
				ans+=PQ[j].first;
				slug[i]=PQ[j].first;
				++cnt;
				if(cnt == (N-1)*2)
				{
					printf("%d",ans);
					return 0;
				}
				break;
			}
		}
	}
	
}
