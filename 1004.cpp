#include <bits/stdc++.h>
using namespace std;

int data[100001];

int main(){
	list <int> l;
	int nc , ns , c , s;
	int i ;
	scanf(" %d %d",&nc ,&ns);
	for(i = 0;i < ns;i++){
		scanf(" %d %d",&c ,&s);
		data[s] = c;
	}
	char ch;
	bool doing = true;
	bool check = true;
	while(doing){
		scanf("%c",&ch);
		switch(ch){
			case 'E':
				scanf("%d" ,&s);
				if(l.size() == 0){
					l.push_back(s);
				}else{
					check = true;
					for(auto it = l.rbegin() ; it != l.rend() ;it++){
						if(data[*it] == data[s]){
							l.insert(it.base(), s);
							check = false;
							break;
						}
					}
					if(check){
						l.push_back(s);
					}
				}
				/*for(auto it = l.begin() ; it != l.end() ;it++){
						cout << *it << " ";
					}
				cout << endl;*/
				break;
			case 'D' :
				if(l.size() == 0){
					printf("empty\n");
				}else{
					printf("%d\n",*(l.begin()));
					l.erase(l.begin());
				}
				break;
			case 'X' :
				printf("0");
				doing = false;
		}
	}
}
