#include <iostream>
#include <queue>
#define MAX 987654321
using namespace std;

int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
//���� �� �� �ִ� 8���� ��ġ
int adj_x[4] = { -1,1,0,0 };
int adj_y[4] = { 0,0,-1,1 };
//�����ؼ� �� �� �ִ� �� ��

int K, W, H;
int map[201][201];
int dist[201][201][31];//dist[x][y][k] : x,y�� k���� �̵����� ������ �� �ִ� �ּ� Ƚ��
int main() {
	cin >> K >> W >> H;
	for (int i = H; i >=1 ; i--) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			for (int k = 0; k < 31; k++) {
				dist[i][j][k] = MAX;
			}
		}
	}
	queue<pair<pair<int, int>,int> > q;
	dist[H][1][0] = 0;//���� ���� ���� ��
	q.push({ { H,1 },0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		//���� �̵��ϵ��� �̵�
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (nx <1 || nx > H || ny < 1 || ny > W || map[nx][ny] == 1) continue;//�̵� �Ұ����� ��
			if (dist[nx][ny][cnt + 1] > dist[x][y][cnt] + 1 && cnt + 1 <= K) {
				dist[nx][ny][cnt + 1] = dist[x][y][cnt] + 1;
				q.push({ {nx,ny},cnt + 1 });
			}
		}

		//������ �� �̵�
		for (int k = 0; k < 4; k++) {
			int nx = x + adj_x[k];
			int ny = y + adj_y[k];
			if (nx <1 || nx > H || ny < 1 || ny > W || map[nx][ny] == 1) continue;//�̵� �Ұ����� ��
			if (dist[nx][ny][cnt] > dist[x][y][cnt] + 1) {
				dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
				q.push({ {nx,ny},cnt});
			}
		}

	}
	int ans = MAX;
	for (int i = 0; i <= K; i++) {
		if (ans > dist[1][W][i]) ans = dist[1][W][i];
	}
	if (ans == MAX) cout << "-1" << '\n';
	else cout << ans << endl;
}