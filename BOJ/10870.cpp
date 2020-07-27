#include <iostream>

using namespace std;

int n;
int dp[21];//피보나치 수열을 저장할 dp
int main() {
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;//initialization

	for (int i = 2; i <= 20; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}//피보나치 수열 계산

	cout << dp[n] << "\n";
	
}