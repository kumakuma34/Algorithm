#include <iostream>
#include <vector>
using namespace std;

int C, N;
int dp[100001];
vector<pair<int, int> > v;//����� ������ �迭
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
			int a = v[i].first;//���
			int b = v[i].second;//���� �� �ִ� �� ��
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