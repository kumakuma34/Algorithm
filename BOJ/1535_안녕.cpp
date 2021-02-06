#include <iostream>
#include <algorithm>
using namespace std;
int N;
int hp[21], joy[21];
int dp[101];
//dp[i][j] : i������� �λ��ϰ�, �� ü���� j�϶��� �ִ� ���

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> hp[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> joy[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 99; j >=hp[i]; j--) {
			dp[j] = max(dp[j], dp[j - hp[i]] + joy[i]);
		}
	}
	
	cout << dp[99] << endl;

}