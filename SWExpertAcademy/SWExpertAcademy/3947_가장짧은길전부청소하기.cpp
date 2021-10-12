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
	pq.push({ 0, src });//앞에가 코스트 뒤에가 정점 번호

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

	}//다익스트라를 이용해 최단 거리 구하기
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
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}