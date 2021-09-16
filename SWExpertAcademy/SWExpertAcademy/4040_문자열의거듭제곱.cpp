#include<iostream>
#include <string>

using namespace std;

#define MAX 1000000

int pi[MAX + 1];

void init() {
	for (int i = 0; i < MAX + 1; i++)
		pi[i] = 0;
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
		string s;
		cin >> s;

		int len = s.size();
		int j = 0;

		for (int i = 1; i < len; ++i) {
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j]) pi[i] = ++j;
		}
		
		cout << "#" << test_case << " ";
		int maxLength = pi[len - 1];//접두사, 접미가사 같은 최대 길이
		if (len % (len - maxLength)) cout << "1\n";
		else
			cout << len / (len - maxLength) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}