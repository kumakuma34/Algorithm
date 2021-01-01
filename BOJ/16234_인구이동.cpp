#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N, L, R;
int map[51][51];
int area[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int > > q;
pair<int, int> people[2501]; //first : 인구 합 , second : 영역개수
bool flag = false;

void bfs(int i, int j) {
	q.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (abs(map[x][y] - map[nx][ny]) >= L && abs(map[x][y] - map[nx][ny]) <= R && area[nx][ny] == 0) {
				flag = true;
				area[nx][ny] = area[x][y];
				q.push({ nx,ny });
			}
		}
	}
	return;
}
int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	int ans = 0;
	while (1) {
		int now = 1;
		flag = false;
		for(int i = 0 ; i <2501 ; i++)	people[i] = { 0,0 };

		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				area[i][j] = 0;
			}
		}
	
		//국경 해제 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (area[i][j] == 0) {
					area[i][j] = now;
					bfs(i, j);
					now++;
				}
			}
		}

		if (!flag) break;
		ans++;

		//인구이동
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int now = area[i][j];
				people[now].first += map[i][j];
				people[now].second++;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = people[area[i][j]].first / people[area[i][j]].second;
			}
		}
	
	}
	cout << ans << endl;

}