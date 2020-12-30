#include <iostream>
#include <queue>
#define MAX 987564321
using namespace std;

int dist[1000001];
int F, S, G, U, D;
int main() {
	cin >> F >> S >> G >> U >> D;
	for (int i = 0; i < 1000001; i++) dist[i] = MAX;

	queue<int> q;
	q.push(S);
	dist[S] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int up_next = now + U;
		if (up_next <= F && dist[up_next] > dist[now] + 1) {
			dist[up_next] = dist[now] + 1;
			q.push(up_next);
		}

		int low_next = now - D;
		if (low_next >= 1 && dist[low_next] > dist[now] + 1) {
			dist[low_next] = dist[now] + 1;
			q.push(low_next);
		}
	}
	if (dist[G] != MAX) cout << dist[G] << '\n';
	else cout << "use the stairs" << '\n';
}