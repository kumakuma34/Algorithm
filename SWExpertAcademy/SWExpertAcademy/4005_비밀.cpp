#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 10
#define INIT -1
vector<int> graph[MAX + 1];
int T, N, K, ans;
bool visit[MAX + 1];

void init() {
	for (int i = 0; i < MAX + 1; i++)
		graph[i].clear();
	ans = 0;
}

void getMaxDist(int src, int cost, bool* visited) {
	visited[src] = true;
	for (int i = 0; i < graph[src].size(); i++) {
		int next = graph[src][i];
		if (!visited[next]) {
			getMaxDist(next, cost + 1, visited);
		}
	}

	visited[src] = false;
	ans = max(ans, cost);
}
int main(int argc, char** argv)
{
	int test_case;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> K;
		for (int i = 0; i < K; i++) {
			int cnt, from, to;
			cin >> cnt >> from;
			cnt--;
			while (cnt--) {
				cin >> to;
				graph[from].push_back(to);
				from = to;
			}
		}

		for (int i = 0; i <= N; i++)
			visit[i] = false;
		cout << "#" << test_case << " ";
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				sort(graph[i].begin(), graph[i].end());
				graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
				//cout << graph[i][j] << " ";
			}
			cout << graph[i].size() << " ";
			getMaxDist(i, 1, visit);
		}
		cout << ans << " " << endl;
	}

	

	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}