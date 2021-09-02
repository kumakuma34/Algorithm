#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

vector<int> tree[10001];
int above[10001];
bool visited[10001];
int par[10001], depth[10001];

void init() {
	for (int i = 0; i < 10001; i++) {
		above[i] = 0;
		tree[i].clear();
		visited[i] = false;
	}
}
void dfs(int n) {//n: 탐색중인 노드, root 부터 탐색 시작
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

int LCM(int A, int B) {
	if (depth[A] < depth[B]) swap(A, B);
	while (depth[A] != depth[B]) A = par[A];//depth가 같아질때까지 부모 노드로 업데이트
	while (A != B) {
		A = par[A];
		B = par[B];
	}
	return A;
}

int getSize(int lcm) {
	int cnt = 0;
	bool used[10001];
	for (int i = 0; i < 10001; i++) used[i] = false;


	queue<int> q;
	q.push(lcm);
	used[lcm] = true;

	while (!q.empty()) {
		int now = q.front();
		cnt++;
		q.pop();
		for (int i = 0; i < tree[now].size(); i++) {
			if (used[tree[now][i]]) continue;
			q.push(tree[now][i]);
			used[tree[now][i]] = true;
		}
	}

	return cnt;
}
int main(int argc, char** argv)
{
	int test_case;
	int T, V, E, A, B, root;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();

		//input
		cin >> V >> E >> A >> B;
		int x, y;
		for (int i = 0; i < E; i++) {
			cin >> x >> y;
			tree[x].push_back(y);
			above[y]++;
		}
		for (int i = 1; i <= V; i++) {
			if (above[i] == 0) {
				root = i;
				break;
			}
		}
		dfs(root);

		//깊이 탐색하면서 조상 노드 찾기
		int lcm = LCM(A, B);
		cout << "#"<<test_case<<" "<< lcm << " " << getSize(lcm) << endl;
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}