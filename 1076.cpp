#include <bits/stdc++.h>
using namespace std;
string num_1 = {' _ ','   ',' _ ',' _ ','   ',' _ ',' _ ',' _ ',' _ ',' _ '};
string num_2 = {'| |','  |',' _|',' _|','|_|','|_ ','|_ ','  |','|_|','|_|'};
string num_3 = {'|_|','  |','|_ ',' _|','  |',' _|','|_|','  |','|_|',' _|'};
int main(){
	int a , b;
	cin >> a >> b;
	string str;
	string a_[4] , b_[4];
	long long int num_a = 0, num_b = 0;
	int i , j , k , r;
		//cout << "\n";
		for(i = 0;i < 4;i++){
			getline(cin , str);
			a_[i] = str;
		}
		for(i = 0;i < 3*a;i+=3){
			cout << a_[1][i] << a_[1][i+1] <<a_[1][i + 2];
		}
		cout << endl;
		for(i = 0;i < 3*a;i+=3){
			cout << a_[2][i] << a_[2][i+1] <<a_[2][i + 2];
		}
		cout << endl;
		for(i = 0;i < 3*a;i+=3){
			cout << a_[3][i] << a_[3][i+1] <<a_[3][i + 2];
		}
		cout << endl;
		for(i = 0;i < 3*a;i+=3){
			for(j = 0;j < 30;j+=3){
				if(a_[1][i] == num_1[j] && a_[1][i + 1] == num_1[j + 1] && a_[1][i + 2] == num_1[j + 2]
				&& a_[2][i] == num_2[j] && a_[2][i + 1] == num_2[j + 1] && a_[2][i + 2] == num_2[j + 2]
				&& a_[3][i] == num_3[j] && a_[3][i + 1] == num_3[j + 1] && a_[3][i + 2] == num_3[j + 2]){
					cout <<"True\n";
					num_a= (num_a * 10) + (j / 3);
				}
			}
		}
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
		for(i = 0;i < 3*a;i+=3){
			for(j = 0;j < 30;j+=3){
				if(b_[1][i] == num_1[j] && b_[1][i + 1] == num_1[j + 1] && b_[1][i + 2] == num_1[j + 2]
				&& b_[2][i] == num_2[j] && b_[2][i + 1] == num_2[j + 1] && b_[2][i + 2] == num_2[j + 2]
				&& b_[3][i] == num_3[j] && b_[3][i + 1] == num_3[j + 1] && b_[3][i + 2] == num_3[j + 2]){
					cout <<"True\n";
					num_b= (num_b * 10) + (j / 3);
				}
			}
		}
		cout << num_a + num_b;
	//}
}
