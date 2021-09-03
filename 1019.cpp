#include <iostream>
#include <string.h>
using namespace std;
typedef struct mark{
	int val = 0;
	int i = 0;
}MARK;
int main(){
	int a,b,i,j;
	MARK mark;
	char A[201],B[201];
	//INPUT
	cin >> A;
	cin >> B;
	//PROCESS
	a = strlen(A);
	b = strlen(B);
	int T[a + 1][b + 1];
	for(i = 0;i <= a;i++){
		T[i][0] = 0;
	}
	for(j = 0;j <= b;j++){
		T[0][j] = 0;
	}
	for(i = 1;i <= a;i++){
		for(j = 1;j <= b;j++){
			if(A[i-1] == B[j-1]){
				T[i][j] = T[i-1][j-1] + 1;
				if(T[i][j] > mark.val){
					mark.i = i;
					mark.val = T[i][j];
				}
			}else{
				T[i][j] = 0;
			}
		}
	}
	//OUTPUT
	for(i = mark.i - mark.val;i < mark.i ;i++){
		cout << A[i];
	}
}
