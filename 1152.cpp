#include <iostream>
#include <stdbool.h>
using namespace std;
typedef struct prop{
	int i;
	int val;
}prop;
int main(){
	int n;
	bool sort = true;
	cin >> n;
	int i , j;
	long long int total = 0;
	prop tmp;
	prop order[n * n];
	prop *ptr;
	ptr = &order[0];
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			cin >> ptr->val;
			ptr->i = i + j;
			ptr++;
		}
	}
	while(sort){
		sort = false;
		for(i = 0;i < (n * n)-1 ;i++){
			if(order[i].val < order[i+1].val){
				tmp = order[i];
				order[i] = order[i+1];
				order[i+1] = tmp;
				sort = true;
			}
		}
	}
	for(i = 0;i < (n * n);i++){
		cout << order[i].val << " "<< order[i].i << "\n";
	}
	for(i = 0;i < 25 ;i++){
		for(j = 0;j < (n*n);j++){
			if(order[j].i > i && order[j].val != 0){
				cout << order[j].val << " " << order[j].i;
				cout << "\n";
				total += order[j].val;
				order[j].val = 0;
				break;
			}
		}
	}
	cout << total;
}
