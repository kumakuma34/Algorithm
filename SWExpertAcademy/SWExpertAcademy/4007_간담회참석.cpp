#include<iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 50000
#define INF 987654231
int N, M, X;
vector <pair<int, int> > graph[MAX + 1];
vector <pair<int, int> > graph_reverse[MAX + 1];

void init() {
	for (register unsigned int i = 0; i < MAX + 1; i++) {
		graph[i].clear();
		graph_reverse[i].clear();
	}
}

//우선순위 큐를 이용한 다익스트라
vector<int> dijkstra(int src, vector<pair<int, int> >v[]) {
	vector<int> dist(N + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (register unsigned int i = 0; i < v[here].size(); ++i) {
			int there = v[here][i].first;
			int nextCost = cost + v[here][i].second;
			if (dist[there] > nextCost) {
				dist[there] = nextCost;
				pq.push({ -1 * nextCost, there });
			}
		}
	}

	return dist;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M >> X;
		int from, to, cost;
		for (register unsigned int i = 0; i < M; i++) {
			cin >> from >> to >> cost;
			graph[from].push_back({ to,cost });
			graph_reverse[to].push_back({ from,cost });//간선을 반대방향으로 배열에 저장
		}

		vector<int> dist1 = dijkstra(X, graph);//i->목적지
		vector<int> dist2 = dijkstra(X, graph_reverse);//목적지 ->i 
		int dist = -1;
		for (register unsigned int i = 1; i <= N; i++) {
			//cout << dist1[i] << " " << dist2[i] << endl;
			if (dist1[i] == INF || dist2[i] == INF) continue;
			if (dist < dist1[i] + dist2[i])
				dist = dist1[i] + dist2[i];
		}

		cout << "#" << test_case << " " << dist << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}