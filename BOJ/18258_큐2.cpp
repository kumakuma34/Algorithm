#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> dq;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int value;
			cin >> value;
			dq.push_back(value);
		}
		else if (cmd == "pop") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "front") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << '\n';
		}
		else if (cmd == "back") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << '\n';
		}
	}
}