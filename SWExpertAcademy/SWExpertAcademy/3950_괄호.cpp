#include<iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string s;
int reverseCnt = 0;
vector<pair<int, int> > res;
vector<int> sumArr;

void init() {
	res.clear();
	sumArr.clear();
	reverseCnt = 0;
}
string process(int l, int r, string str) {
	int start = l;
	int end = r;
	while (l < r) {
		char tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++;
		r--;
	}
	for (int i = start; i <= end; i++) {
		if (str[i] == '(') str[i] = ')';
		else if (str[i] == ')') str[i] = '(';
	}
	return str;
}
string reverseString(string str, int len) {
	int minVal = 0;
	int idx = -1;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') sum++;
		else if (str[i] == ')') sum--;

		if (sum < minVal) {
			minVal = sum;
			idx = i;
		}
	}

	if (idx != -1) {
		reverseCnt++;
		res.push_back({ 0,idx });
		str = process(0, idx, str);
	}

	return str;
}

void solve() {
	if (N % 2 == 1) {
		reverseCnt = -1;
		return;
	}

	s = reverseString(s, N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == '(') sum++;
		else if (s[i] == ')') sum--;
		sumArr.push_back(sum);
	}

	if (sumArr.back() == 0) return;

	int midVal = sumArr.back() / 2;
	int idx = -1;
	for (int i = 0; i < N; i++) {
		if (midVal == sumArr[i]) {
			idx = i + 1;
		}
	}
	res.push_back({ idx, N - 1 });
	reverseCnt++;

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> s;
		solve();

		cout << "#" << test_case << " " << reverseCnt << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].first << " " << res[i].second << endl;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}