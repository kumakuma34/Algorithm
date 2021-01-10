#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int T, N;

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		vector<string> v;
		
		string s;
		for (int i = 0; i < N; i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		bool flag = true;
		for (int i = 0; i < v.size() - 1; i++) {
			int bef = v[i].length();
			int next = v[i + 1].length();

			if (bef < next) {
				if (v[i + 1].find(v[i]) == 0) {
					flag = false;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}