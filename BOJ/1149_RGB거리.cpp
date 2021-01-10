#include <iostream>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;
int N;
int dp[1001][3];
int cost[1001][3];//���
//dp[N][0] : N��° ���� �������� ĥ���� �� �ּڰ�
//dp[N][1] : N��° ���� �ʷ����� ĥ���� �� �ּڰ�
//dp[N][2] : N��° ���� �Ķ����� ĥ���� �� �ּڰ�
int ans = INF;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = INF;
		}
	}
	
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				dp[i][j] = min(dp[i - 1][k]+cost[i][j], dp[i][j]);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		ans = min(ans, dp[N - 1][i]);
	}
	cout << ans << endl;
}