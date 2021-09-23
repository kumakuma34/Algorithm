#include<iostream>
#include <vector>
#include <list>

using namespace std;
int N, M;
list<int> l;

void init() {
	l.clear();
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		int tmp;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			l.push_back(tmp);
		}
		
		cin >> M;
		char cmd;
		int x, y, s;
		while (M--) {
			cin >> cmd;
			if (cmd == 'I') {
				cin >> x >> y;
				list<int> tmp;
				while (y--) {
					cin >> s;
					tmp.push_back(s);
				}
				auto iter = l.begin();
				for (int i = 0; i < x; i++) iter++;
				l.splice(iter, tmp);
			}
			else if (cmd == 'D') {
				cin >> x >> y;
				auto iter = l.begin();
				for (int i = 0; i < x; i++)
					iter++;
				for (int j = 0; j < y; j++) {
					iter = l.erase(iter);
				}
			}
			else if (cmd == 'A') {
				cin >> y;
				while (y--) {
					cin >> s;
					l.push_back(s);
				}
			}
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; i++) {
			cout << l.front() << " ";
			l.pop_front();
		}
		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}