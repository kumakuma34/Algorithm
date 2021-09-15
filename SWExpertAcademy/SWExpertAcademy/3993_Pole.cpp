#include<iostream>

#define MAX 20
using namespace std;

long long dp[MAX + 1][MAX + 1][MAX + 1];

void solve() {
	dp[1][1][1] = 1;
	for (int i = 2; i <= MAX; i++) {
		for (int j = 1; j <= MAX; j++) {
			for (int k = 1; k <= MAX; k++) {
				dp[i][j][k] += dp[i - 1][j][k] * (i - 2);
				dp[i][j][k] += dp[i - 1][j - 1][k];
				dp[i][j][k] += dp[i - 1][j][k - 1];
			}
		}
	}

}
int main(int argc, char** argv)
{
	int test_case;
	int T, N, L, R;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	solve();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> L >> R;
		cout << "#" << test_case << " " << dp[N][L][R] << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}