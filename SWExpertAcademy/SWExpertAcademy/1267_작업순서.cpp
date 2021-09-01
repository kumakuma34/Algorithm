#include<iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> map[1001];
int cnt[1001];//선행되어야 될 작업의 수
bool visit[1001];
void init() {
	for (int i = 0; i < 1001; i++) {
		map[i].clear();
		cnt[i] = 0;
		visit[i] = false;
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int V, E;
	//freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> V >> E;
		int from, to;
		for (int i = 0; i < E; i++) {
			cin >> from >> to;
			map[from].push_back(to);
			cnt[to]++;
		}

		vector<int> ans;
		queue<int> q;
		for (int i = 1; i <= V; i++) {
			if (cnt[i] == 0) {
				q.push(i);
				visit[i] = true;
			}
		}

		cout << "#" << test_case << " ";

		while (!q.empty()) {
			int now = q.front();
			cout << now << " ";
			q.pop();
			ans.push_back(now);

			for (int i = 0; i < map[now].size(); i++) {
				int next = map[now][i];
				cnt[next]--;
				if (cnt[next] == 0) {
					q.push(next);
					visit[next] = true;
				}
			}

			for (int i = 1; i <= V; i++) {
				if (cnt[i] == 0 && !visit[i]) {
					q.push(i);
					visit[i] = true;
				}
			}
		}
		

		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}