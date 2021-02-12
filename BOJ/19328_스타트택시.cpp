#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987564321
using namespace std;
int N, M, fuel;
int map[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int x, y;//택시의 현재 위치
vector<pair<int, int> > from;
vector<pair<int, int> > to;
bool done[40001];

void initDist(int x, int y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == x && j == y) map[i][j] = 0;
			else if (map[i][j] != -1) map[i][j] = INF;
		}
	}
}
//현재위치부터 최소 거리 계산 함수
void getMinDist(int x, int y) {
	initDist(x, y);
	queue<pair<int, int> > q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (map[nx][ny] > map[x][y] + 1) {
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> N >> M >> fuel;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}
	cin >> x >> y;
	x--; y--;
	int a, b, c, d;
	for(int i = 0 ; i<M ;i ++) 
	{
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		from.push_back({ a,b });
		to.push_back({ c,d });
	}

	int cnt = 0;//처리한 승객의 개수
	bool flag = true;//요청을 다 처리했는지 여부
	while (1) {
		if (cnt == M) break;
		getMinDist(x, y);
		vector < pair<pair<int, pair<int, int> > , int> > v;
		for (int i = 0; i < M; i++) {
			if (done[i]) continue;
			int fromX = from[i].first;
			int fromY = from[i].second;
			v.push_back({ { map[fromX][fromY], {fromX, fromY} },i });
		}
		sort(v.begin(),v.end());
		int nowX = v[0].first.second.first;
		int nowY = v[0].first.second.second;
		int now = v[0].second;
		//여기까지가 이번 턴에 처리해야될 승객 번호를 구한 것

		if (fuel < map[nowX][nowY]) {
			flag = false;
			break;
		}
		fuel -= map[nowX][nowY];
		x = nowX; y = nowY;
		getMinDist(x, y);
		if (fuel < map[to[now].first][to[now].second]) {
			flag = false;
			break;
		}
		fuel += map[to[now].first][to[now].second];
		x = to[now].first;
		y = to[now].second;

		done[now] = true;
		cnt++;

	}
	
	if (flag) cout << fuel << endl;
	else cout << "-1" << endl;
	

}
