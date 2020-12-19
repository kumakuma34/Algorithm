#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, ans;
int map[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> v;

void bfs(int x, int y) {
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny] == 0){
				map[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	v.push_back(cnt);
	return;
}
int main() {
	cin >> m >> n >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				map[i][j] = 1;
			}
		}
	}//직사각형 존재 위치 1 표시 

	//BFS 탐색, BFS가 도는 횟수 => 직사각형이 존재하지 않는 분리된 위치
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				ans++;
				map[i][j] = 1;
				bfs(i, j);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		cout << v[i] << ' ';
	}
	cout << endl;


}