#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int K;
vector<string> v;

void init() {
	v.clear();
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
		cin >> K;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			v.push_back(s.substr(i, s.length()-i));
		}
		sort(v.begin(), v.end());

		/*for (int i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}*/
		cout << "#" << test_case << " " << v[K-1] << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}