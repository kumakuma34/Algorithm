#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, N;
vector<int> job;
int map[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[101][101];

void print() {
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
void dfs(int x, int y, int num) {
	queue<pair<int, int > > q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx > R || nx <1 || ny > C || ny < 1) continue;
			if (map[nx][ny] != 0 && visited[nx][ny] == false) {
				map[nx][ny] = num;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
void makeCluster() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}
	int cnt = 1;//clsuter count number;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] != 0 && visited[i][j] == false) {//미네랄이 있는 위치
				map[i][j] = cnt;
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}
}
int main() {
	cin >> R >> C;
	for (int i = R; i >= 1; i--) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '.') map[i][j + 1] = 0;
			else if (s[j] == 'x') map[i][j + 1] = -1;
		}
	}
	for (int i = 1; i <= C; i++) {
		map[0][i] = 102;
	}//바닥 설정

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		job.push_back(tmp);
	}
	makeCluster();


	for (int cnt = 0; cnt < N; cnt++) {
		//cout << job[i] << " : " << endl;
		//print();

		bool flag = false;
		int fall_cluster;
		int now = 0;
		if (cnt % 2 == 0) { //왼쪽에서 오른쪽으로 
			for (int j = 1; j <= C; j++) {
				if (map[job[cnt]][j] != 0) {
					now = map[job[cnt]][j];
					map[job[cnt]][j] = 0;//미네랄 캠
					makeCluster();
					for (int k = 0; k < 4; k++) {
						int nx = job[cnt] + dx[k];
						int ny = j + dy[k];
						if (nx > R || nx <1 || ny > C || ny < 1) continue;
						if (map[nx][ny] != 0) {
							if (now != map[nx][ny]) {//클러스터가 분리된 경우
								//cout << i << " : " << "분리됨!" << endl;
								fall_cluster = map[nx][ny];
								flag = true;
							}
						}
					}
					break;
				}
			}


		}
		else {//오른쪽에서 왼쪽으로 
			for (int j = C; j >= 1; j--) {
				if (map[job[cnt]][j] != 0) {
					now = map[job[cnt]][j];
					map[job[cnt]][j] = 0;//미네랄 캠
					makeCluster();
					for (int k = 0; k < 4; k++) {
						int nx = job[cnt] + dx[k];
						int ny = j + dy[k];
						if (nx > R || nx <1 || ny > C || ny < 1) continue;
						if (map[nx][ny] != 0) {
							if (now != map[nx][ny]) {//클러스터가 분리된 경우
								flag = true;
								fall_cluster = map[nx][ny];

								//cout << i<<" : " <<"분리됨!" << endl;
							}
						}
					}
					break;
				}
			}
		}

		if (!flag && job[cnt] == 1) {//공중에서 떴는지 확인
			bool tmp_flag = false;
			for (int j = 1; j <= C; j++) {
				if (map[1][j] == now) {
					tmp_flag = true;
					break;
				}
			}
			if (!tmp_flag) {
				flag = true;
				fall_cluster = now;
			}
		}

		if (flag) {//클러스터가 분리된 경우 
			//cout<< "분리됨" << endl;
			int bottom;
			int move = 101;//아래로 평행이동 해야하는 칸의 수 
			int tmp = 0;
			for (int i = R; i >= 1; i--) {
				for (int j = 1; j <= C; j++) {
					if (map[i][j] == fall_cluster) {
						bottom = i;
						break;
					}
				}
			}
			//cout << "bottom : " << bottom << endl;
			for (int i = 1; i <=R ; i++) {
				for (int j = 1; j <= C; j++) {
					if (map[i][j] == fall_cluster) {
						int tmp = 1;
						while (i - tmp >= 0) {
							if (map[i - tmp][j] != 0 && map[i-tmp][j] != fall_cluster) {
								move = min(tmp, move);
								break;
							}
							else tmp++;
						}
					}
				}
			}
			
			//cout << "움직여야 하는 칸의 수 : " << move<< endl;
			move--;
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					if (map[i][j] == fall_cluster) {
						if (map[i - move][j] == 0) {
							map[i - move][j] = fall_cluster;
							map[i][j] = 0;
						}
					}
				}
			}
			makeCluster();
		}
		
	}
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 0)
				cout << ".";
			else
				cout << "x";
		}
		cout << endl;
	}


}