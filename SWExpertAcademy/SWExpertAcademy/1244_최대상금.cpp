#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define INF 987654321
int dist[1000000];

void init() {
	for (int i = 0; i < 1000000; i++)
		dist[i] = INF;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		int ans = 0;
		queue<string> q; 
		string s;
		int n;
		cin >> s >> n;
		q.push(s);
		dist[stoi(s)] = 0;

		while (!q.empty()) {
			string now = q.front();
			int cost = dist[stoi(now)];
			q.pop();
			if (dist[stoi(now)] >= n) continue;
			for (int i = 0; i < now.length(); i++) {
				for (int j = 0; j < now.length(); j++) {
					string next = now;
					next[j] = now[i];
					next[i] = now[j];
					if (next == now) {
						dist[stoi(now)]++;
						continue;
					}
					if (dist[stoi(next)] > cost + 1){
						dist[stoi(next)] = cost + 1;
						//cout << now << " , " << cost << " -> " << next << cost + 1 << endl;
						q.push(next);
					}
				}
			}
		}
		for (int i = 0; i < 1000000; i++) {
			if (dist[i] == INF) continue; // 도달할 수 없는 값
			//cout << i << " , " << dist[i] << endl;
			if ((n - dist[i]) % 2 == 0 && dist[i] != 0 &&  dist[i] <= n) {
				if (ans < i) ans = i;
			}
		}
		cout << "#" << test_case <<" " << ans << endl;
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}