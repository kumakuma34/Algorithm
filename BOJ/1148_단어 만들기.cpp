#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> dict;//사전에 속한 단어 저장
int main() {
	string s;
	while (1) {
		cin >> s;
		if (s == "-") break;
		dict.push_back(s);
	}

	string now;
	while (1) {
		cin >> now;
		if (now == "#") break;
		sort(now.begin(), now.end());
		vector<int> able;//가능한 문자열
		//cout << now << endl;
		for (int i = 0; i < dict.size(); i++) {
			string s = dict[i];//현재 탐색 중인 문자
			sort(s.begin(), s.end());
			int bit = 0;

			bool flag = true;
			int x = 0;
			for (int j = 0; j < s.size(); j++) {
				while (1) {
					if (x >= 9) {
						flag = false;
						break;
					}
					if (now[x] == s[j]) {
						bit = bit | (1 << x);
						x++;
						break;
					}
					x++;
				}
				
			}
			//cout << bit << endl;
			if (flag) {
				//cout << dict[i] << endl;
				able.push_back(bit);
			}
			
		}
		/*for (int i = 0; i < able.size(); i++) {
			cout << bitset<9>(able[i]) << endl;
		}*/
		int max_ans = -1;
		int min_ans = 987654321;
		vector<char> max_v;
		vector<char> min_v;
		for (int i = 0; i < 9; i++) {//베열판에서 가운데 놓을 문자를 탐색
			if (i != 0 && now[i] == now[i - 1]) continue;
			int cnt = 0;
			for (int j = 0; j < able.size(); j++) {
				int bit = able[j];
				if (bit & (1 << i)) cnt++;
			}

			//cout << cnt << endl;

			if (max_ans < cnt) {
				max_ans = cnt;
				max_v.clear();
				max_v.push_back(now[i]);
			}
			else if (max_ans == cnt) {
				max_v.push_back(now[i]);
			}

			if (min_ans > cnt) {
				min_ans = cnt;
				min_v.clear();
				min_v.push_back(now[i]);
			}
			else if (min_ans == cnt) {
				min_v.push_back(now[i]);
			}
		}
		
		
		for (int i = 0; i < min_v.size(); i++) {
			cout << min_v[i];
		}
		cout << ' '<<min_ans<<' ';

		for (int i = 0; i < max_v.size(); i++) {
			cout << max_v[i];
		}
		cout << ' ' << max_ans << ' ';
		cout << '\n';


	}
	

	/*string s = "LARBITNLI";
	sort(s.begin(), s.end());
	cout << s << endl;

	string a = "APPLE";
	sort(a.begin(), a.end());
	cout << a << endl;*/
}