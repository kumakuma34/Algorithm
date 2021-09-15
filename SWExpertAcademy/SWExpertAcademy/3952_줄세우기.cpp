#include<iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50000

vector<int> graph[MAX + 1];
int N, M;
int cnt[MAX + 1];
bool visit[MAX + 1];
void init() {
	for (int i = 0; i < MAX + 1; i++) {
		graph[i].clear();
		cnt[i] = 0;
		visit[i] = false;
	}
		
}
void solve() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			q.push(i);
			//visit[i] = true;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		cout << now << " ";
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int there = graph[now][i];
			//if (visit[there]) continue;
			cnt[there]--;
			if (cnt[there] == 0) {
				//visit[there] = true;
				q.push(there);
			}
		}
		
	}

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M;
		int a, b;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			cnt[b]++;
		}
		cout << "#" << test_case << " ";
		solve();
		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}