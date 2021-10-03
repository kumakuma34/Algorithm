#include<iostream>

using namespace std;
#define MAX 200001
int N;
int dp[MAX];

void init() {
	for (int i = 0; i < MAX; i++)
		dp[i] = 0;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		cin >> dp[0];
		int ans = dp[0];
		for (int i = 1; i < N; i++) {
			cin >> dp[i];
			if (dp[i - 1] + dp[i] >= dp[i]) {
				dp[i] = dp[i - 1] + dp[i];

			}
			if (dp[i] > ans) ans = dp[i];

		}
		cout << "#"<<test_case<<" "<<ans << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}