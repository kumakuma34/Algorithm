#include <iostream>
using namespace std;
int n, m, k;
int map[101][101];
bool visited[101][101];
int ans = 0, cnt = 1;//ans : ����, cnt : dfs ���� Ž���� ����
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] , ny = y + dy[i];//���� Ž�� ����
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
	}//��ġ ���� �Է�

	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (visited[i][j] == false && map[i][j]) {//Ž������ ���� ���Ĺ��� ���
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