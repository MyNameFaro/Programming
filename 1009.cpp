#include <bits/stdc++.h>
using namespace std;
string num_1[] = {" _ ","   "," _ "," _ ","   "," _ "," _ "," _ "," _ "," _ "};
string num_2[] = {"| |","  |"," _|"," _|","|_|","|_ ","|_ ","  |","|_|","|_|"};
string num_3[] = {"|_|","  |","|_ "," _|","  |"," _|","|_|","  |","|_|"," _|"};

bool check(char a , char b){
	printf("%d %d\n",a , b);
	printf("%c %c\n",a , b);
	if(a == 0 && b == 32){
		return  true;
	}else{
		if(a == b){
			return true;
		}else{
			return false;
		}
	}
}
int main(){
	int a , b;
	cin >> a >> b;
	//string str;
	char a_[4][32] , b_[4][32];
	long long int num_a = 0, num_b = 0;
	int i , j , k , r;
		//cout << "\n";
		for(i = 0;i < 4;i++){
			fgets(a_[i] ,32,stdin);
			//a_[i] = str;
		}
		//for(i = 1;i < 4;i++){
			printf("1 %d  %d ",a_[1][2] ,num_1[1][2]);
			printf("2 %d  %d ",a_[2][2],num_2[1][2]);
			printf("3 %d  %d ",a_[3][2],num_3[1][2]);
			//cout << endl;
		//}
		
		
		for(i = 0;i < 3*a;i+=3){
			for(j = 1;j <= 1;++j){
				if(check(a_[1][i] , num_1[j][0]) && check(a_[1][i + 1] , num_1[j][1]) && check(a_[1][i + 2] , num_1[j][2])
				&& check(a_[2][i] , num_2[j][0]) && check(a_[2][i + 1] , num_2[j][1]) && check(a_[2][i + 2] , num_2[j][2])
				&& check(a_[3][i] , num_3[j][0]) && check(a_[3][i + 1] , num_3[j][1]) && check(a_[3][i + 2] , num_3[j][2])){
					cout << j << endl;
					num_a= (num_a * 10) + j;
				}
			}
		}
		/*
		for(i = 0;i < 4;i++){
			getline(cin , str);
			b_[i] = str;
		}
		for(i = 0;i < 3*a;i+=3){
			cout << b_[1][i] << b_[1][i+1] <<b_[1][i + 2];
		}
		cout << endl;
		for(i = 0;i < 3*a;i+=3){
			cout << b_[2][i] << b_[2][i+1] <<b_[2][i + 2];
		}
		cout << endl;
		for(i = 0;i < 3*a;i+=3){
			cout << b_[3][i] << b_[3][i+1] <<b_[3][i + 2];
		}
		cout << endl;
		*/
		for(i = 0;i < 3*a;i+=3){
			for(j = 0;j <= 9;++j){
				if((b_[1][i] == num_1[j][0]) && (b_[1][i + 1] == num_1[j][1]) && (b_[1][i + 2] == num_1[j][2])
				&& (b_[2][i] == num_2[j][0]) && (b_[2][i + 1] == num_2[j][1]) && (b_[2][i + 2] == num_2[j][2])
				&& (b_[3][i] == num_3[j][0]) && (b_[3][i + 1] == num_3[j][1]) && (b_[3][i + 2] == num_3[j][2])){
					cout << j  << endl;
					num_b= (num_b * 10) + j;
				}
			}
		}
		cout << num_a + num_b;
	//}
}
