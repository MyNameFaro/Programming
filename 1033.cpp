#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , char>;

int visited[102][102];

int main(){
	int N , K;
	cin >> N >> K;
	vector <int> C (5 , 0);
	int P[4][2];
	P[0][0] = N;P[0][1] = 1;visited[N][1] = 1;
	P[1][0] = N;P[1][1] = N;visited[N][N] = 2;
	P[2][0] = 1;P[2][1] = N;visited[1][N] = 3;
	P[3][0] = 1;P[3][1] = 1;visited[1][1] = 4;
	priority_queue <pii ,vector <pii> ,greater<pii>> pq;
	for(int i = 0;i < 4;++i){
		for(int j = 0;j < K;++j){
			char x;
			cin >> x;
			pq.push({i + (4 * j), x});
		}
	}
	for(int kk = 0;kk < 4*K;++kk){
		int i = pq.top().first;i %= 4;
		char x = pq.top().second;pq.pop();
		int new_x = P[i][0], new_y = P[i][1];
		switch(x){
			case 'W':
				if(new_x > 1) --new_x;
				break;
			case 'E':
				if(new_x < N) ++new_x;
				break;
			case 'N':
				if(new_y > 1) --new_y;
				break;
			case 'S':
				if(new_y < N) ++new_y;
				break;
		}
		if(visited[new_x][new_y] < 1){
			visited[P[i][0]][P[i][1]] = -1 * (i + 1);
			P[i][0] = new_x;
			P[i][1] = new_y;
			visited[new_x][new_y] = (i + 1);
			//cout << i % 4 << " : " << new_x << " " << new_y << endl;
		}
	}
	for(int i = 1;i <= N;++i){
		for(int j = 1;j <= N;++j) ++C[abs(visited[j][i])];
	}
	for(int i = 1;i <= N;++i){
		for(int j = 1;j <= N;++j){
			if(visited[i][j] == 0){
				printf("No");
				return 0;
			}
		}
	}
	int mx = -2e9;int cnt = 0;
	for(int i = 1;i <= 4;++i) mx = max(mx , C[i]);
	for(int i = 1;i <= 4;++i){
		if(C[i] == mx) ++cnt;
	}
	printf("%d %d\n",cnt ,mx);
	for(int i = 1;i <= 4;++i){
		if(C[i] == mx) printf("%d\n",i);
	}
}
