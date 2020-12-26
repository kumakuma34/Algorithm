#include <iostream>
#include <vector>
using namespace std;

int N, M;
int par[50001];//부모 노드를 저장
int depth[50001];
vector<int> tree[50001];
bool visited[50001];

void dfs(int n) {//DFS를 통해 부모노드, depth를 탐색
	visited[n] = true;

	for (int i = 0; i < tree[n].size(); i++) {
		int now = tree[n][i];
		if (!visited[now]) {
			par[now] = n;
			depth[now] = depth[n] + 1;
			dfs(now);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[y].push_back(x);
		tree[x].push_back(y);
	}
	dfs(1);

	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		if (depth[a] < depth[b]) swap(a, b);//편의상 더 깊이가 깊은 쪽을 a로 설정
		while (depth[a] != depth[b]) a = par[a];//depth가 같아질때 까지 부모노드로 업데이트
		while (a != b) {//공통 부모 찾기
			a = par[a];
			b = par[b];
		}
		cout << a << '\n';
	}
}