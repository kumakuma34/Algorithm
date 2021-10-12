#include<iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX_NODE 200005
#define INF 18446744073709559ll
int N, M;
long long ans;
vector<pair<int, long long> > v[MAX_NODE];
bool visited[MAX_NODE];
vector<bool> check[MAX_NODE];

void init() {
	for (register int i = 0; i < N + 1; ++i) {
		v[i].clear();
		visited[i] = false;
		check[i].clear();
		//dist[i] = INF;
	}
	ans = 0;
}

long long findCost(int a, int b) {
	long long cost = -1;
	for (register int i = 0; i < v[a].size(); ++i) {
		int there = v[a][i].first;
		cost = v[a][i].second;
		if (there == b) break;
	}
	return cost;
}

bool findCheck(int a, int b) {
	if (b > a) swap(a, b);
	bool flag = false;
	for (register int i = 0; i < v[a].size(); ++i) {
		int there = v[a][i].first;
		flag = check[a][i];
		if (there == b) {
			check[a][i] = true;
			break;
		}
	}
	return flag;
}

void dijkstra(int src) {
	priority_queue<pair<long long, int> > pq;
	vector<long long> dist(N + 1, INF);
	vector<int> trace(N+1, -1);

	dist[src] = 0;
	trace[src] = src;
	pq.push({ 0, src });//�տ��� �ڽ�Ʈ �ڿ��� ���� ��ȣ

	while (!pq.empty())
	{
		int here = pq.top().second;
		pq.pop();

		if (visited[here]) continue;
		visited[here] = true;

		for (register int i = 0; i < v[here].size(); ++i)
		{
			int there = v[here][i].first;
			if (dist[there] >= dist[here] + v[here][i].second)
			{
				dist[there] = dist[here] + v[here][i].second;
				if (trace[there] == -1) {
					trace[there] = here;
				}
				else {
					long long costA = v[here][i].second;
					long long costB = findCost(trace[there], there);
					//cout << costA <<" , "<<costB<< endl;
					if (costA < costB) trace[there] = here;
				}
				pq.push(make_pair(dist[there] * -1, there));
			}
		}

	}//���ͽ�Ʈ�� �̿��� �ִ� �Ÿ� ���ϱ�
	for (register int v = 1; v <= N; ++v) {
		if (v == src) continue;
		register int prev;
		for (prev = v; prev != src; prev = trace[prev]) {
			int a = prev;
			int b = trace[prev];
			bool flag = findCheck(a, b);
			if (flag) break;
			else {
				ans += findCost(a, b);
				//cout << a<<" , "<<b<<" : "<<findCost(a, b) << endl;
				//findCheck(a, b, true);
				//findCheck(b, a);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		//cin >> N >> M;
		init();

		int from, to;
		long long cost;
		for (register int i = 0; i < M; i++) {
			//cin >> from >> to >> cost;
			scanf("%d %d %lld", &from, &to, &cost);
			v[from].push_back({ to, cost });
			v[to].push_back({ from, cost });
			check[from].push_back(false);
			check[to].push_back(false);
		}
		ans = 0;
		dijkstra(1);
		//printf("#%d %lld\n", test_case, ans);
		cout << "#" << test_case << " " << ans;
		cout << '\n';

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}