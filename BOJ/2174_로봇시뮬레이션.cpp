#include <iostream>
#include <vector>
using namespace std;
struct Robot {
	int x;
	int y;
	int dir;
	//N: 0 , W : 1 , S : 2, E : 3
};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int A, B, N, M;
int map[101][101];
vector<Robot> v;
int main() {
	cin >> B >> A >> N >> M;
	int a, b;
	char dir;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> dir;
		if (dir == 'N') v.push_back({ a,b,0 });
		else if (dir == 'W') v.push_back({ a,b,1 });
		else if (dir == 'S') v.push_back({ a,b,2 });
		else if (dir == 'E') v.push_back({ a,b,3 });
		map[a][b] = i + 1;
	}

	bool flag = true;

	while (M--) {
		int now, cnt;
		char order;
		cin >> now >> order >> cnt;
		while (cnt--) {
			if (order == 'L') {//왼쪽으로 90도 회전
				v[now - 1].dir++;
				if (v[now - 1].dir >= 4) v[now - 1].dir -= 4;
			}
			else if (order == 'R') {//오른쪽으로 90도 회전
				v[now - 1].dir--;
				if (v[now - 1].dir < 0) v[now - 1].dir += 4;
			}
			else if (order == 'F') {//로봇이 향하고 있는 방향으로 한칸 이동
				int x = v[now - 1].x;
				int y = v[now - 1].y;
				int nx = x + dx[v[now - 1].dir];
				int ny = y + dy[v[now - 1].dir];
				if (nx <= 0 || nx > B || ny <= 0 || ny > A) {
					flag = false;
					cout << "Robot " << now << " crashes into the wall" << '\n';
					break;
				}
				else {
					map[x][y] = 0;
					v[now - 1].x = nx;
					v[now - 1].y = ny;
					if (map[nx][ny] == 0) {
						map[nx][ny] = now;
					}
					else {
						cout << "Robot " << now << " crashes into robot " << map[nx][ny] << "\n";
						flag = false;
						break;
					}
					//다른 로봇과 부딪히지 않았는지 검사
				}

			}
		}
		if (!flag) break;
	}
	if(flag) cout << "OK\n";

}