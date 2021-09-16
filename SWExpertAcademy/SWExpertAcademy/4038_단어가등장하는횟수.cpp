#include<iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 500000

int N, M;
int fail[MAX + 1];

void init() {
	for (int i = 0; i < MAX + 1; i++)
		fail[i] = 0;
}
void preprocessing(string s) {
	for (int i = 1, j = 0; i < M; i++) {
		while (j > 0 && s[i] != s[j]) j = fail[j - 1];
		if (s[i] == s[j]) fail[i] = ++j;
	}
}

int kmp(string s, string p) {
	vector<int> ans;
	int j = 0;

	for (int i = 0; i < N; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = fail[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == M - 1) {
				ans.push_back(i - M + 1);
				j = fail[j];
			}
			else
				j++;
		}
	}
	return ans.size();
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		string s, pattern;
		cin >> s >> pattern;
		N = s.length();
		M = pattern.length();
		preprocessing(pattern);

		cout << "#" << test_case << " " << kmp(s, pattern) << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}