#include <bits/stdc++.h>
using namespace std;
int factor[100002];
int main(){
	vector <int> p ,vf;
	bool prime = false;
	int i , x , j , n;
	long int lcd = 1;
	p.push_back(2);
	for(i = 3;i <= 99997;i += 2){
		prime = true;
		for(x = 3;x <= sqrt(i);x++){
			if(i % x == 0){
				prime = false;
				break;
			}
		}
		if(prime){
			p.push_back(i);
		}
	}
	scanf("%d",&n);
	for(i = 1;i <= n;i++){
		scanf("%d",&x);
		vf.assign(100002 , 0);
		while(x >= 2){
			for(j = 0;j < p.size();j++){
				if(x % p[j] == 0){
					//cout << p[j] << " ";
					x /= p[j];
					vf[p[j]]+=1;
					break;
				}
			}
		}
		for(j = 0;j < p.size();j++){
			factor[p[j]] = max(factor[p[j]] , vf[p[j]]);
		}
		vf.clear();
		//cout << endl;
	}
	for(i = 0;i < p.size();i++){
		lcd *= pow(p[i] , factor[p[i]]);
	}
	printf("%ld",lcd);
}
