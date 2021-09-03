#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int n,m,i,j,t,ter;
	cin >> n >> m;
	int M[m];
	char I[n][m];
	for(i=0;i<n;i++){
		cin >> I[i];
	}
	for(j=0;j<m;j++){
		cin >> M[j];
	}
	for(j=0;j<m;j++){
		ter = n;
		for(i=0;i<n;i++){
			if(I[i][j]=='O'){
				ter = i;
				break;
			}
		}
		for(t=1;t<=M[j];t++){
			I[ter - t][j] = '#';
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout << I[i][j];
		}
		cout << "\n";
	}
}
