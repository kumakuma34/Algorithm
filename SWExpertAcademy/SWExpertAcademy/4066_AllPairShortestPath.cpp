#include<iostream>
#include <vector>
#include <queue>

#define MAX 500
#define INF 987654321
using namespace std;

vector<pair<int, int> > graph[MAX+1];
int V, E;

vector<int> dijkstra(int src) {
	vector<int> dist(V+1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < graph[here].size(); ++i) {
			int there = graph[here][i].first;
			int nextCost = cost + graph[here][i].second;

			if (dist[there] > nextCost) {
				dist[there] = nextCost;
				pq.push({ -1 * nextCost , there });
			}
		}
	}

	return dist;
}

void init() {
	for (int i = 0; i < MAX + 1; i++) {
		graph[i].clear();
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
		cin >> V >> E;
		int from, there, cost;
		for (int i = 0; i < E; i++) {
			cin >> from >> there >> cost;
			graph[from].push_back({ there, cost });
		}

		cout << "#" << test_case << " ";
		for (int i = 1; i <= V; i++) {
			vector<int> dist = dijkstra(i);
			for (int i = 1; i <= V; i++) {
				if (dist[i] == INF)
					cout << "-1 ";
				else
					cout << dist[i] << " ";
			}
		}

		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}