#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int map[9][9];
int ans[9][9];
int answer = 987654321;
vector<pair<int, pair<int, int>  >> cctvs;
vector<vector<int>> v;
//direct : 1> 왼쪽 , 2 > 오른쪽, 3> 위쪽, 4 : 아래쪽

void makeLeft(int i, int j) {
	for (int y = j - 1; y >= 0; y--) {
		if (ans[i][y] == 6) break;
		else if (ans[i][y] == 0) ans[i][y] = -1;
	}
	return;
}

void makeRight(int i, int j) {
	for (int y = j + 1; y < M; y++) {
		if (ans[i][y] == 6) break;
		else if (ans[i][y] == 0) ans[i][y] = -1;
	}
	return;
}

void makeUp(int i, int j) {
	for (int x = i - 1; x >= 0; x--) {
		if (ans[x][j] == 6) break;
		else if (ans[x][j] == 0) ans[x][j] = -1;
	}
	return;
}

void makeDown(int i, int j) {
	for (int x = i + 1; x < N; x++) {
		if (ans[x][j] == 6) break;
		else if (ans[x][j] == 0) ans[x][j] = -1;
	}
	return;
}

int countByWay(vector<int> ways) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < ways.size(); i++) {
		int dir = ways[i];
		int now = cctvs[i].first;
		int x = cctvs[i].second.first;
		int y = cctvs[i].second.second;
		if (now == 1) {
			if (dir == 1) makeLeft(x, y);
			else if (dir == 2) makeRight(x, y);
			else if (dir == 3) makeUp(x, y);
			else if (dir == 4) makeDown(x, y);
		}
		else if (now == 2) {
			if (dir == 1) {
				makeLeft(x, y);
				makeRight(x, y);
			}
			else if (dir == 2) {
				makeUp(x, y);
				makeDown(x, y);
			}
		}
		else if (now == 3) {
			if (dir == 1) {
				makeUp(x, y);
				makeRight(x, y);
			}
			else if (dir == 2) {
				makeUp(x, y);
				makeLeft(x, y);
			}
			else if (dir == 3) {
				makeDown(x, y);
				makeRight(x, y);
			}
			else if (dir == 4) {
				makeDown(x, y);
				makeLeft(x, y);
			}
		}
		else if (now == 4) {
			if (dir == 1) {
				makeUp(x, y);
				makeLeft(x, y);
				makeRight(x, y);
			}
			else if (dir == 2) {
				makeDown(x, y);
				makeLeft(x, y);
				makeRight(x, y);
			}
			else if (dir == 3) {
				makeRight(x, y);
				makeUp(x, y);
				makeDown(x, y);
			}
			else if (dir == 4) {
				makeLeft(x, y);
				makeUp(x, y);
				makeDown(x, y);
			}
		}
		else if (now == 5) {
			makeLeft(x, y);
			makeRight(x, y);
			makeUp(x, y);
			makeDown(x, y);
		}
		
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ans[i][j] == 0) cnt++;
		}
	}
	//cout << cnt << endl;
	return cnt;
}
void makeWays(int n, vector<int> v) {
	if (n == cctvs.size()) {
		int cnt = countByWay(v);
		/*for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << endl;*/
		if (answer > cnt) answer = cnt;
		return;
	}
	else {
		int now = cctvs[n].first;
		v.push_back(-1);
		if (now == 1 || now == 3 || now == 4) {
			for (int k = 1; k <= 4; k++) {
				v[n] = k;
				makeWays(n + 1, v);
			}
		}
		else if (now == 2) {
			for (int k = 1; k <= 2; k++) {
				v[n] = k;
				makeWays(n + 1, v);
			}
		}
		else if (now == 5) {
			v[n] = 1;
			makeWays(n + 1, v);
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			ans[i][j] = map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) cctvs.push_back({ map[i][j], {i,j} });
		}
	}
	if (cctvs.size() == 0) {
		answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 6) answer++;
			}
		}
	}
	vector<int> v; 
	makeWays(0, v);

	cout << answer;
}