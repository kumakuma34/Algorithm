#include<iostream>
#include <string>
#include <algorithm>

#define MAX 1000
using namespace std;

int dp[MAX + 1][MAX + 1];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input
		string A, B;
		cin >> A >> B;
		
		int n = A.length();
		int m = B.length();
		//dp�ʱ�ȭ
		dp[0][0] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (A[i-1] == B[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		cout << "#" << test_case << " " << dp[n][m] << endl;



	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}