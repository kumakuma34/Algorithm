/*
BOJ 1874[스택 수열]
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> v;
int main() {
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	int nx = 1;//stack push value
	int idx = 0; // vector idx
	stack<int> s;
	vector<char> ans;
	bool flag = true;//if false, impossible
	while (nx <= n) {
		if (!s.empty() && s.top() == v[idx]) {
			s.pop();
			idx++;
			ans.push_back('-');
		}
		else {
			s.push(nx);
			nx++;
			ans.push_back('+');
		}
	}
	while (!s.empty()) {
		if (s.top() == v[idx]) {
			s.pop();
			idx++;
			ans.push_back('-');
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}
	else
		cout << "NO\n";


}