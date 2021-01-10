#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
bool isDragonCurve[101][101];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };//0,1,2,3 방향에 따라 이동
int main() {
	cin >> N;
	int x, y, d, g;
	while (N--) {
		cin >> y >>x >> d >> g;
	
		vector<int> v;
		isDragonCurve[x][y] = true;

		int end_x = x + dx[d];
		int end_y = y + dy[d];
		isDragonCurve[end_x][end_y] = true;
		//cout << end_x << " , " << end_y << endl;
		v.push_back(d);
		for (int i = 0; i < g; i++) {
			int sz = (int)v.size();
			for (int j = sz - 1; j >= 0; j--) {
				int dir = (v[j] + 1) % 4;
				//cout << dir << " : ";

				end_x += dx[dir];
				end_y += dy[dir];

				isDragonCurve[end_x][end_y] = true;
				//cout << end_x << " ," << end_y << endl;
				v.push_back(dir);
			}
		}
	}


	int ans = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (isDragonCurve[i][j] && isDragonCurve[i + 1][j] && isDragonCurve[i][j + 1] && isDragonCurve[i + 1][j + 1]) ans++;

		}
	}
	cout << ans << endl;
	/*for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (isDragonCurve[i][j]) cout << i << ", " << j << endl;
		}
	}*/
}