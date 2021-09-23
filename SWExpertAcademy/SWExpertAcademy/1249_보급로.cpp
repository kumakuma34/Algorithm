#include<iostream>
#include <queue>
#include <string>

using namespace std;
#define MAX 100
#define INF 987654321
int map[MAX + 1][MAX + 1], dist[MAX + 1][MAX + 1];
int N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0, -1,1 };

void init() {
	for (int i = 0; i < MAX + 1; i++) {
		for (int j = 0; j < MAX + 1; j++) {
			dist[i][j] = INF;
		}
	}
}

void solve() {
	dist[0][0] = 0;
	queue<pair<int, int> > q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < N; j++) {
				map[i][j] = s[j] - '0';
			}
		}
		solve();
		cout << "#"<<test_case<<" "<<dist[N - 1][N - 1] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}