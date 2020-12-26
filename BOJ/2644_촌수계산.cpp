#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, x, y;
int depth[101];
vector<int> graph[101];
bool visited[101];


void bfs(int n) {
	visited[n] = true;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!visited[next]) {
				visited[next] = true;
				depth[next] = depth[now] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> N >> x >> y >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(x);

	if (depth[y] != 0) cout << depth[y] << endl;
	else cout << "-1" << endl;
}