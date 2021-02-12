#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[101][101];
int visited[101];
vector<int> v[101];
bool checkEmtpy(int x) {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (i == x) continue;
		if (map[x][i] == 0) flag = true;
	}
	return flag;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	bool flag = true;//안정된 집단인지 판단하는 flag
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		if (!checkEmtpy(i)) {
			flag = false;
			break;
		}
		if (!flag) break;
		if (visited[i]) continue;
		visited[i] = cnt;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (map[i][j] == 0) {
				if (visited[j] != 0 && visited[j] != cnt) {
					flag = false;
					break;
				}
				else {
					visited[j] = cnt;
				}
			}
		}
		cnt++;
	}

	if (flag) {
		for (int i = 0; i < N; i++) {
			v[visited[i]].push_back(i + 1);
		}
		int ans = 0;
		for (int i = 0; i < 101; i++) {
			if (v[i].empty()) continue;
			ans++;
			sort(v[i].begin(), v[i].end());
		}
		cout << ans << '\n';
		vector<pair<int, int> > order;
		for (int i = 0; i < 101; i++) {
			if (v[i].empty()) continue;
			order.push_back({ v[i][0],i });
		}
		for (int i = 0; i < order.size(); i++) {
			for (int j = 0; j < v[order[i].second].size(); j++) {
				cout << v[order[i].second][j] << " ";
			}
			cout << "\n";
		}
	}
	else
		cout << "0\n";
	

}