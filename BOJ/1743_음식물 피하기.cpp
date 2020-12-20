#include <iostream>
using namespace std;
int n, m, k;
int map[101][101];
bool visited[101][101];
int ans = 0, cnt = 1;//ans : 정답, cnt : dfs 깊이 탐색용 변수
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] , ny = y + dy[i];//다음 탐색 지점
		if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
			if (visited[nx][ny] == false && map[nx][ny]) {
				visited[nx][ny] = true;
				cnt++;
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		map[x][y] = 1;
	}//위치 정보 입력

	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (visited[i][j] == false && map[i][j]) {//탐색하지 않은 음식물일 경우
				cnt = 1;
				visited[i][j] = true;
				dfs(i, j);
				if (cnt > ans)
					ans = cnt;
			}
		}
	}
	cout << ans << endl;

}