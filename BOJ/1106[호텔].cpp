#include <iostream>
#include <vector>
using namespace std;

int C, N;
int dp[100001];
vector<pair<int, int> > v;//비용을 저장할 배열
int main() {
	cin >> C >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	int idx = 1;
	while (1) {
		for (int i = 0; i < N; i++) {
			int a = v[i].first;//비용
			int b = v[i].second;//얻을 수 있는 고객 수
			if (idx - a >= 0) {
				if (dp[idx] < dp[idx - a] + b) {
					dp[idx] = dp[idx - a] + b;
				}
			}
		}
		if (dp[idx] >= C) {
			cout << idx << endl;
			break;
		}
		idx++;
	}
}