#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[301][301];
int nearByCnt[301][301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[301][301];

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/// <summary>
/// 빙산이 모두 녹았는지 확인하는 함수
/// </summary>
/// <returns>
/// 모두 0이면 true / 모두 없으면 false
/// </returns>
bool allZero() {
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (!flag) break;
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int > > q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (visited[nx][ny] == false && map[nx][ny] != 0) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}
/// <summary>
/// 빙산이 두개로 분리되었는지 확인하는 함수
/// </summary>
/// <returns>
/// 빙산이 두개 이상이면 true, 하나이면 false
/// </returns>
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}//초기화

	int cnt = 0;//빙산 개수
	bool result = false;
	for (int i = 0; i < N; i++) {
		if (result) break;
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0 && !visited[i][j]) {
				if (cnt == 1) {
					result = true;
					break;
				}
				cnt++;
				bfs(i, j);
			}
		}
	}
	return result;
}
/// <summary>
/// 년 단위 빙산 모양 계산 함수
/// </summary>
void makeTimePass() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			nearByCnt[i][j] = 0;
		}
	}

	//빙산에 인접한 바다의 개수 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (map[nx][ny] == 0) nearByCnt[i][j]++;
			}
		}
	}

	//인접한 빙산 개수만큼 감소 시킴.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] -= nearByCnt[i][j];
			if (map[i][j] < 0) map[i][j] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;

	while (1) {
		makeTimePass();
		ans++;
		if (check()) break;
		if (allZero()) {
			ans = 0;
			break;
		}
	}
	cout << ans << endl;
}