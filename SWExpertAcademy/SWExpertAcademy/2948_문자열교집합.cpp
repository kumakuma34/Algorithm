#include<iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, int> m;
int N, M;
void init() {
	m.clear();
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
		cin >> N >> M;
		string s;
		int ans = 0;
		while (N--) {
			cin >> s;
			m.insert({ s,-1 });
		}
		while (M--) {
			cin >> s;
			auto iter = m.find(s);
			if (iter != m.end()) ans++;
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}