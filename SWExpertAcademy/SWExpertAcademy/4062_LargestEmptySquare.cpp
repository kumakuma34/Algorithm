#include<iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 1000
int map[MAX + 2][MAX + 2], dp[MAX + 2][MAX + 2];

int main(int argc, char** argv)
{
	int test_case;
	int T, N;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input
		int ans = 0;
		cin >> N;
		string s;
		for (int i = 0; i < N; i++) {
			cin >> s;
			for (int j = 0; j < N; j++) {
				map[i][j] = s[j] - '0';
				if (map[i][j] == 0) map[i][j] = 1;
				else map[i][j] = 0;//코딩하기 편하게 toggle
				if (map[i][j] == 1) ans = 1;
				dp[i][j] = map[i][j];
			}
		}

		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (map[i][j] == 0) continue;
				dp[i][j] = min(dp[i - 1][j - 1],min( dp[i - 1][j], dp[i][j - 1])) + map[i][j];
				ans = max(ans, dp[i][j]);
			}
		}

		cout << "#" << test_case << " " << ans << endl;

		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}