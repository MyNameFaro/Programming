#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	for(int i=1;i<=N-(N/2);++i)
	{
		//top left
		for(int j=N-(N/2);j>=1;--j)
		{
			if(j == i)
			{
				printf("*");
			}else{
				printf("-");
			}
		}
		//top right
		for(int j=2;j<=N-(N/2);++j)
		{
			if(j == i)
			{
				printf("*");
			}else{
				printf("-");
			}
		}
	
		printf("\n");
	}
	for(int i=N/2;i>=1;--i)
	{
		//bottom left
		for(int j=N-(N/2);j>=1;--j)
		{
			if(j == i)
			{
				printf("*");
			}else{
				printf("-");
			}
		}
		//bottom right
		for(int j=2;j<=N-(N/2);++j)
		{
			if(j == i)
			{
				printf("*");
			}else{
				printf("-");
			}
		}
	
		printf("\n");
	}
}
