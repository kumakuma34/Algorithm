#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 250
using namespace std;

string dp[MAX + 1];

string addBigInt(string a, string b) {
	if (a.length() < b.length()) {
		string tmp = a;
		a = b;
		b = tmp;
	}
	int minLen = min(a.length(), b.length());

	string ans = "";
	bool upFlag = false;
	for (int i = 0; i < minLen; i++) {
		int x = a[a.length() - i - 1] - '0';
		int y = b[b.length() - i - 1] - '0';
		if (upFlag) {
			x++;
			upFlag = false;
		}
		if (x + y <= 9)
			ans += to_string(x + y);
		else {
			upFlag = true;
			ans += to_string(x + y - 10);
		}
	}
	if (a.length() == b.length()){
		if (upFlag) {
			ans += "1";
			upFlag = false;
		}
	}
	else {
		for (int i = minLen; i < a.length(); i++) {
			if (upFlag) {
				int x = a[a.length() - i - 1] - '0';
				x++;
				ans += to_string(x);
				upFlag = false;
			}
			else
				ans += a[a.length() - i - 1];
		}
	}
	
	string tmp = ans;
	ans = "";
	for (int i = tmp.length() - 1; i>=0; i--) {
		ans += tmp[i];
	}
	return ans;
}
int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	//cout << addBigInt("6", "5");
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
	
		dp[1] = "1";
		dp[2] = "3";
		for (int i = 3; i <= N; i++) {
			dp[i] = addBigInt(addBigInt(dp[i - 2] , dp[i - 2])  ,dp[i - 1]);
		}
		cout << "#"<<test_case<<" "<<dp[N] << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}