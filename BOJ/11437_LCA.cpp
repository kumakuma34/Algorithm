#include <iostream>
#include <vector>
using namespace std;

int N, M;
int par[50001];//�θ� ��带 ����
int depth[50001];
vector<int> tree[50001];
bool visited[50001];

void dfs(int n) {//DFS�� ���� �θ���, depth�� Ž��
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
		if (depth[a] < depth[b]) swap(a, b);//���ǻ� �� ���̰� ���� ���� a�� ����
		while (depth[a] != depth[b]) a = par[a];//depth�� �������� ���� �θ���� ������Ʈ
		while (a != b) {//���� �θ� ã��
			a = par[a];
			b = par[b];
		}
		cout << a << '\n';
	}
}