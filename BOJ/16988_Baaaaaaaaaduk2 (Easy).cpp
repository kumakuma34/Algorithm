#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans = 0;
int map[22][22];
int tmp[22][22];

bool visited[22][22];
bool visited2[22][22];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 }; //���� ��ġ
vector<pair<int,int>> candidate;//�� �ΰ��� ���� �� �ִ� �ĺ�����

void bfs(int i, int j) {
	vector<pair<int, int> > tmp;
	queue<pair<int, int> > q;
	q.push({ i,j });
	
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1) continue;
			if (map[nx][ny] == 0 && !visited[nx][ny]) { //��ĭ�̸� ���� ���ƾ� ������ �𸣴� ��
				cnt++;
				visited[nx][ny] = true;
				tmp.push_back({ nx,ny });
			}
			else if (map[nx][ny] == 2 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	for (int i = 0; i < tmp.size(); i++) {
		int x = tmp[i].first;
		int y = tmp[i].second;
		candidate.push_back({ x,y });
	}

}

int count(int i, int j) {//���� ���� �� ������ �׷��� �� ������ count
	queue<pair<int, int> > q;
	q.push({ i,j });

	int cnt = 0;
	bool flag = true;
	int zero_cnt = 0;

	while (!q.empty()) {
		if (!flag) break;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1) continue;
			if (tmp[nx][ny] == 0 ) { 
				zero_cnt++;//��ĭ�� ����
			}
			else if (tmp[nx][ny] == 2 && !visited2[nx][ny]) {
				visited2[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	if (zero_cnt > 0) return 0;//��ĭ�� �ϳ��� �����ϸ� ������ ���� �׷�
	else return cnt;
}
int main() {
	cin >> N >> M;
	
	//�׵θ� ��谪 1�� ����
	for (int i = 0; i <= M + 1; i++) map[0][i] = 1;
	for (int i = 0; i <= N + 1; i++) map[i][0] = 1;
	for (int i = 0; i <= N + 1; i++) map[i][M + 1] = 1;
	for (int i = 0; i < M + 1; i++) map[N + 1][i] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 2 && !visited[i][j]) {
				visited[i][j] = true;
				bfs(i, j);
			}
		}
	}
	//��ĭ �ĺ��� Ž��


	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			visited2[i][j] = false;
		}
	}

	//������ �ĺ��� �� �ΰ��� �����ϴ� ����Ž��
	for (int i = 0; i < candidate.size(); i++) {
		for (int j = 0; j < candidate.size(); j++) {
			int now = 0;
			if (i == j) continue;
			int x1 = candidate[i].first;
			int y1 = candidate[i].second;
			int x2 = candidate[j].first;
			int y2 = candidate[j].second;
			
			for (int x = 0; x <= N + 1; x++) {
				for (int y = 0; y <= M + 1; y++) {
					tmp[x][y] = map[x][y];
					visited2[x][y] = false;
				}
			}
			tmp[x1][y1] = 1;
			tmp[x2][y2] = 1;
			
			for (int x = 0; x <= N + 1; x++) {
				for (int y = 0; y <= M + 1; y++) {
					if (!visited2[x][y] && tmp[x][y] == 2) {
						visited2[x][y] = true;
						now += count(x, y);
					}
				}
			}
			if (ans < now) ans = now;

		}

	}
	cout << ans << endl;

}