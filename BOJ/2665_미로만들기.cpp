#include <iostream>
#include <queue>
#include <string.h>
#define INF 987564321
using namespace std;

int N;
int map[51][51], dist[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			map[i][j] = (int)tmp[j] - 48;
			//cout << map[i][j] << " ";
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cin >> map[i][j];
			dist[i][j] = INF;
		}
	}
	
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
			if (map[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.push({ nx,ny });
				}
			}
			else {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			
		}
	}
	cout << dist[N - 1][N - 1] << endl;

}